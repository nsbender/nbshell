/*
 * CommandLine.cpp
 *
 *  Created on: Mar 29, 2016
 *  Authors: Nathaniel Bender
 *  Reads in command-line from in, parses it and builds instance
 *  variables for argc and argv
 */

#include "CommandLine.h"
#include <iostream>

/*Constructor for CommandLine for reading a command-line from in, parses it and builds instance
 * variables for argc and argv
 * @param: istream& in
 * http://stackoverflow.com/questions/16029324/c-splitting-a-string-into-an-array
 */
CommandLine::CommandLine(istream& in){
	ifAmpersand = false;

	//assigns cin string to "input"
	getline(in, input);
	rawInput = input;
	//looks and finds '&' in input string.
	size_t found = input.find("&");
	if (found!=string::npos){
		ifAmpersand = true;
		cout << "Ampersand found" << endl;
		input.erase(std::remove(input.begin(), input.end(), '&'), input.end());
	}

	if (input.size() != 0){
		argc = 1;
		//gets the number of words in the array by counting the spaces.
		for (unsigned i = 0; i < input.size(); i++) {
			if (isspace(input.at(i))) {
				argc++;
			}
		}
		//dynamically allocates memory for argv array.
		char* temp;
		char* myInput = new char[argc];
		myInput = const_cast<char*>(input.c_str());
		/* stores the first word in argv, as strtok chops off the first word. Then arranges the rest of the
	 		words into individual characters */
		ARGV = (char**) calloc(argc, sizeof(char*));
		temp = strtok(myInput, " ");
		for (int i = 0; i < argc; i++){
			ARGV[i] = temp;
			temp = strtok(NULL, " ");
		}
		free(temp);
	}
	else{
		argc = 0;
		ARGV = NULL;
	}
}

char* CommandLine::getCommand() const{
	//Return only the first argument from the command line (The original command)
	return ARGV[0];
}

int CommandLine::getArgCount() const {
	//Return the count of arguments in the command line (including the original command)
	return argc;
}

char** CommandLine::getArgVector() const {
	//Return the whole array of arguments from the command line
	return ARGV;
}

char* CommandLine::getArgVector(int i){
	//Return argument of the command contained at the specified index
	return ARGV[i];
}

string CommandLine::getRawInput(){
	return rawInput;
}

bool CommandLine::Ampersand() const {
	//Returns whether or not an ampersand is present in the command string
	return ifAmpersand;
}

CommandLine::~CommandLine() {
	//Destructor deallocates argument array
	free(ARGV);
}
