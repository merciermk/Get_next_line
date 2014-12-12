### compilation
make -C libft/ fclean
make -C libft/
gcc -g -Wall -Wextra -Werror -I libft/ -c get_next_line.c
gcc -g -Wall -Wextra -Werror -I libft/ -c main.c
gcc -g -Wall -Wextra -Werror get_next_line.o main.o -L libft/ -lft -o test_gnl
### debut des tests
echo "--- Hello World"
./test_gnl ztest_s02_gnl/hello
echo "--- 1*8 char with _n"
./test_gnl ztest_s02_gnl/test81
echo "--- 2*8 char with _n"
./test_gnl ztest_s02_gnl/test82
echo "--- 3*8 char with _n"
./test_gnl ztest_s02_gnl/test83
echo "--- 1*4 char with _n"
./test_gnl ztest_s02_gnl/test91
echo "--- 2*4 char with _n"
./test_gnl ztest_s02_gnl/test92
echo "--- 3*4 char with _n"
./test_gnl ztest_s02_gnl/test93
echo "--- a char without _n"
./test_gnl ztest_s02_gnl/test1
echo "--- line without _n"
./test_gnl ztest_s02_gnl/test2
echo "--- empty file"
./test_gnl ztest_s02_gnl/test3
### bonus
#echo "--- 3 fd (digit->letter->symbol)"
#./test_gnl ztest_s02_gnl/test41 ztest_s02_gnl/test42 ztest_s02_gnl/test43
#echo "--- 42"
#./test_gnl ztest_s02_gnl/bob1 ztest_s02_gnl/bob2 ztest_s02_gnl/bob3
### test de performance
 echo "--- creation mega fichier"
 openssl rand -out 27.txt -base64 $((2**27 * 3/4))
 echo "--- speedtest"
 time ./test_gnl 27.txt > /dev/null
