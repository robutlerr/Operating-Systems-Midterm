#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main () {
	// opening to read
	int file = open("q2TestFile.txt", O_RDONLY|O_WRONLY| O_APPEND);
	if (file == -1) {
		printf ("Error reading file!\n");
		return 1;
	}
	// creating the child w/ fork
	pid_t pid  = fork();

	// buffer for reading the files
	char buffer[50];
	// variable to store the read() in
	ssize_t bytesRead;

	if (pid  == 0) {
		// child process
		// reading test
		bytesRead = read(file, buffer, sizeof(buffer)-1);
		buffer[bytesRead] = '\0';
            	printf("Child read: %s\n", buffer);
		// writing test
		dprintf(file, "This is the child writing!");
	} else if (pid > 0){ 
		// parent process
		// reading test
		bytesRead = read(file, buffer, sizeof(buffer) - 1);
		buffer[bytesRead] = '\0';
            	printf("Parent read: %s\n", buffer);
		// writing test
		dprintf(file, "This is the parent writing!");
	} else {
		//fork failed
		printf("fork failed!\n");
	}
	// close the file
	close(file);
	return 0;
}

