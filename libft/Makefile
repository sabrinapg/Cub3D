# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkpg-md- <dkpg-md-@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 17:02:04 by dkpg-md-          #+#    #+#              #
#    Updated: 2025/03/09 17:02:44 by dkpg-md-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_memcpy.c ft_strrchr.c ft_isdigit.c ft_memmove.c \
	   ft_strncmp.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	   ft_strlcpy.c ft_memchr.c ft_strlcat.c ft_memcmp.c ft_toupper.c \
	   ft_memset.c ft_tolower.c ft_strnstr.c ft_bzero.c ft_strchr.c ft_atoi.c \
	   ft_strdup.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	   ft_putendl_fd.c ft_split.c ft_calloc.c ft_strjoin.c ft_strtrim.c \
	   ft_striteri.c ft_strmapi.c ft_itoa.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
