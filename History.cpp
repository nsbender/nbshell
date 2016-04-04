/*
 * History.cpp
 *
 * Defines methods for History object
 * Author: Nathaniel Bender
*/

#include "History.h"

using namespace std;

History::History(){

}

string History::getLast() const{
	return histVec[histVec.size()];
}

void History::getAll(){
	for (int i = 0; i < histVec.size(); i++){
		cout << histVec[i] << endl;
	}
}

void History::add(string command){
	if (command != ""){
		histVec.push_back(command);
	}
}

void History::clear(){
	histVec.clear();
}
