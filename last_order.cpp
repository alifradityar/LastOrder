#include "volume_information.h"
#include "sister_allocation_table.h"
#include "root_directory.h"
#include "data_pool.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

VolumeInformation vi;
SisterAllocationTable sat;
//RootDirectory rd;
//DataPool dp;

void readFile(char* file){
  string line;
  ifstream myfile (file);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}

void writeFile(char* file,string content){
  ofstream myfile (file);
  if (myfile.is_open())
  {
    myfile << content;
    myfile.close();
  }
  else cout << "Unable to open file";
}

void generateFile(string namaFile){

}

// ./LastOrder /mnt/hd/sisterfs sister.fs
// ./LastOrder /mnt/hd/sisterfs sister.fs shift

int main(int argc, char *argv[]){
	
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
