#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	struct stat statbuf;

	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
	{
		printf("File open failed for error %s\n", strerror(errno));
		return -1;
	}

	ret = fstat(fd, &statbuf);
	if (-1 == fd)
	{
		printf("fstat failed for error %s\n", strerror(errno));
		return -1;
	}

	printf("dev_t     = %d\n", statbuf.st_dev);     /* ID of device containing file */
	printf("ino_t     = %d\n", statbuf.st_ino);     /* inode number */
	printf("mode_t    = %d\n", statbuf.st_mode);    /* protection */
	printf("nlink_t   = %d\n", statbuf.st_nlink);   /* number of hard links */
	printf("uid_t     = %d\n", statbuf.st_uid);     /* user ID of owner */
	printf("gid_t     = %d\n", statbuf.st_gid);     /* group ID of owner */
	printf("dev_t     = %d\n", statbuf.st_rdev);    /* device ID (if special file) */
	printf("off_t     = %d\n", statbuf.st_size);    /* total size, in bytes */
	printf("blksize_t = %d\n", statbuf.st_blksize); /* blocksize for file system I/O */
	printf("blkcnt_t  = %d\n", statbuf.st_blocks);  /* number of 512B blocks allocated */
	printf("time_t    = %d\n", statbuf.st_atime);   /* time of last access */
	printf("time_t    = %d\n", statbuf.st_mtime);   /* time of last modification */
	printf("time_t    = %d\n", statbuf.st_ctime);   /* time of last status change */

	close(fd);

	return 0;
}

