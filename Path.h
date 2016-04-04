/*
 * Path.h
 *
 *  Created on: Mar 29, 2016
 *  Authors: Nathaniel Bender (nsb2)
 */

#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <vector>
#include <boost/algorithm/string/classification.hpp>

using namespace std;

class Path {
public:
	Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
private:
	vector<string> pathVec;
};

#endif /* PATH_H_ */
