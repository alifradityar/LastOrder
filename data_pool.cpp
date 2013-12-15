#include "data_pool.h"

DataPool::DataPool(){
	for (int i=0;i<21;i++){
		namaFile = namaFile + '\0';
	}
	
	fileAtt = '0';
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string year = DecToBin(ltm->tm_year-110); 
	string month = DecToBin(ltm->tm_mon+1);
	string day = DecToBin(ltm->tm_mday);
	string hour = DecToBin(ltm->tm_hour);
	string min = DecToBin(ltm->tm_min);
	string sec = DecToBin(ltm->tm_sec/2);
	string clockRes = checkBin(hour,"hour") + checkBin(min,"minute") + checkBin(sec,"second");
	string dateRes = checkBin(year,"year") + checkBin(month,"month") + checkBin(day,"day");
	
	clock = BinToDec(clockRes);
	date = BinToDec(dateRes);
	
	dir = 0;
	
	size = 0;
	
} 

DataPool::DataPool(string name, char att, short _dir, int _size){
	namaFile = name;
	for (int i=name.length();i<21;i++){
		namaFile = namaFile + '\0';
	}
	
	fileAtt = att;
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string year = DecToBin(ltm->tm_year-110); 
	string month = DecToBin(ltm->tm_mon+1);
	string day = DecToBin(ltm->tm_mday);
	string hour = DecToBin(ltm->tm_hour);
	string min = DecToBin(ltm->tm_min);
	string sec = DecToBin(ltm->tm_sec/2);
	string clockRes = checkBin(hour,"hour") + checkBin(min,"minute") + checkBin(sec,"second");
	string dateRes = checkBin(year,"year") + checkBin(month,"month") + checkBin(day,"day");
	
	clock = BinToDec(clockRes);
	date = BinToDec(dateRes);
	
	dir = _dir;
	
	size = _size;
}

void DataPool::setAtt(char att){
	fileAtt = att;
}
void DataPool::setClock(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string hour = DecToBin(ltm->tm_hour);
	string min = DecToBin(ltm->tm_min);
	string sec = DecToBin(ltm->tm_sec/2);
	string clockRes = checkBin(hour,"hour") + checkBin(min,"minute") + checkBin(sec,"second");
	clock = BinToDec(clockRes);
}
void DataPool::setDate(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string year = DecToBin(ltm->tm_year-110); 
	string month = DecToBin(ltm->tm_mon+1);
	string day = DecToBin(ltm->tm_mday);
	string dateRes = checkBin(year,"year") + checkBin(month,"month") + checkBin(day,"day");
	date = BinToDec(dateRes);
}
void DataPool::setDir(short _dir){
	dir = _dir;
}
void DataPool::setSize(int _size){
	size = _size;
}

string DataPool::DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}

int DataPool::BinToDec(string number)
{
    int result = 0, pow = 1;
    for ( int i = number.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (number[i] - '0') * pow;

    return result;
}

string DataPool::checkBin(string binary,string status){
	string zero = "0";
	//cout << "Panjang : " << binary.length() << endl;
	if (status=="hour"){
		int delta = 5-binary.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				binary = zero + binary;
			}
		}
	}else if (status=="minute"){
		int delta = 6-binary.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				binary = zero + binary;
			}
		}
	}else if (status=="second"){
		int delta = 5-binary.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				binary = zero + binary;
			}
		}
	}else if (status=="year"){
		int delta = 7-binary.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				binary = zero + binary;
			}
		}
	}else if (status=="month"){
		int delta = 4-binary.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				binary = zero + binary;
			}
		}
	}else if (status=="day"){
		int delta = 5-binary.length();
		if (delta>=0){
			for(int i=0;i<delta;i++){
				binary = zero + binary;
			}
		}
	}
	return binary;
}
