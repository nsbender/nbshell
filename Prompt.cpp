/*
 * Prompt.cpp
 *
 *  Created on: Mar 30, 2016
 *  Authors: Nathaniel Bender (nsb2)
 */

#include "Prompt.h"

using namespace std;

Prompt::Prompt() {
//Constructs a Prompt instance
	char *path=NULL;
	path = getcwd(path, NULL);
	currentString = path;
}

string Prompt::get() const{
//Returns the current working directory
	return currentString;
}

void Prompt::update(){
//Check for changes to the current working directory and record them
	char *path=NULL;
	path = getcwd(path, NULL);
	currentString = path;
}
