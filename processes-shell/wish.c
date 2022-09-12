#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // fork()
#include <sys/wait.h>

void exit_wish()
{
	printf("Exiting Wish shell......\n");
	exit(0);
}

int main(int argc, char **argv)
{
	printf("Hi, This is wish!\n");
	char str1[20];
	while (1)
	{
		scanf("%s", str1);
		printf("Your input: %s\n", str1);
		if ( !strcmp(str1, "exit") ) exit_wish();

		int rc = fork();
		if (rc < 0) {
			// fork failed
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (rc == 0) {
			// child process
			//parse_input();
			if (!strcmp(str1, "ls")) {
				printf("built-in cmd: ls\n");
			}
			return 0;
		} else {
			// parent process
			int rc_wait = wait(NULL);
			printf("child process with cmd %s has finished\n", str1);
		}
	}

	return 0;

}
