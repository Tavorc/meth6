//Component.h

#ifndef __COMPONENT_H_INCLUDED__   // if x.h hasn't been included yet...
#define __COMPONENT_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <windows.h>
#include <iostream>
#include "Graphics.h"
#include <vector>
using namespace std;

enum class BorderType { Single, Double, None};

class CONTROL{
private:
	
protected:
	static CONTROL * focus;
	COORD _position;
public:
	CONTROL();
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short,char);
	void getAllControls(vector<CONTROL*>*);
	static CONTROL*  getFocus();
	static void setFocus(CONTROL);
	bool canGetFocus();
	void draw(Graphics, int, int, size_t);
	int getLeft();
	int getTop();
};

#endif a