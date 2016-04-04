/*
 * NBShell.cpp
 *
 *  Created on: Mar 29, 2016
 *  Authors: Nathaniel Bender (nsb2)
 */

#ifndef NBShell_H_
#define NBShell_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include  <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"

using namespace std;

class NBShell {

public:
	NBShell();
	void run();
};

#endif
