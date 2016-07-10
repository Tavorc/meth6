#pragma once

#include "../Control/Control.h"


struct Row{
private:
	string text;
	boolean isChecked;
public:
	Row(string r, boolean b);
	~Row();
	string getText(){ return text; };
	boolean getIsChecked(){ return isChecked; };
	void setIsChecked(boolean a){ isChecked = a; }
};

class Checklist : public Control
{
private:
	vector <Row> ar;
	int focusedRow;
protected:

public:
	Checklist(int width, int height, vector <string> list);
	virtual ~Checklist();
	void draw(Graphics& graphics, int x_relative, int y_relative, size_t layer);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int code, char ch);
	virtual bool canGetFocus() const;
	int getFocusedRow(){ return focusedRow; }
	void setFocusedRow(int f){ focusedRow = f; }
	vector <Row> getAr(){ return ar; }
	void selectIndex(int a);

};