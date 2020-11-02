// Created by asandler on 10/31/20.

#pragma once
#include<vector>
#include<string>

using namespace std;

class Document{

private:

	vector<string> doc;
	int currentLine;

public:

	Document();
	Document(string);
	~Document();

	void changeCurrentLine(int); // 3
	void xlinesForward(int);// +2
	void xlinesBack(int); // -1
	void lastLine(); //$
	void addAfterCurrent(); //a
	void addBeforeCurrent(); //i
	void changeCurrent(); // c
	void deleteCurrent(); //d
	void search(string); // /text/
	void replaceText(string);// ‫‪s/old/new/‬‬
	void combine(); // j
	void writeToFile(string); //w file
	// q is in the cpp file

};
