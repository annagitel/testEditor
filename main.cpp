#include <iostream>
#include "Editor.h"

int main(int argc, char* argv[]) {
	if (argc ==1 ){
		Editor editor;
		editor.loop();
		return 0;
	}

	else if (argc == 2){
		Editor editor(argv[1]);
		editor.loop();
		return 0;
	}
}
