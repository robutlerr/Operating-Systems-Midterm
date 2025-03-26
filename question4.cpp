#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main () {
	// creating the child w/ fork
	pid_t pid  = fork();

	if (pid < 0) {
        	// Proper fork failure handling
        	printf("fork failed");
        	return 1;
	} 
	if (pid  == 0) {
		// child process
		printf("I am the child! This will print before closing output");
		fflush(stdout);		
		close(STDOUT_FILENO);
		printf("I am the child! This will not print!");
	} else {
		//parent
	}
	return 0;
}
