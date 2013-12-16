#include "root_directory.h"

RootDirectory::RootDirectory(){
	Entry entry;
	for (int i=0;i<32;i++){
		data.push_back(entry);
	}
} 

string RootDirectory::toString(){
	//cout << "data size : " << data.size() << endl;
	string str = "";
	for (int i=0;i<data.size();i++){
		str = str + data[i].toString();
	}
	return str;
}

void RootDirectory::load(string str){
	int offset = 0;
	string s = "";
	while (offset < 1024){
		for (int i=0;i<32;i++){
			s = s + str[offset+i];
		}
		Entry entry;
		entry.load(s);
		offset+=32;
	}
}
