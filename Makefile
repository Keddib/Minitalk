SRV			= server

CLT			= client

GCC			= gcc -Wall -Wextra -Werror

SSRC		= server.c minitalk_utils.c

CSRC		= client.c minitalk_utils.c


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
