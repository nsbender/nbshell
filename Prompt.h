/*
 * Prompt.h
 *
 *  Created on: Mar 30, 2016
 *  Authors: Nathaniel Bender (nsb2)
 */

#ifndef PROMPT_H_
#define PROMPT_H_

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

class Prompt {
public:
	Prompt();
	string get() const;
	void update();
	string currentString;

private:

};

#endif /* PROMPT_H_ */
