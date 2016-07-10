#include "CheckList.h"
#include <Windows.h>
#include <stdio.h>
Row::Row(string r, boolean b){
	text = r;
	isChecked = b;
}

Row::~Row(){

}


Checklist::Checklist(int width, int height, vector <string> list) : Control(width){
	focusedRow = 0;
	Row *temp;
	int max = width;
	for (int i = 0; i < list.size(); i++)
	{
		if (max < list[i].length() + 6) { max = list[i].length() + 6; }
		temp = new Row(list[i], false);
		ar.push_back(*temp);
	}

	setWidth(max);
}

Checklist::~Checklist(){
	//delete ar;
}




bool Checklist::canGetFocus() const { return true; }

void Checklist::draw(Graphics& graphics, int x_relative, int y_relative, size_t layer){

	graphics.setForeground((Color)getForegroundColor());
	graphics.setBackground((Color)getBackgroundColor());

	setHeight(ar.size());

	Control::draw(graphics, 0, 0, layer);

	for (int i = 0; i < ar.size(); i++)
	{
		graphics.write(_position.X + 1, _position.Y + 1 + i, "  [ ] " + ar[i].getText());

		if (ar[i].getIsChecked() == TRUE)
		{
			graphics.moveTo(_position.X + 4, _position.Y + i + 1);
			graphics.write("*");
		}

		if (i == focusedRow){
			graphics.moveTo(_position.X + 1, _position.Y + i + 1);
			graphics.write(">");
		}
	}

}


void Checklist::mousePressed(int x, int y, bool isLeft) {

	if (isClicked(x, y)){

		int pos = (y - _position.Y) - 1;
		if (pos >= 0){
			if (ar[pos].getIsChecked()){
				ar[pos].setIsChecked(false);
			}
			else{
				ar[pos].setIsChecked(true);
			}
			focusedRow = pos;
		}
	}
}

void Checklist::selectIndex(int a){
	ar[a].setIsChecked(true);
}

void Checklist::keyDown(int code, char ch) {


	if (code == VK_RETURN){
		ar[focusedRow].getIsChecked() ? ar[focusedRow].setIsChecked(false) : ar[focusedRow].setIsChecked(true);
	}

	else if (code == VK_DOWN){
		if (focusedRow == ar.size() - 1){
			focusedRow = 0;
		}
		else{ focusedRow++; }


	}


	else if (code == VK_UP){
		if (focusedRow == 0){
			focusedRow = ar.size() - 1;
		}
		else{ focusedRow--; }
	}
}