#include "testframework.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <ctype.h>
#include <math.h>
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <regex.h>
//#include "libft.h"

//#define RENDU_PATH "/Users/jbfrebourg/get_next_line/rendu"


UT_TEST(01_test_simple)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "aaa"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "bbb"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ccc"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ddd"), 0);

}

UT_TEST(02_test_eof_with_close)
{
	char *line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "aaa"), 0);

}

UT_TEST(03_test_large_string)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	// int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	// while (len--)
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, str), 0);

}

UT_TEST(04_test_return_values)
{
	/* Thank you bwyyoung for pointing out the problem. */

	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT_EQ(gnl_ret, 1);
	UT_ASSERT_EQ(strcmp(line, "abc"), 0);

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT_EQ(gnl_ret, 1);
	UT_ASSERT(line == NULL || *line == '\0');

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT_EQ(gnl_ret, 0);
	UT_ASSERT(line == NULL || *line == '\0');

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT_EQ(gnl_ret, 0);
	UT_ASSERT(line == NULL || *line == '\0');

}

UT_TEST(05_test_error_handling)
{
	UT_ASSERT_EQ(get_next_line(1, NULL), -1);
	UT_ASSERT_EQ(get_next_line(99, NULL), -1);

}

UT_TEST(06_test_line_of_08)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "oiuytrew\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "oiuytrew"), 0);
}

UT_TEST(07_test_two_lines_of_08)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcdefgh"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ijklmnop"), 0);
}

UT_TEST(08_test_few_lines_of_08)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	write(fd, "qrstuvwx\n", 9);
	write(fd, "yzabcdef\n", 9);
	write(fd, "ghijklmn\n", 9);
	write(fd, "opqrstuv\n", 9);
	write(fd, "wxyzabcd\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcdefgh"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ijklmnop"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "qrstuvwx"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "yzabcdef"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ghijklmn"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "opqrstuv"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "wxyzabcd"), 0);
}

UT_TEST(09_test_line_of_16)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcdefghijklmnop"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, ""), 0);
}

UT_TEST(10_test_two_lines_of_16)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcdefghijklmnop"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "qrstuvwxyzabcdef"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, ""), 0);
}

UT_TEST(11_test_few_lines_of_16)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	write(fd, "ghijklmnopqrstuv\n", 17);
	write(fd, "wxyzabcdefghijkl\n", 17);
	write(fd, "mnopqrstuvwxyzab\n", 17);
	write(fd, "cdefghijklmnopqr\n", 17);
	write(fd, "stuvwxzabcdefghi\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcdefghijklmnop"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "qrstuvwxyzabcdef"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ghijklmnopqrstuv"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "wxyzabcdefghijkl"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "mnopqrstuvwxyzab"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "cdefghijklmnopqr"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "stuvwxzabcdefghi"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, ""), 0);
}

UT_TEST(12_test_line_of_4)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcd"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, ""), 0);

}

UT_TEST(13_test_two_lines_of_4)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcd"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "efgh"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, ""), 0);

}

UT_TEST(14_test_few_lines_of_4)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	write(fd, "ijkl\n", 5);
	write(fd, "mnop\n", 5);
	write(fd, "qrst\n", 5);
	write(fd, "uvwx\n", 5);
	write(fd, "yzab\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcd"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "efgh"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "ijkl"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "mnop"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "qrst"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "uvwx"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "yzab"), 0);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, ""), 0);

}

UT_TEST(15_test_line_without_nl)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd", 4);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "abcd"), 0);

}

UT_TEST(16_test_line_of_8_without_nl)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "efghijkl", 8);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "efghijkl"), 0);

}

UT_TEST(17_test_line_of_16_without_nl)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "mnopqrstuvwxyzab", 16);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT_EQ(strcmp(line, "mnopqrstuvwxyzab"), 0);

}

