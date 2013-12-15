#ifndef DATA_POOL_H
#define DATA_POOL_H
#include <iostream>
#include <ctime>
using namespace std;

class DataPool{
	private :
		string namaFile;
		char fileAtt;
		unsigned short clock;
		unsigned short date;
		unsigned short dir;
		int size;
		
	public : 
		DataPool();
		DataPool(string name, char att, short _dir, int _size);
		void setAtt(char att);
		void setClock();
		void setDate();
		void setDir(short _dir);
		void setSize(int _size);
		string DecToBin(int number);
		int BinToDec(string number);
		string checkBin(string binary,string status);
};
#endif
