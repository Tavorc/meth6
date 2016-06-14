//Component.h
#ifndef __LABEL_H_INCLUDED__   // if x.h hasn't been included yet...
#define __LABEL_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <windows.h>
#include "Component.h"
using namespace std;


class LABEL: COMPONENT{
protected:
	
public:
	 void Show();
	 void Hide();
	 void SetForegroundColor(ForegroundColor);
	 void SetBackgroundColor(BackgroundColor);
	 void SetBorder(BorderType);
};

#endif 