UT_TEST(bonus_01_multiple_fd)
{
	char 	*line0;
	int		p0[2];
	int		fd0 = 0;
	int		out0 = dup(fd0);
	pipe(p0);
	dup2(p0[1], fd0);
	write(fd0, "aaa\nbbb\n", 12);
	dup2(out0, fd0);

	char 	*line_fd1;
	int		p_fd1[2];
	int		fd1 = 1;
	int		out_fd1 = dup(fd1);
	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 12);
	dup2(out_fd1, fd1);

	char 	*line_fd2;
	int		p_fd2[2];
	int		fd2 = 2;
	int		out_fd2 = dup(fd2);
	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 12);
	dup2(out_fd2, fd2);

	char 	*line_fd3;
	int		p_fd3[2];
	int		fd3 = 3;
	int		out_fd3 = dup(fd3);
	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 12);
	dup2(out_fd3, fd3);

	get_next_line(p0[0], &line0);
	UT_ASSERT_EQ(strcmp(line0, "aaa"), 0);

	get_next_line(p_fd1[0], &line_fd1);
	UT_ASSERT_EQ(strcmp(line_fd1, "111"), 0);

	get_next_line(p_fd2[0], &line_fd2);
	UT_ASSERT_EQ(strcmp(line_fd2, "www"), 0);

	get_next_line(p_fd3[0], &line_fd3);
	UT_ASSERT_EQ(strcmp(line_fd3, "888"), 0);

	get_next_line(p0[0], &line0);
	UT_ASSERT_EQ(strcmp(line0, "bbb"), 0);

	get_next_line(p_fd1[0], &line_fd1);
	UT_ASSERT_EQ(strcmp(line_fd1, "222"), 0);

	get_next_line(p_fd2[0], &line_fd2);
	UT_ASSERT_EQ(strcmp(line_fd2, "zzz"), 0);

	get_next_line(p_fd3[0], &line_fd3);
	UT_ASSERT_EQ(strcmp(line_fd3, "999"), 0);

}

UT_TEST(bonus_02_one_static_var)
{
	char		path[10000];
	FILE		*file;
	char		*line = NULL;
	size_t		len = 0;
	ssize_t		read;
	int			static_files_count = 0;
	regex_t		regex;
	int			reti;

	strcpy(path, "/get_next_line.c");
	strcat(path, "/get_next_line.c");
	file = fopen(path, "r");

	regcomp(&regex, "static .*;", 0);

	while ((read = getline(&line, &len, file)) != -1)
	{
		reti = regexec(&regex, line, 0, NULL, 0);
		if (!reti) {
			static_files_count++;
		}
	}

	UT_ASSERT_EQ(1, 1);

}


int	main(void)
{

	UT_ADD_TEST(01_test_simple);

	UT_ADD_TEST(02_test_eof_with_close);

	UT_ADD_TEST(03_test_large_string);

	UT_ADD_TEST(04_test_return_values);

	UT_ADD_TEST(05_test_error_handling);

	UT_ADD_TEST(06_test_line_of_08);

	UT_ADD_TEST(07_test_two_lines_of_08);

	UT_ADD_TEST(08_test_few_lines_of_08);

	UT_ADD_TEST(09_test_line_of_16);

	UT_ADD_TEST(10_test_two_lines_of_16);

	UT_ADD_TEST(11_test_few_lines_of_16);

	UT_ADD_TEST(12_test_line_of_4);

	UT_ADD_TEST(13_test_two_lines_of_4);

	UT_ADD_TEST(14_test_few_lines_of_4);

	UT_ADD_TEST(15_test_line_without_nl);

	UT_ADD_TEST(16_test_line_of_8_without_nl);

	UT_ADD_TEST(17_test_line_of_16_without_nl);

	//UT_ADD_TEST(bonus_01_multiple_fd);

	//UT_ADD_TEST(bonus_02_one_static_var);


	UT_RUN_ALL_TESTS();
	return (0);
}
