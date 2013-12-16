#include "volume_information.h"
#include "sister_allocation_table.h"
#include "root_directory.h"
#include "data_pool.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

#include "params.h"
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>

using namespace std;

VolumeInformation vi;
SisterAllocationTable sat;
RootDirectory rd;
vector <DataPool> dp;

void readFile(char* file){
	dp.clear();
	string line;
	string whole = "";
  	ifstream myfile (file);
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
      		whole = whole + line;
    	}
    	myfile.close();
    	//cout << whole.length() << endl;
	  	// Volume Information
	  	string svi = "";
	  	for (int i=0;i<1024;i++){
			svi = svi + whole[i];
		}
		vi.load(svi);
		//cout << svi.length() << endl;
		//cout << svi << endl;
	  	// Sister Allocation Table
		string ssat = "";
		int offset = 1024;
	  	for (int i=0;i<128*1024;i++){
			ssat = ssat + whole[offset+i];
		}
		sat.load(ssat);
		//cout << ssat.length() << endl;
		//cout << ssat << endl;
	  	// Root Directory
		string srd = "";
		offset+= 128*1024;
	  	for (int i=0;i<1024;i++){
			srd = srd + whole[offset+i];
		}
		rd.load(srd);
		//cout << srd.length() << endl;
		//cout << srd << endl;
	  	// Data Pool
		offset+=1024;
		int idxx = 0;
		while (offset < whole.length()){
		  	string sdp = "";
		  	for (int i=offset;i<whole.length();i++){
				sdp = sdp + whole[i];
			}
			DataPool dpt;
			dpt.load(sdp);
			dp.push_back(dpt);
			//cout << sdp.length() << endl;
			//cout << idxx << " " << sdp << endl;
			idxx++;
			offset+=32;
		}
		cout << whole.length() << endl;
	}
  	else 
  		cout << "Unable to open file"; 
}

void writeFile(char* file){
	string whole;
	ofstream myfile (file);
	if (myfile.is_open()){
		//cout << "write1" << endl;
		whole = whole + vi.toString();
		//cout << vi.toString().length() << endl;
		//cout << "write2" << endl;		
		whole = whole + sat.toString();
		//cout << sat.toString().length() << endl;
		//cout << "write3" << endl;
		whole = whole + rd.toString();
		//cout << rd.toString().length() << endl;
		//cout << "write4" << endl;
		for (int i=0;i<dp.size();i++){
			//cout << "write5" << i << endl;
			whole = whole + dp[i].toString();
			//cout << dp[i].toString().length() << endl;
		}
		cout << whole.length() << endl;
		//cout << endl;
		//cout << endl;
		myfile << whole;
		myfile.close();
	}
	else 
		cout << "Unable to open file";
}

void generateFile(string namaFile){

}



// ./LastOrder /mnt/hd/sisterfs sister.fs
// ./LastOrder /mnt/hd/sisterfs sister.fs shift

int main(int argc, char *argv[]){
	DataPool dpt;

	dp.push_back(dpt);
	writeFile("sister.fs");
	readFile("sister.fs");
	
	if (argc < 3 || argc > 4) {
		cout << "Shift failed, invalid parameter[s]" << endl;
	}
	else if (argc == 3){
		cout << "Shift success" << endl;
		cout << argv[2] << "c" << endl;
		readFile(argv[2]);
	}
	else if (argc == 4){
		if (strcmp(argv[3],"shift") == 0){
			cout << "Shift success" << endl;
			string str = argv[1];
			//generateFile(str);
		}
		else {
			cout << "Shift failed, invalid parameter[s]" << endl;
		}
	}
}
