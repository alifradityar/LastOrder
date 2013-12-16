#ifndef __ROOT
#define __ROOT
#include "entry.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class RootDirectory{
	public :
		vector <Entry> data;
		RootDirectory();
		
		string toString();
		void load(string);
};
#endif
