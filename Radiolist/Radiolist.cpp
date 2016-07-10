#include "RadioList.h"
#include <Windows.h>
#include <stdio.h>



Radiolist::Radiolist(int width, int height, vector <string> list) : Checklist(width, height, list){
	setFocusedRow(0);
	mark = 0;

}

Radiolist::~Radiolist(){
	//delete ar;
}




bool Radiolist::canGetFocus() const { return true; }

void Radiolist::draw(Graphics& graphics, int x_relative, int y_relative, size_t layer){
	vector <Row> ar = getAr();
	graphics.setForeground((Color)getForegroundColor());
	graphics.setBackground((Color)getBackgroundColor());

	setHeight(ar.size());

	Control::draw(graphics, 0, 0, layer);

	for (int i = 0; i < ar.size(); i++)
	{
		graphics.write(_position.X + 1, _position.Y + 1 + i, "  [ ] " + ar[i].getText());

		if (mark == i)
		{
			graphics.moveTo(_position.X + 4, _position.Y + i + 1);
			graphics.write("*");
		}

		if (i == getFocusedRow()){
			graphics.moveTo(_position.X + 1, _position.Y + i + 1);
			graphics.write(">");
		}
	}

}


void Radiolist::mousePressed(int x, int y, bool isLeft) {
	int focusedRow = getFocusedRow();
	vector <Row> ar = getAr();
	if (isClicked(x, y)){
		int pos = (y - _position.Y) - 1;
		if (pos >= 0){
			mark = pos;
			setFocusedRow(mark);
			if (!ar[pos].getIsChecked()){
				ar[pos].setIsChecked(true);
			}
		}
	}
}


void Radiolist::keyDown(int code, char ch) {
	int focusedRow = getFocusedRow();
	int temp = 0;
	vector <Row> ar = getAr();
	if (code == VK_RETURN){
		mark = focusedRow;

	}

	else if (code == VK_DOWN){
		if (focusedRow == ar.size() - 1){
			focusedRow = 0;
			setFocusedRow(focusedRow);
		}
		else{
			focusedRow++;
			setFocusedRow(focusedRow);
		}


	}


	else if (code == VK_UP){
		if (focusedRow == 0){

			setFocusedRow(ar.size() - 1);
		}
		else{
			focusedRow--;
			setFocusedRow(focusedRow);
		}
	}
}