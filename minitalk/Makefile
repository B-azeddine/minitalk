INC = minitalk.h

CFLAGS = -Wall -Wextra -Werror

all : server client

server : server.c ft_utils.c $(INC) 
						cc $(CFLAGS) server.c ft_utils.c -o server

client : client.c ft_utils.c $(INC)
						cc $(CFLAGS) client.c ft_utils.c -o client

clean :
		 rm  -rf server client

fclean : clean
					rm -rf server client

re : fclean all