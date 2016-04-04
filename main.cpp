/*
 * main.cpp
 *
 *  Created on: Mar 29, 2016
 *  Authors: Nathaniel Bender
 */

#include "NBShell.h"
#include "Prompt.h"
#include <unistd.h>


int main(){
	NBShell * nb = new NBShell();
	nb -> run();
}


