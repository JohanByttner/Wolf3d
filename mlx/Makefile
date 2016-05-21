# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 22:55:11 by jbyttner          #+#    #+#              #
#    Updated: 2016/05/15 23:20:01 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmlx.a



UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	MLX_SOURCE = minilibx_linux
	EXECUTABLE = libmlx_x86_64.a
else
	MLX_SOURCE = minilibx_mac
	EXECUTABLE = tobefound.a
endif

MAKE = make --silent -C $(MLX_SOURCE)

all: $(NAME)

$(NAME):
	@echo Making libmlx for $(UNAME)
	@$(MAKE)
	@cp $(MLX_SOURCE)/$(EXECUTABLE) $(NAME)

clean:
	@echo Cleaning $(MLX_SOURCE)
	@$(MAKE) clean

fclean: clean
	@echo Removing $(NAME)
	@rm -rf $(NAME)

re: fclean all
