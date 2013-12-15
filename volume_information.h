#ifndef VOLUME_INFORMATION_H
#define VOLUME_INFORMATION_H
#include <iostream>
#include <cstring>

using namespace std;

class VolumeInformation{
	private :
		string magicString;
		string namaPartisi;
		int jumlahByte;
		int filesystemCapacity;
		int freeBlock;
		int firstIdxBlock;
		string reserved;
		string sist;

	public : 
		VolumeInformation();
		VolumeInformation(string nama, int capacity, int _free, int _first);
		void setNama(string nama);
		void setCapacity(int capacity);
		void setFree(int _free);
		void setFirst(int _first);
		string getNama();
		int getCapacity();
		int getFree();
		int getFirst();
		string DecToBin(int number);
		int BinToDec(string number);
		string int2str(string bin);
		string toString();
		void Print();
};
#endif
