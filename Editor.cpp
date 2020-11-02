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

    	if (input.at(0)=='q')
    		return;
    	else if (input.at(0) < '0' && input.at(0) <= '9')
    		this->ed.changeCurrentLine(stoi(input));
    	else if (input.at(0) == '+')
    		this->ed.xlinesForward(stoi(input.substr(1,input.size()-1)));
    	else if (input.at(0) == '-')
    		this->ed.xlinesBack(stoi(input.substr(1,input.size()-1)));
    	else if (input.at(0)== '$')
			this->ed.lastLine();
    	else if (input.at(0) == 'a')
    		this->ed.addAfterCurrent();
    	else if (input.at(0) == 'i')
    		this->ed.addBeforeCurrent();
    	else if (input.at(0) == 'c')
    		this->ed.changeCurrent();
    	else if (input.at(0) == 'd')
    		this->ed.deleteCurrent();
    	else if (input.at(0) == '/')
    		this->ed.search(input.substr(1,input.size()-1));
    	else if (input.at(0) == 's')
    		this->ed.replaceText(input.substr(2,input.size()-1));
    	else if (input.at(0) == 'j')
    		this->ed.combine();
    	else if (input.at(0) == 'w')
    		this->ed.writeToFile(input.substr(2,input.size()-1));

		}

}

