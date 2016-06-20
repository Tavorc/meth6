//Component.h
#ifndef __LABEL_H_INCLUDED__   // if x.h hasn't been included yet...
#define __LABEL_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <windows.h>
#include "Control.h"
using namespace std;


class LABEL: CONTROL{
protected:
	
public:
	 void SetForegroundColor(Color);
	 void SetBackgroundColor(Color);
	 void SetBorder(BorderType);
	 void MoveTo(int, int);
	 void Show();
	 void Hide();
	 void LABEL::Handle(INPUT_RECORD *inpt);
	 LABEL();
};

#endif 