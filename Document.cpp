// Created by asandler on 10/31/20.
#include "Document.h"
#include <iostream>
#include <fstream>
using namespace std;

Document::Document(){
	currentLine = 0;
}

Document::Document(string filename) {
	currentLine = 0;
	std::ifstream infile(filename);
	std::string line;
	while (std::getline(infile, line)){
		doc.push_back(line);
	}
}

Document::~Document(){}

void Document::changeCurrentLine(int newLine){
	this->currentLine = newLine-1 ;
	cout << "now on line: " << this->currentLine << endl;
}

void Document::xlinesForward(int x){
	this->currentLine = this->currentLine + x;
	cout << "now on line: " << this->currentLine << endl;
}

void Document::xlinesBack(int x){
	this->currentLine = this->currentLine - x;
	cout << "now on line: " << this->currentLine << endl;
}

void Document::lastLine(){
	this->currentLine = doc.size();
	cout << "now on line: " << this->currentLine << endl;
}

void Document::addAfterCurrent(){
	string in = "";
		while (getline(cin, in)){
			if(in.compare(".") == 0)
				break;
			if(this->doc.size() == 0)
				this->doc.push_back(in);
			else
				this->doc.insert(this->doc.begin() + this->currentLine, in);
			this->currentLine++;
		}
}
void Document::addBeforeCurrent(){
	string in = "";
		while (getline(cin, in)){
			if(in.compare(".") == 0)
				break;
			if(this->doc.size() == 0)
				this->doc.push_back(in);
			else
				this->doc.insert(this->doc.begin() + this->currentLine -1, in);
			this->currentLine++;
		}
}

void Document::changeCurrent(){
	deleteCurrent();
	addBeforeCurrent();

}
void Document::deleteCurrent(){
	this->doc.erase(this->doc.begin()-1 + this->currentLine--);
}
void Document::search(string s){
	for(auto it = this->doc.begin() + this->currentLine -1; it != this->doc.end(); ++it){

        string line = *it;
        auto find = line.find(s);

         if(find != string::npos){
            cout << *it << endl;
            this->currentLine = distance(this->doc.begin(), it) +1;
            return;
        }
    }
    this->currentLine = this->doc.size();
	for(auto it = this->doc.begin() + this->currentLine -1; it != this->doc.begin(); --it){
        string word = *it;
        auto find = word.find(s);
        if(find != string::npos){
            cout << *it << endl;
            this->currentLine = distance(this->doc.begin(), it) +1;
            return;
        }
    }
    this->currentLine = 1;
}
void Document::replaceText(string s){
	string olds = s.substr(0,s.find("/"));
	string news = s.substr(s.find("/")+1, s.size() - olds.size() -2);
	this->doc.at(currentLine -1).replace(this->doc.at(currentLine -1).find(olds), olds.size(), news);
}
void Document::combine(){
	string s = "";
	doc[currentLine].append(doc[currentLine+1]);
	this->doc.erase(this->doc.begin() + this->currentLine--);
}
void Document::writeToFile(string filename){
	std::ofstream outFile(filename);
	for (const auto &e : doc) outFile << e << "\n";
}