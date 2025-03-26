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
	if (pid  == 0) {
		// child process
		printf("Hello!");		
	} else if (pid > 0){ 
		// parent process
		// sleep for 1 second so that the child can run first
		sleep(1);
		printf("Goodbye!");
	} else {
		//fork failed
		printf("fork failed!\n");
	}
	return 0;	
}
