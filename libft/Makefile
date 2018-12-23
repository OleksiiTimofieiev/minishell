# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 21:09:12 by otimofie          #+#    #+#              #
#    Updated: 2018/12/22 14:00:23 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a

SRCS =  ft_printf.c \
 		ft_wchar_print.c \
 		parsing.c \
 		printing.c \
 		parsing_1.c \
		parsing_2.c \
		parsing_3.c \
		printing_1.c \
		print_simple_string.c \
		print_simple_1.c \
		print_int_1.c \
		print_int_2.c \
		print_int_u_1.c \
		print_int_u_2.c \
		print_w_char_1.c\
		print_w_s_1.c\
		print_w_s_2.c\
		different.c \
		different_1.c \
		different_2.c \
		ft_print_hex_1.c \
		ft_print_hex_2.c \
		print_hex_big_1.c \
		print_hex_big_2.c \
		print_octlal_main_1.c \
		print_octal_main_2.c \
		ft_print_hex_main_pointer_1.c \
		ft_print_hex_main_pointer_2.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_size_bin.c \
		ft_decimal_length.c \
		ft_print_hex.c \
		ft_hex_length.c \
		ft_print_hex_big.c \
		ft_print_octal.c \
		ft_octal_length.c \
		get_next_line.c \
		ft_isint.c \
		ft_2d_arr_size.c \
		ft_isposint.c \
		ft_str_find_chr.c \
		ft_clean_2d_char.c \
		ft_check_quantity.c \
		ft_strnccpy.c \
		ft_line_is_digit.c \
		len_char_2d_array.c \
		copy_2d_char.c \
		ft_char_position.c \
		ft_quantity_of_chars.c \

		#colors
		RESET		= \033[m
		RED         = \033[1;31m
		GREEN       = \033[01;38;05;46m
		YELLOW      = \033[01;38;05;226m
		BLUE        = \033[03;38;05;21m
		VIOLET      = \033[01;38;05;201m
		CYAN        = \033[1;36m
		WHITE       = \033[01;38;05;15m

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I.
OBJECTS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJECTS): %.o: %.c
	@ gcc -c $(CFLAGS) $(IFLAGS) $< -o $@
	@ echo  "$(BLUE)█$(RES)\c)"

$(NAME): $(OBJECTS)
	@ ar rcs $(NAME) $(OBJECTS) 
	@ echo  "$(RESET) $(YELLOW) : OK$(RESET)"

clean:
	@ /bin/rm -f $(OBJECTS)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
