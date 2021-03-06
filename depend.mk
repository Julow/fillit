INCLUDE_FLAGS += -I$(O_DIR)/_public
MAINS += fillit
OBJ_DIR_TREE += $(O_DIR)/srcs/tetri_solver/ $(O_DIR)/srcs/tetri_parser/ \
	$(O_DIR)/srcs/tetri_map/ $(O_DIR)/srcs/main/ $(O_DIR)/srcs/ \
	$(O_DIR)/libft/ft_vector/ $(O_DIR)/libft/ft_set/ \
	$(O_DIR)/libft/ft_printf/formats/ $(O_DIR)/libft/ft_printf/ \
	$(O_DIR)/libft/ft_out/ $(O_DIR)/libft/ft_in/ $(O_DIR)/libft/ft_file_in/ \
	$(O_DIR)/libft/ft_file/ $(O_DIR)/libft/ft_dstr/ $(O_DIR)/libft/ft_base/ \
	$(O_DIR)/libft/ $(O_DIR)/_public/ft/ $(O_DIR)/_public/ $(O_DIR)/
O_FILES += $(O_DIR)/srcs/main/main.o $(O_DIR)/libft/ft_base/ft_abs.o \
	$(O_DIR)/libft/ft_base/ft_assert.o $(O_DIR)/libft/ft_base/ft_atoib.o \
	$(O_DIR)/libft/ft_base/ft_bitset.o $(O_DIR)/libft/ft_base/ft_bzero.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_base/ft_max.o \
	$(O_DIR)/libft/ft_base/ft_memcmp.o $(O_DIR)/libft/ft_base/ft_memcpy.o \
	$(O_DIR)/libft/ft_base/ft_memdup.o $(O_DIR)/libft/ft_base/ft_memfill.o \
	$(O_DIR)/libft/ft_base/ft_memmove.o $(O_DIR)/libft/ft_base/ft_memrcpy.o \
	$(O_DIR)/libft/ft_base/ft_memset.o $(O_DIR)/libft/ft_base/ft_memstart.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o $(O_DIR)/libft/ft_base/ft_min.o \
	$(O_DIR)/libft/ft_base/ft_sort.o $(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_base/ft_subfind.o $(O_DIR)/libft/ft_base/ft_subnext.o \
	$(O_DIR)/libft/ft_base/ft_subto.o $(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_base/ft_widetoa.o $(O_DIR)/libft/ft_base/ft_wstrconv.o \
	$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/libft/ft_dstr/ft_dstradd.o $(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_file/open.o \
	$(O_DIR)/libft/ft_file_in/file_in.o \
	$(O_DIR)/libft/ft_file_in/file_in_open.o \
	$(O_DIR)/libft/ft_in/ft_in_refresh.o $(O_DIR)/libft/ft_in/ft_read.o \
	$(O_DIR)/libft/ft_in/ft_readto.o $(O_DIR)/libft/ft_out/ft_putchar.o \
	$(O_DIR)/libft/ft_out/ft_putendl.o $(O_DIR)/libft/ft_out/ft_putfloat.o \
	$(O_DIR)/libft/ft_out/ft_putint.o $(O_DIR)/libft/ft_out/ft_putnchar.o \
	$(O_DIR)/libft/ft_out/ft_putpad.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/libft/ft_out/ft_putsub.o $(O_DIR)/libft/ft_out/ft_putuint.o \
	$(O_DIR)/libft/ft_out/ft_str_out.o $(O_DIR)/libft/ft_out/ft_write.o \
	$(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_printf/args_utils.o \
	$(O_DIR)/libft/ft_printf/exec_format.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_printf/formats/int.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o \
	$(O_DIR)/libft/ft_printf/formats/str.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_printf/ft_logf.o \
	$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
	$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o \
	$(O_DIR)/libft/ft_set/first.o $(O_DIR)/libft/ft_set/get.o \
	$(O_DIR)/libft/ft_set/insert.o $(O_DIR)/libft/ft_set/iter.o \
	$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_set/utils.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o $(O_DIR)/libft/ft_vector/ft_vpush.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/libft/ft_vector/ft_vspan.o \
	$(O_DIR)/srcs/tetri_map/access.o $(O_DIR)/srcs/tetri_map/create.o \
	$(O_DIR)/srcs/tetri_map/update.o $(O_DIR)/srcs/tetri_parser/check.o \
	$(O_DIR)/srcs/tetri_parser/parser.o $(O_DIR)/srcs/tetri_solver/backtrack.o \
	$(O_DIR)/srcs/tetri_solver/build_pool.o $(O_DIR)/srcs/tetri_solver/solve.o
PUBLIC_LINKS += $(O_DIR)/_public/ft/file.h $(O_DIR)/_public/ft/file_in.h \
	$(O_DIR)/_public/ft/ft_colors.h $(O_DIR)/_public/ft/ft_dstr.h \
	$(O_DIR)/_public/ft/ft_in.h $(O_DIR)/_public/ft/ft_out.h \
	$(O_DIR)/_public/ft/ft_printf.h $(O_DIR)/_public/ft/ft_str_out.h \
	$(O_DIR)/_public/ft/ft_vector.h $(O_DIR)/_public/ft/ft_vprintf.h \
	$(O_DIR)/_public/ft/ft_wchar.h $(O_DIR)/_public/ft/libft.h \
	$(O_DIR)/_public/ft/set.h $(O_DIR)/_public/tetri_map.h \
	$(O_DIR)/_public/tetri_parser.h $(O_DIR)/_public/tetri_solver.h

# module fillit
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_file_in/public/file_in.h \
	libft/ft_in/public/ft_in.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_vector/public/ft_vector.h \
	srcs/tetri_map/public/tetri_map.h srcs/tetri_parser/public/tetri_parser.h \
	srcs/tetri_solver/public/tetri_solver.h

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
$(O_DIR)/libft/ft_base/ft_emalloc.o: libft/ft_base/ft_emalloc.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
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
$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/libft/ft_base/ft_emalloc.o \
$(O_DIR)/libft/ft_base/ft_escape.o $(O_DIR)/libft/ft_base/ft_is.o \
$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_base/ft_memdup.o \
$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_base/ft_memmove.o \
$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/libft/ft_base/ft_memset.o \
$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_base/ft_memswap.o \
$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_sort.o \
$(O_DIR)/libft/ft_base/ft_strchri.o $(O_DIR)/libft/ft_base/ft_strlen.o \
$(O_DIR)/libft/ft_base/ft_sub.o $(O_DIR)/libft/ft_base/ft_subfind.o \
$(O_DIR)/libft/ft_base/ft_subnext.o $(O_DIR)/libft/ft_base/ft_subto.o \
$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
$(O_DIR)/libft/ft_base/ft_wstrnconv.o: INCLUDE_FLAGS += -Ilibft/ft_base

# module ft::dstr
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: libft/ft_dstr/ft_dstradd.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: libft/ft_dstr/ft_dstrclear.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: libft/ft_dstr/ft_dstrextend.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: libft/ft_dstr/ft_dstrspan.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h

# module ft::file
$(O_DIR)/libft/ft_file/open.o: libft/ft_file/open.c \
	libft/ft_base/public/libft.h libft/ft_file/public/file.h

# module ft::file_in
$(O_DIR)/libft/ft_file_in/file_in.o: libft/ft_file_in/file_in.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file_in/public/file_in.h libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_file_in/file_in_open.o: libft/ft_file_in/file_in_open.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file/public/file.h libft/ft_file_in/public/file_in.h \
	libft/ft_in/public/ft_in.h

# module ft::in
$(O_DIR)/libft/ft_in/ft_in_refresh.o: libft/ft_in/ft_in_refresh.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_read.o: libft/ft_in/ft_read.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_readto.o: libft/ft_in/ft_readto.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h

# module ft::out
$(O_DIR)/libft/ft_out/ft_putchar.o: libft/ft_out/ft_putchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putendl.o: libft/ft_out/ft_putendl.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putfloat.o: libft/ft_out/ft_putfloat.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putint.o: libft/ft_out/ft_putint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putnchar.o: libft/ft_out/ft_putnchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putpad.o: libft/ft_out/ft_putpad.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putstr.o: libft/ft_out/ft_putstr.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putsub.o: libft/ft_out/ft_putsub.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putuint.o: libft/ft_out/ft_putuint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_str_out.o: libft/ft_out/ft_str_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h
$(O_DIR)/libft/ft_out/ft_write.o: libft/ft_out/ft_write.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_char.o: libft/ft_out/ft_write_char.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_nchar.o: libft/ft_out/ft_write_nchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/out_formats.o: libft/ft_out/out_formats.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h

$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_out/ft_putendl.o \
$(O_DIR)/libft/ft_out/ft_putfloat.o $(O_DIR)/libft/ft_out/ft_putint.o \
$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_putpad.o \
$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_putsub.o \
$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_str_out.o \
$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_write_char.o \
$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o: \
	INCLUDE_FLAGS += -Ilibft/ft_out

# module ft::printf
$(O_DIR)/libft/ft_printf/args_utils.o: libft/ft_printf/args_utils.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_format.o: libft/ft_printf/exec_format.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_subformat.o: libft/ft_printf/exec_subformat.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_out/public/ft_str_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/char.o: libft/ft_printf/formats/char.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/int.o: libft/ft_printf/formats/int.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/misc.o: libft/ft_printf/formats/misc.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/str.o: libft/ft_printf/formats/str.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_aprintf.o: libft/ft_printf/ft_aprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_logf.o: libft/ft_printf/ft_logf.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_out.o: libft/ft_printf/ft_out.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_printf.o: libft/ft_printf/ft_printf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_putf.o: libft/ft_printf/ft_putf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_vprintf.o: libft/ft_printf/ft_vprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h

$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_printf/exec_format.o \
$(O_DIR)/libft/ft_printf/exec_subformat.o \
$(O_DIR)/libft/ft_printf/formats/char.o $(O_DIR)/libft/ft_printf/formats/int.o \
$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_printf/formats/str.o \
$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_printf/ft_logf.o \
$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o: \
	INCLUDE_FLAGS += -Ilibft/ft_printf

# module ft::set
$(O_DIR)/libft/ft_set/first.o: libft/ft_set/first.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/get.o: libft/ft_set/get.c libft/ft_base/public/libft.h \
	libft/ft_set/internal.h libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/insert.o: libft/ft_set/insert.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/iter.o: libft/ft_set/iter.c libft/ft_base/public/libft.h \
	libft/ft_set/internal.h libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/remove.o: libft/ft_set/remove.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/utils.o: libft/ft_set/utils.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h

$(O_DIR)/libft/ft_set/first.o $(O_DIR)/libft/ft_set/get.o \
$(O_DIR)/libft/ft_set/insert.o $(O_DIR)/libft/ft_set/iter.o \
$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_set/utils.o: INCLUDE_FLAGS += \
	-Ilibft/ft_set

# module ft::vector
$(O_DIR)/libft/ft_vector/ft_vclear.o: libft/ft_vector/ft_vclear.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vpush.o: libft/ft_vector/ft_vpush.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vreserve.o: libft/ft_vector/ft_vreserve.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vspan.o: libft/ft_vector/ft_vspan.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h

# module tetri_map
$(O_DIR)/srcs/tetri_map/access.o: srcs/tetri_map/access.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h
$(O_DIR)/srcs/tetri_map/create.o: srcs/tetri_map/create.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h
$(O_DIR)/srcs/tetri_map/update.o: srcs/tetri_map/update.c \
	libft/ft_base/public/libft.h srcs/tetri_map/internal.h \
	srcs/tetri_map/public/tetri_map.h

$(O_DIR)/srcs/tetri_map/access.o $(O_DIR)/srcs/tetri_map/create.o \
$(O_DIR)/srcs/tetri_map/update.o: INCLUDE_FLAGS += -Isrcs/tetri_map

# module tetri_parser
$(O_DIR)/srcs/tetri_parser/check.o: srcs/tetri_parser/check.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_vector/public/ft_vector.h \
	srcs/tetri_parser/internal.h srcs/tetri_parser/public/tetri_parser.h
$(O_DIR)/srcs/tetri_parser/parser.o: srcs/tetri_parser/parser.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_vector/public/ft_vector.h \
	srcs/tetri_parser/internal.h srcs/tetri_parser/public/tetri_parser.h

$(O_DIR)/srcs/tetri_parser/check.o $(O_DIR)/srcs/tetri_parser/parser.o: \
	INCLUDE_FLAGS += -Isrcs/tetri_parser

# module tetri_solver
$(O_DIR)/srcs/tetri_solver/backtrack.o: srcs/tetri_solver/backtrack.c \
	libft/ft_base/public/libft.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/tetri_map/public/tetri_map.h \
	srcs/tetri_solver/internal.h srcs/tetri_solver/public/tetri_solver.h
$(O_DIR)/srcs/tetri_solver/build_pool.o: srcs/tetri_solver/build_pool.c \
	libft/ft_base/public/libft.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/tetri_map/public/tetri_map.h \
	srcs/tetri_solver/internal.h srcs/tetri_solver/public/tetri_solver.h
$(O_DIR)/srcs/tetri_solver/solve.o: srcs/tetri_solver/solve.c \
	libft/ft_base/public/libft.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h srcs/tetri_map/public/tetri_map.h \
	srcs/tetri_solver/internal.h srcs/tetri_solver/public/tetri_solver.h

$(O_DIR)/srcs/tetri_solver/backtrack.o $(O_DIR)/srcs/tetri_solver/build_pool.o \
$(O_DIR)/srcs/tetri_solver/solve.o: INCLUDE_FLAGS += -Isrcs/tetri_solver

fillit: $(O_FILES)

# public links
$(O_DIR)/_public/ft/file.h: libft/ft_file/public/file.h
$(O_DIR)/_public/ft/file_in.h: libft/ft_file_in/public/file_in.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_dstr.h: libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/_public/ft/ft_in.h: libft/ft_in/public/ft_in.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_str_out.h: libft/ft_out/public/ft_str_out.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/ft/set.h: libft/ft_set/public/set.h
$(O_DIR)/_public/tetri_map.h: srcs/tetri_map/public/tetri_map.h
$(O_DIR)/_public/tetri_parser.h: srcs/tetri_parser/public/tetri_parser.h
$(O_DIR)/_public/tetri_solver.h: srcs/tetri_solver/public/tetri_solver.h
