/*
 * NBShell.h
 *
 *  Created on: Apr 1, 2016
 *  Authors: Nathaniel Bender (nsb2)
 *  NBShell initializes the shell and allows it to be executable.
 */
#include "NBShell.h"

using namespace std;

NBShell::NBShell() {

}

void NBShell::run() {
	Prompt * prompt = new Prompt();
	Path * path = new Path();
	while (true){
		cout << (prompt -> get()) << "$ " << flush;
		CommandLine * cmd = new CommandLine(cin);

		if (cmd->getArgCount() == 0){ // If the input is empty, do nothing (Allow the user to press enter with no text)
			cmd->~CommandLine();
			continue;
		}

		else if ((string)cmd -> getCommand() == "cd"){
			struct stat st;
			if (stat((cmd->getArgVector(1)), &st) == 0 && S_ISDIR(st.st_mode)) //Check to make sure the directory exists
			{
				chdir(cmd->getArgVector(1)); //Tell the system to change the current working directory
				prompt->update();
				cmd->~CommandLine(); // Destroy the CommandLine after it is done and restart the loop.
				continue;
			}
			else {
				cout << "No such directory!" << endl;
				cmd->~CommandLine();
				continue;
			}
		}

		else if ((string)cmd -> getCommand() == "exit"){
			exit(0); // Exit the program
		}

		else if ((string)cmd -> getCommand() == "pwd"){
			cout << prompt->get() << endl;
			cmd->~CommandLine();
			continue;
		}

		else{
			int status = path -> find((string)cmd -> getCommand());
			if (status != -1 ){ // After checking that the program exists...
				pid_t pid;
				int forkStatus;
				string completePath = (path->getDirectory(status)) + "/" + ((string)cmd -> getCommand()); // Add the file name to the end of the directory that contains it
				if ((pid = fork()) < 0) { // Attempt to create a child using fork
					perror("fork() error");
					exit(-1);
				}
				else if (pid == 0) { //Check to see if fork isn't a parent; If so execute the command.
					if (execve(completePath.c_str(),cmd->getArgVector(), NULL) < 0) { //Execute the file and pass in its arguments from the CommandLine
						perror("execve() error");
						cmd->~CommandLine();
						continue;
					}
					exit(0);
				}
				//Have the parent wait for child completion if & is included in the command
				if (cmd->Ampersand() == false) {
					waitpid(pid, &forkStatus, 0); // Wait for the child with the PID specified at its creation
					cmd->~CommandLine();
					continue;
				}
			}
			else{
				cout << "Command not found." << endl;
			}
		}
	}
}
