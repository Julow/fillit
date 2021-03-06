
#

# Git submodule to init
SUBMODULES		:= 

# Base flags
BASE_FLAGS		= -Wall -Wextra
INCLUDE_FLAGS	=

# Compilation flags (per language)
C_FLAGS			= $(INCLUDE_FLAGS) $(BASE_FLAGS)
CPP_FLAGS		= $(INCLUDE_FLAGS) $(BASE_FLAGS) -std=c++14

LINK_FLAGS		= $(BASE_FLAGS)

DEBUG_MODE		?= 0
ifeq ($(DEBUG_MODE),1)
	# Extra flags used in debug mode
	BASE_FLAGS	+= -g
else
	# Extra flags used when not in debug mode
	BASE_FLAGS	+= 
endif
export DEBUG_MODE

# Compilers
CC				= clang
CXX				= clang++
LINKER			= $(CC)

# Objects directory
O_DIR			:= _objs

# Jobs
JOBS			:= 4

# Depend file name
DEPEND			:= depend.mk

# tmp
SUBMODULE_RULES	:= $(addsuffix /.git,$(SUBMODULES))
PRINT_OK		= printf '\033[32m$<\033[0m\n'
PRINT_LINK		= printf '\033[32m$@\033[0m\n'

# Default rule (need to be before any include)
all: init
	make -j$(JOBS) $(MAINS)

# Include $(O_FILES) and dependencies
include $(DEPEND)

# make -n
n: init
	make -n $(MAINS)

init: | $(SUBMODULE_RULES) $(LIBS_RULES) $(OBJ_DIR_TREE) $(PUBLIC_LINKS)

# Linking
$(MAINS): | init
	$(LINKER) -o $@ $^ $(LINK_FLAGS) && $(PRINT_LINK)

# Compiling
$(O_DIR)/%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@ && $(PRINT_OK)
$(O_DIR)/%.o: %.cpp
	$(CXX) $(CPP_FLAGS) -c $< -o $@ && $(PRINT_OK)
	$(eval LINKER = $(CXX))

# Init submodules
$(SUBMODULE_RULES):
	git submodule init $(@:.git=)
	git submodule update $(@:.git=)

# Create include links
$(PUBLIC_LINKS):
	ln -fs $(abspath $<) $@
# Create obj directories
$(OBJ_DIR_TREE):
	mkdir -p $@

# Set debug mode and make
debug: _debug all

# Clean, set debug mode and make
rebug: fclean debug

# Clean obj files
clean:
	-rm -f $(O_FILES) $(PUBLIC_LINKS) 2> /dev/null
	-rm -df $(OBJ_DIR_TREE) 2> /dev/null

# Clean everything
fclean: clean
	rm -f $(MAINS)

# Clean and make
re: fclean all

# Set debug flags
_debug:
	$(eval DEBUG_MODE = 1)

.SILENT:
.PHONY: all n clean fclean re debug rebug _debug init
