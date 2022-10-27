#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>

#include "rusinconsole.h"
using namespace std;



inline bool exists_test0 (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

inline bool exists_test1 (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

inline bool exists_test2 (const std::string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}

inline bool exists_test3 (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

std::string file_exist(bool e){
	return e ? std::string("exist") : std::string("not exist");
}

typedef bool (*PTF)(const std::string& name);




int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	string goodname("H:\\CPP\\QtPrpjects\\ProjectsCPP\\shildt\\my\\FileIO\\FileExistTest\\data\\test1.txt");
	string badname("H:\\CPP\\QtPrpjects\\ProjectsCPP\\shildt\\my\\FileIO\\FileExistTest\\data\\test2.txt");
	
	
	PTF PTFA[4];
	PTFA[0] = &exists_test0;
	PTFA[1] = &exists_test1;
	PTFA[2] = &exists_test2;
	PTFA[3] = &exists_test3;
	
	for(int i = 0; i < 4; i++){
		cout << "good file: " << file_exist((*(PTFA[i]))(goodname)) << endl;
		cout << "bad file: " << file_exist((*(PTFA[i]))(badname)) << endl;
	}
	
	return 0;
}
