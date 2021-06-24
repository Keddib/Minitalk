SRV			= server

CLT			= client

GCC			= gcc -Wall -Wextra -Werror

SSRC		= server.c utils/minitalk_utils.c utils/ft_memset.c

CSRC		= client.c utils/minitalk_utils.c


all:	$(SRV) $(CLT)

$(SRV) : $(SSRC)
	@$(GCC) -o $(SRV) $(SSRC)

$(CLT) : $(CSRC)
	@$(GCC) -o $(CLT) $(CSRC)

clean:

fclean: clean
	@rm -rf $(SRV) $(CLT)

re: fclean all

.PHONY: clean fclean re all
