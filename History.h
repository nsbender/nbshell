/*
 * History.h
 *
 *  Created on: Mar 30, 2016
 *  Authors: Nathaniel Bender (nsb2)
 */

#ifndef HISTORY_H_
#define HISTORY_H_

#include <vector>
#include <iostream>

using namespace std;

class History {
public:
	History();
	string getLast() const;
	void getAll();
	void add(string command);
	void clear();
private:
	vector<string> histVec;
};

#endif
