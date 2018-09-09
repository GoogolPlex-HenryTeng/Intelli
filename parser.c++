#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	if(argc == 2){
		string cmds;
		string names[] = {"__DOCNAME__", "__CMDINPUT__"};
		string values[] = {argv[1], ""};
		string types[] = {"str", "str"};
		bool opened = false;
		fstream program;
		program.open(argv[1]);
		if(program.is_open()){
			while(getline(program, cmds)){
				if(cmds.find("OUT") != string::npos && cmds.find("OUT") == 0){
					for(int i = cmds.find("OUT");i < cmds.length() - 1;i++){
						if(cmds[i] == '"' && opened == true){
							opened = false;
						}
						if(opened == true){
							cout << cmds[i];
						}
						if(cmds[i] == '"' && opened == false){
							opened = true;
						}
					}
					cout << endl;
				}
				if(cmds.find("IN") != string::npos && cmds.find("IN") == 0){
					getline(cin, values[1]);
				}
				if(cmds.find("SET") != string::npos && cmds.find("SET") == 0){
					for(int i = cmds.find("SET");i < cmds.length() - 1;i++){
						if(cmds[i] != ' ' && cmds[i] != '\t' && cmds[i] != '\n' && cmds[i] != '\v' && cmds[i] != '\r' && sizeof(names) == sizeof(values)){
							names[sizeof(names)/sizeof(*names)] = cmds[i];
						}
						if(cmds[i] != ' ' && cmds[i] != '\t' && cmds[i] != '\n' && cmds[i] != '\v' && cmds[i] != '\r' && sizeof(names) > sizeof(values)){
							values[sizeof(values)/sizeof(*values)] = cmds[i];
						}
					}
				}
			}
			program.close();
		}
	}else if(argc > 2){
		cout << "<ERROR>: too much arguments";
	}else if(argc < 2){
		cout << "<ERROR>: no input files";
	}
	return 0;
}