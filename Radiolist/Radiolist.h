#pragma once

#include "../CheckList/CheckList.h"

class Radiolist : public Checklist{
private:
	int mark;

public:
	Radiolist(int width, int height, vector <string> list);
	virtual ~Radiolist();
	void draw(Graphics& graphics, int x_relative, int y_relative, size_t layer);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int code, char ch);
	virtual bool canGetFocus() const;
};