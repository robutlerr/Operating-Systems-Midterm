#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() {
	// creating the variables that the user will be asked for
	string programName = " ";
	int count = 0;
	char  seqOrPar ='s';

	// ask the user for the program to run
	cout << "closh>";
	cin >> programName;

	// error catching
	if (programName.length() <=  2 || programName[0] != '.' || programName[1] != '/') {
		printf("Error: Please enter program name as: ./programName");
		return 1;
	}

	// ask the user for the number of times to run it
	cout << "count>";
	cin >> count;

	if (count < 0 ||  count > 9) {
		printf("Error: Please enter a number 1-9");
		return 1;
	}

	// ask the user if they want to run the program parallel or sequential (w/ children)
	cout << "[p]arallel or [s]equential>";
	cin >> seqOrPar;

	if (seqOrPar != 's' &&  seqOrPar != 'p') {
		printf("Error: Please enter s or p");
		return 1;
	}

	// make child processes for the number of times the user wants the command to run
	for (int i=0; i<count; i++) {
		pid_t pid = fork();  // Create a new process
		// if fail, return
        	if (pid < 0) {
            		printf("Fork failed");
            		return 1;
        	}
		// child
        	if (pid == 0) {
			char *args[] = { (char*)programName.c_str(), NULL };
			execvp(args[0], args);
		// parent
		} else {
			if (seqOrPar == 's') {
				waitpid(pid, NULL, 0);
			}
		}
	}
	return 0;
}
