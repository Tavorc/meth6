//Form.h

#ifndef __FORM_H_INCLUDED__   // if x.h hasn't been included yet...

#define __FORM_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include "Control.h"
#include <vector>

class ENGINE {
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	char value[100];
	int valLength = 0;
	void ENGINE::ErrorExit(LPSTR lpszMessage);
	vector<CONTROL*> comps;
	int currentComponnent = 0;
	bool NextEditableComponent(int start);

public:
	ENGINE();
	void Add(CONTROL*);
	void Run();
	void Handle(INPUT_RECORD *inpt);
};
#endif