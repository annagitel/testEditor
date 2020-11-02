// Created by asandler on 10/31/20.

#include "Editor.h"
#include<iostream>
#include<string>

using namespace std;
Editor::Editor() {}
Editor::Editor(string s):ed(s) {}
Editor::~Editor() {}
void Editor::loop(){

    string input="";

    while(getline(cin,input)){
		char s = input.at(0);
		switch (s) {
			case 'q':
				return;
				case '0': case '1':case '2': case '3':case '4': case '5':case '6': case '7':case '8': case '9':{
					this->ed.changeCurrentLine(stoi(input));
					break;
				}
			case '+':{
				this->ed.xlinesForward(stoi(input.substr(1,input.size()-1)));
				break;
			}
			case '-':{
				this->ed.xlinesBack(stoi(input.substr(1,input.size()-1)));
				break;
			}
			case '$': {
				this->ed.lastLine();
				break;
			}
			case 'a':{
				this->ed.addAfterCurrent();
				break;
			}
			case 'i':{
				this->ed.addBeforeCurrent();
				break;
			}
			case 'c':{
				this->ed.changeCurrent();
				break;
			}
			case 'd':{
				this->ed.deleteCurrent();
				break;
			}
			case '/':{
				this->ed.search(input.substr(1,input.size()-2));
				break;
			}
			case 's':{
				cout << "sending : " << input.substr(2,input.size()-3) << endl;
				this->ed.replaceText(input.substr(2,input.size()-3));
				break;
			}
			case 'j':{
				this->ed.combine();
				break;
			}
			case 'w': {
				this->ed.writeToFile(input.substr(2,input.size()-1));
				break;
			}
		}

    }

}

