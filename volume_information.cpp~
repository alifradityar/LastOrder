#include <iostream>
#include "volume_information.h"
#include <cstdlib>

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

void VolumeInformation::load(string input){
	int ctr=0;
	string temp="";
	for (int i=0; i<1024; i++){
		ctr++;
		if (ctr==8){
			temp = temp + input[i];
			magicString = temp;
			cout << magicString << endl;
			temp ="";
		}
		else if (ctr==264){
			temp = temp + input[i];
			namaPartisi = temp;
			cout << namaPartisi << endl;
			temp ="";
		}
		else if (ctr==268){
			temp = temp + input[i];
			jumlahByte = str2int(temp);
			cout << jumlahByte << endl;
			temp ="";
		}
		else if (ctr==272){
			temp = temp + input[i];
			filesystemCapacity = str2int(temp);
			cout << filesystemCapacity << endl;
			temp ="";
		}
		else if (ctr==276){
			temp = temp + input[i];
			freeBlock = str2int(temp);
			cout << freeBlock<< endl;
			temp ="";
		}
		else if (ctr==280){
			temp = temp + input[i];
			firstIdxBlock = str2int(temp);
			cout << firstIdxBlock << endl;
			temp ="";
		}
		else if (ctr== 1020){
			temp = temp + input[i];
			reserved = temp;
			cout << reserved << endl;
			temp ="";
		}
		else if (ctr==1024){
			temp = temp + input[i];
			sist = temp;
			cout << sist << endl;
			temp ="";
		}
		else{
			temp = temp + input[i];
		}
	}
}

int VolumeInformation::str2int(string chr){
	string temp="";
	string result="";
	string zero = "0";
	for(int i=0;i<4;i++){
		temp = DecToBin(int(chr[i]));	
		int delta = 8 - temp.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				temp = zero + temp;
			}
		}
		result = result + temp;
	}
	//cout << "result : " << result << endl;
	return BinToDec(result);
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
