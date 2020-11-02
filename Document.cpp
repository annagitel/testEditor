// Created by asandler on 10/31/20.
#include "Document.h"
#include <iostream>
#include <fstream>
using namespace std;

Document::Document(){
	this->currentLine = 0;
	cout << "default:document is inited with " << this->doc.size() << endl;
}

Document::Document(string filename) {
	std::ifstream infile(filename);
	std::string line;
	while (std::getline(infile, line)){
		doc.push_back(line);
	}
	this->currentLine = doc.size()-1;
	cout << "with file: document is inited with " << this->doc.size() << endl;
}

Document::~Document(){}

void Document::changeCurrentLine(int newLine){
	this->currentLine = newLine-1 ;
	cout << "now on line: " << this->currentLine+1 << endl;
}

void Document::xlinesForward(int x){
	this->currentLine = this->currentLine + x;
	cout << "now on line: " << this->currentLine+1 << endl;
}

void Document::xlinesBack(int x){
	this->currentLine = this->currentLine - x;
	cout << "now on line: " << this->currentLine+1 << endl;
}

void Document::lastLine(){
	this->currentLine = doc.size()-1;
	cout << "now on line: " << this->currentLine+1 << endl;
}

void Document::addAfterCurrent(){
	string in = "";
    while (getline(cin, in)){

        if(in.compare(".") == 0)
            break;

        if(this->doc.size() == 0)
            this->doc.push_back(in);

        else // insert after
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

        else // insert before
            this->doc.insert(this->doc.begin() + this->currentLine, in);
        this->currentLine++;
    }
	cout << "now on line: " << this->currentLine+1 << endl;
}

void Document::changeCurrent(){
	this->doc.erase(this->doc.begin() + this->currentLine);
    addAfterCurrent();
	cout << "now on line: " << this->currentLine+1 << endl;
}
void Document::deleteCurrent(){
	this->doc.erase(this->doc.begin()-1 + this->currentLine--);
	cout << "now on line: " << this->currentLine+1 << endl;
}
void Document::search(string s){
	for(auto it = this->doc.begin() + this->currentLine ; it != this->doc.end(); ++it){

        string line = *it;
        auto find = line.find(s);

         if(find != string::npos){
            cout << *it << endl;
            this->currentLine = distance(this->doc.begin(), it) ;
            cout << "now on line: " << this->currentLine+1 << endl;
            return;
        }
    }
	for(auto it = this->doc.begin() ; it != this->doc.begin() + this->currentLine; ++it){
        string word = *it;
        auto find = word.find(s);
        if(find != string::npos){
            cout << *it << endl;
            this->currentLine = distance(this->doc.begin(), it) ;
			cout << "now on line: " << this->currentLine+1 << endl;
            return;
        }
    }
    this->currentLine = 1;
}
void Document::replaceText(string s){
	string olds = s.substr(0,s.find("/"));
	cout << "old word " << olds << endl;
	string news = s.substr(s.find("/")+1, s.size() - 1);
	cout << "new word " << news << endl;
	this->doc.at(currentLine).replace(this->doc.at(currentLine).find(olds), olds.size(), news);
}
void Document::combine(){
	string s = "";
	doc[currentLine].append(doc[currentLine+1]);
	this->doc.erase(this->doc.begin() + this->currentLine+1);
}
void Document::writeToFile(string filename){
	std::ofstream outFile(filename);
	for (const auto &e : doc) outFile << e << "\n";
}