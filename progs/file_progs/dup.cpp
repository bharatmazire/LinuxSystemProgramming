
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
	int fd;
	int stdoutfd;

	if (argc != 2) {
		printf("Usage: %s <file_in_which_you_want_to_redirect_output\n", argv[0]);
		return -1;
	}

	fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	if (-1 == fd) {
		printf("Unable to open/create file(%s). Error: %s\n", argv[1], strerror(errno));
		return -1;
	}
	printf("File open success. File desc = %d\n", fd);

	close(STDOUT_FILENO);	//	This is equivalent to close(1);
	stdoutfd = dup(fd);
	if (-1 == stdoutfd) {
		printf("Unable to dup file desc %d. Error: %s\n", fd, strerror(errno));
		return -1;
	}
	printf("Duped file descriptor = %d\n", stdoutfd);

	printf("Whatever we will write on stdout will be written to file.\n");
	close(fd);

	printf("Whatever we will write on stdout after closing the file will also written to file.\n");
	close(stdoutfd);

	int ret = printf("Printf will fail here as stdout is closed.\n");
	if (ret < 0)
	{
		write (2, "Printf is failed\n", strlen("Printf is failed\n"));
	}

	return 0;
}

