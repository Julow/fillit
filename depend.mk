INCLUDE_FLAGS += -I$(O_DIR)/_public
MAINS += fillit
OBJ_DIR_TREE += $(O_DIR)/srcs/tetri_map/ $(O_DIR)/srcs/main/ $(O_DIR)/srcs/ \
	$(O_DIR)/libft/ft_base/ $(O_DIR)/libft/ $(O_DIR)/_public/ft/ \
	$(O_DIR)/_public/ $(O_DIR)/
O_FILES += $(O_DIR)/srcs/main/main.o $(O_DIR)/libft/ft_base/ft_abs.o \
	$(O_DIR)/libft/ft_base/ft_assert.o $(O_DIR)/libft/ft_base/ft_atoib.o \
	$(O_DIR)/libft/ft_base/ft_bitset.o $(O_DIR)/libft/ft_base/ft_bzero.o \
	$(O_DIR)/libft/ft_base/ft_clock.o $(O_DIR)/libft/ft_base/ft_emalloc.o \
	$(O_DIR)/libft/ft_base/ft_escape.o $(O_DIR)/libft/ft_base/ft_getenv.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_base/ft_max.o \
	$(O_DIR)/libft/ft_base/ft_memcmp.o $(O_DIR)/libft/ft_base/ft_memcpy.o \
	$(O_DIR)/libft/ft_base/ft_memdup.o $(O_DIR)/libft/ft_base/ft_memfill.o \
	$(O_DIR)/libft/ft_base/ft_memmove.o $(O_DIR)/libft/ft_base/ft_memrcpy.o \
	$(O_DIR)/libft/ft_base/ft_memset.o $(O_DIR)/libft/ft_base/ft_memstart.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o $(O_DIR)/libft/ft_base/ft_min.o \
	$(O_DIR)/libft/ft_base/ft_rand.o $(O_DIR)/libft/ft_base/ft_sort.o \
	$(O_DIR)/libft/ft_base/ft_strchri.o $(O_DIR)/libft/ft_base/ft_strlen.o \
	$(O_DIR)/libft/ft_base/ft_sub.o $(O_DIR)/libft/ft_base/ft_subfind.o \
	$(O_DIR)/libft/ft_base/ft_subnext.o $(O_DIR)/libft/ft_base/ft_subto.o \
	$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o $(O_DIR)/srcs/tetri_map/access.o \
	$(O_DIR)/srcs/tetri_map/block_masks.o $(O_DIR)/srcs/tetri_map/create.o \
	$(O_DIR)/srcs/tetri_map/update.o
PUBLIC_LINKS += $(O_DIR)/_public/ft/ft_colors.h $(O_DIR)/_public/ft/ft_wchar.h \
	$(O_DIR)/_public/ft/libft.h $(O_DIR)/_public/tetri_map.h \
	$(O_DIR)/_public/tetriminos.h

# module fillit
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/libft.h \
	srcs/tetri_map/public/tetri_map.h srcs/tetriminos/tetriminos.h

# module ft::base
$(O_DIR)/libft/ft_base/ft_abs.o: libft/ft_base/ft_abs.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_assert.o: libft/ft_base/ft_assert.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_atoib.o: libft/ft_base/ft_atoib.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bitset.o: libft/ft_base/ft_bitset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bzero.o: libft/ft_base/ft_bzero.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock.o: libft/ft_base/ft_clock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_emalloc.o: libft/ft_base/ft_emalloc.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_getenv.o: libft/ft_base/ft_getenv.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_is.o: libft/ft_base/ft_is.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_max.o: libft/ft_base/ft_max.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcmp.o: libft/ft_base/ft_memcmp.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcpy.o: libft/ft_base/ft_memcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memdup.o: libft/ft_base/ft_memdup.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memfill.o: libft/ft_base/ft_memfill.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memmove.o: libft/ft_base/ft_memmove.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memrcpy.o: libft/ft_base/ft_memrcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memset.o: libft/ft_base/ft_memset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memstart.o: libft/ft_base/ft_memstart.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memswap.o: libft/ft_base/ft_memswap.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_min.o: libft/ft_base/ft_min.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_rand.o: libft/ft_base/ft_rand.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_sort.o: libft/ft_base/ft_sort.c \
	libft/ft_base/p_sort.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strchri.o: libft/ft_base/ft_strchri.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strlen.o: libft/ft_base/ft_strlen.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_sub.o: libft/ft_base/ft_sub.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subfind.o: libft/ft_base/ft_subfind.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subnext.o: libft/ft_base/ft_subnext.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subto.o: libft/ft_base/ft_subto.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_unescape.o: libft/ft_base/ft_unescape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_widetoa.o: libft/ft_base/ft_widetoa.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrconv.o: libft/ft_base/ft_wstrconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrlen.o: libft/ft_base/ft_wstrlen.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrnconv.o: libft/ft_base/ft_wstrnconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h

$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_base/ft_assert.o \
$(O_DIR)/libft/ft_base/ft_atoib.o $(O_DIR)/libft/ft_base/ft_bitset.o \
$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/libft/ft_base/ft_clock.o \
$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_escape.o \
$(O_DIR)/libft/ft_base/ft_getenv.o $(O_DIR)/libft/ft_base/ft_is.o \
$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_base/ft_memdup.o \
$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_base/ft_memmove.o \
$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/libft/ft_base/ft_memset.o \
$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_base/ft_memswap.o \
$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_rand.o \
$(O_DIR)/libft/ft_base/ft_sort.o $(O_DIR)/libft/ft_base/ft_strchri.o \
$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_sub.o \
$(O_DIR)/libft/ft_base/ft_subfind.o $(O_DIR)/libft/ft_base/ft_subnext.o \
$(O_DIR)/libft/ft_base/ft_subto.o $(O_DIR)/libft/ft_base/ft_unescape.o \
$(O_DIR)/libft/ft_base/ft_widetoa.o $(O_DIR)/libft/ft_base/ft_wstrconv.o \
$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/libft/ft_base/ft_wstrnconv.o: \
	INCLUDE_FLAGS += -Ilibft/ft_base

# module tetri_map
$(O_DIR)/srcs/tetri_map/access.o: srcs/tetri_map/access.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h
$(O_DIR)/srcs/tetri_map/block_masks.o: srcs/tetri_map/block_masks.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h
$(O_DIR)/srcs/tetri_map/create.o: srcs/tetri_map/create.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h
$(O_DIR)/srcs/tetri_map/update.o: srcs/tetri_map/update.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h

$(O_DIR)/srcs/tetri_map/access.o $(O_DIR)/srcs/tetri_map/block_masks.o \
$(O_DIR)/srcs/tetri_map/create.o $(O_DIR)/srcs/tetri_map/update.o: \
	INCLUDE_FLAGS += -Isrcs/tetri_map

# module tetriminos

fillit: $(O_FILES)

# public links
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/tetri_map.h: srcs/tetri_map/public/tetri_map.h
$(O_DIR)/_public/tetriminos.h: srcs/tetriminos/tetriminos.h
