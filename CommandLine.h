/*
 * CommandLine.h
 *
 *  Created on: Mar 29, 2016
 *  Authors: Nathaniel Bender
 *  Reads in command-line from in, parses it and builds instance
 *  variables for argc and argv
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;


class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i);
	string getRawInput();
	bool Ampersand() const;
	virtual ~CommandLine();

private:
	string rawInput = "";
	string input = "";
	int argc = 0;
	bool ifAmpersand;
	char* argv;
	char** ARGV;

};

#endif /* COMMANDLINE_H_ */
