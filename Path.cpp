/*
 * Path.cpp
 *
 *  Created on: Mar 29, 2016
 *  Authors: Nathaniel Bender (nsb2)
 */

#include "Path.h"
using namespace std;

Path::Path() {
//Construct an instance of path, and store each element of PATH to a vector
	if( char* env_p = getenv("PATH")){
		const char* split = strtok(env_p,":"); //Easily splitting strings by token ':'
		while (split != NULL)
		{
			pathVec.push_back(split); // Add each portion of the PATH variable to an array.
			split = strtok (NULL, ":");
		}
	}
}

int Path::find(const string& program) const{
//Return the index of the path vector containing the program specified
	for (int i = 0; i < pathVec.size(); i++){
		DIR *dir = NULL;
		struct dirent *ent = NULL;
		if ((dir = opendir (pathVec[i].c_str())) != NULL) {
			while ((ent = readdir(dir)) != NULL) {
				if (ent->d_name == program){
				return i;
				}
			}
			closedir (dir);
		}
		else{
			/* could not open directory */
			perror ("");
		}
	}
	return -1;
}

string Path::getDirectory(int i) const{
//Return the PATH directory at the specified vector index
	return (pathVec[i]);
}
