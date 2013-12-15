#include <iostream>
#include "VolumeInformation.h"

using namespace std;

VolumeInformation::VolumeInformation(){
	magicString = "SisterFS";
	for (int i=0;i<256;i++){
		namaPartisi[i] = '\0';
	}
	jumlahByte = 1024;
	filesystemCapacity = 0;
	freeBlock = 0;
	firstIdxBlock = 0;
	for (int i = 0; i<740; i++){
		reserved[i]='0';
	}
	reserved[740]='\0';
	sist = "SIST";
}

VolumeInformation::VolumeInformation(string nama, int capacity, int _free, int _first){
	magicString = "SisterFS";
	if (nama.length()<=256){
		for (int i=0;i<nama.length();i++){
			namaPartisi[i] = nama[i];
		}
		for (int i=nama.length();i<256;i++){
			namaPartisi[i] = '\0';
		}
	}
	else {
		for (int i=0;i<256;i++){
			namaPartisi[i] = nama[i];
		}
	}
	jumlahByte = 1024;
	filesystemCapacity = capacity;
	freeBlock = _free;
	firstIdxBlock = _first;
	for (int i = 0; i<740; i++){
		reserved[i]='0';
	}
	reserved[740]='\0';
	sist = "SIST";
}

void VolumeInformation::setNama(string nama){
	if (nama.length()<=256){
		for (int i=0;i<nama.length();i++){
			namaPartisi[i] = nama[i];
		}
		for (int i=nama.length();i<256;i++){
			namaPartisi[i] = '\0';
		}
	}
	else {
		for (int i=0;i<256;i++){
			namaPartisi[i] = nama[i];
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
