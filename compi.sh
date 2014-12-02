make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -I libft/ -c get_next_line.c
gcc -Wall -Wextra -Werror -I libft/ -c main.build.c testframework.c
gcc -o test_gnl *.o -L libft/ -lft

