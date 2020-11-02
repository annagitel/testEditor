//
// Created by asandler on 10/31/20.
//

#pragma once
#include"Document.h"
#include <string>
class Editor{

    private:
        Document ed;

    public:
		Editor();
		Editor(string);
		~Editor();
        void loop();

};