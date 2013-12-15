#include <iostream>
#include "volume_information.h"

using namespace std;

VolumeInformation::VolumeInformation(){
	magicString = "SisterFS";
	for (int i=0;i<256;i++){
		namaPartisi =  namaPartisi + '\0';
	}
	jumlahByte = 1024;
	filesystemCapacity = 0;
	freeBlock = 0;
	firstIdxBlock = 0;
	for (int i = 0; i<740; i++){
		reserved= reserved + '0';
	}
	sist = "SIST";
}

VolumeInformation::VolumeInformation(string nama, int capacity, int _free, int _first){
	magicString = "SisterFS";
	if (nama.length()<=256){
		namaPartisi = nama;
		for (int i=nama.length();i<256;i++){
			namaPartisi =  namaPartisi + '\0';
		}
	}
	else {
		for (int i=0;i<256;i++){
			namaPartisi =  namaPartisi + '\0';
		}
	}
	jumlahByte = 1024;
	filesystemCapacity = capacity;
	freeBlock = _free;
	firstIdxBlock = _first;
	for (int i = 0; i<740; i++){
		reserved= reserved + '0';
	}
	sist = "SIST";
}

void VolumeInformation::setNama(string nama){
	if (nama.length()<=256){
		namaPartisi = nama;
		for (int i=nama.length();i<256;i++){
			namaPartisi =  namaPartisi + '\0';
		}
	}
	else {
		for (int i=0;i<256;i++){
			namaPartisi =  namaPartisi + '\0';
		}
	}
}
void VolumeInformation::setCapacity(int capacity){
	filesystemCapacity = capacity;
}

void VolumeInformation::setFree(int _free){
	freeBlock = _free;
}

void VolumeInformation::setFirst(int _first){
	firstIdxBlock = _first;
}

string VolumeInformation::getNama(){
	return namaPartisi;
}

int VolumeInformation::getCapacity(){
	return filesystemCapacity;
}

int VolumeInformation::getFree(){
	return freeBlock;
}

int VolumeInformation::getFirst(){
	return firstIdxBlock;
}

string VolumeInformation::DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}

int VolumeInformation::BinToDec(string number)
{
    int result = 0, pow = 1;
    for ( int i = number.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (number[i] - '0') * pow;

    return result;
}

string VolumeInformation::int2str(string bin){
	string result="";
	string temp="";
	int ctr=0;
	string zero = "0";
	int delta = 32 - bin.length();
	if (delta>=0){
		for(int i=0;i<delta;i++){
			bin = zero + bin;
		}
	}
	//cout << "test: " << bin << endl;
	for(int i=0;i<32;i++){
		ctr++;
		if (ctr%8==0){
			temp = temp + bin[i];
			//cout << "temp : " << temp << endl;
			//cout << BinToDec(temp) << endl;
			//cout << char(BinToDec(temp)) << endl;
			result = result + char(BinToDec(temp));
			temp="";
		}
		else{
			temp = temp + bin[i];
		}
	}
	//cout << "result: " << result << endl;
	//cout << result.length() << endl;
	return result;
}

string VolumeInformation::toString(){
	string VolInfo;
	string jmlB = int2str(DecToBin(jumlahByte)); 
	string capacity = int2str(DecToBin(filesystemCapacity));
	string free = int2str(DecToBin(freeBlock));
	string first = int2str(DecToBin(firstIdxBlock));
	VolInfo = magicString + namaPartisi + jmlB + capacity + free + first + reserved + sist;
	return VolInfo;
}

void VolumeInformation::Print(){
	cout << "Magic String: " << magicString << endl;
	cout << "Nama Partisi: " << namaPartisi << endl;
	cout << "Jumlah Byte per Block : " << jumlahByte << endl;
	cout << "Kapasitas Filesystem : " << filesystemCapacity << endl;
	cout << "Free Block : " << freeBlock << endl;
	cout << "Index block pertama yg bebas : " << firstIdxBlock << endl;
	cout << "Reserved : " << reserved  << endl;
	cout << "Magic String: " << sist << endl;
}
