#ifndef __DATA_POOL
#define __DATA_POOL
#include <iostream>
#include <vector>
#include "entry.h"
#include <ctime>
#include <string>
using namespace std;

class DataPool{
	public :
		vector <Entry> data;
		DataPool();
		
		string toString();
		void load(string);
};
#endif
