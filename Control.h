//Component.h

#ifndef __COMPONENT_H_INCLUDED__   // if x.h hasn't been included yet...
#define __COMPONENT_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <windows.h>
#include <iostream>
#include "Graphics.h"
#include <vector>
using namespace std;

enum class BorderType { Single, Double, None };
class CONTROL{
private:
	
protected:
	static CONTROL* focus;
	static vector<CONTROL*> controlsList;
	CONTROL * parent;
	COORD _position;
	COORD _size;
	string value;
	BorderType bt;
	Color bc;
	Color fc;
	Graphics  graphics;
	int z_index; 
	COORD cursor;
public:
	CONTROL(string, int, int, int, int);
	~CONTROL();
	virtual void mousePressed(int, int, unsigned long);
	virtual void keyDown(unsigned short,char);
	static void getAllControls(vector<CONTROL*>*);
	static CONTROL* getFocus();
	static void setFocus(CONTROL&);
	virtual bool canGetFocus();
	virtual void draw(Graphics, int, int, size_t);
	virtual void drawFrame(Graphics, int, int);
	virtual int getLeft();
	virtual int getTop();
	COORD getCursor();
	void setCursor(COORD);
	void showCursorOnScreen();
	string getValue();
	int getZIndex();
	void setZIndex(int);
	void setPosition(int, int);
	int getWidth();
	int getHeight();
	void SetVisibility(bool);
	void SetForeground(Color);
	void SetBackground(Color);
	void SetBorder(BorderType);
	void setGraphics();
	CONTROL& GetParent();
	void SetParent(CONTROL&);
	bool CONTROL::isClicked(int,int);
};


#endif a