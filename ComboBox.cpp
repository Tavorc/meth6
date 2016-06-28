#include "ComboBox.h"

vector<string> arr = { "Num1", "Num2", "Num3", "Num4" }; //drop down options
bool isPressed = false;									//indicates if the options are open
int selectedCell = -1;									//indicates which optiion is selected

ComboBox::ComboBox(string str, int x, int y, int width, int height) : CONTROL(str, x, y, width, height){
}

ComboBox::~ComboBox(){

}

bool ComboBox::canGetFocus(){
	return true;
}

void ComboBox::draw(Graphics graphics, int x_relative, int y_relative, size_t p){
	//set graphics
	this->graphics = graphics;
	graphics.setBackground(bc);
	graphics.setForeground(fc);
	// change color of textbox in focus
	if (this == focus)
	{
		graphics.setBackground(Color::White);
		graphics.setForeground(Color::Black);
	}
	// init position
	int xAbs = this->_position.X + x_relative,
		yAbs = this->_position.Y + y_relative;

	if (isPressed) {
		_size.Y = arr.size() + 3;
		// draw frame of control
		drawFrame(graphics, xAbs, yAbs);
		graphics.moveTo(this->_position.X + 1, this->_position.Y + 1);
		graphics.write(this->getValue());
		// init position
		for (int option = 0; option < arr.size(); option++){
			graphics.moveTo(xAbs + 1, yAbs + 2 + option);
			graphics.write(arr[option]);
		}
	}
	else{
		_size.Y = 3;
		// draw frame of control
		drawFrame(graphics, xAbs, yAbs);
		graphics.moveTo(this->_position.X + 1, this->_position.Y + 1);
		graphics.write(this->getValue());
	}
	graphics.setCursorVisibility(false);

}

void ComboBox::mousePressed(int x, int y, unsigned long button){
	//if the box is already open
	if (isPressed){		
		int pos = (y - _position.Y) - 2;
		if (pos >= 0){
			value = arr[pos];
			selectedCell = pos;
		}
		//close the options box
		isPressed = false;		
	}
	else{
		//open the options box
		isPressed = true;		
	}
}

void ComboBox::keyDown(unsigned short code, char ch){
	//if the box is already open
	if (isPressed){
		//enter key pressed - close box
		if (code == VK_RETURN){
			_size.Y = 3;
			drawFrame(graphics, _position.X, _position.Y);
			isPressed = false;
		}
		//down arrow pressed - go to next option
		else if (code == VK_DOWN){
			selectedCell++;
			if (selectedCell == arr.size()) selectedCell = 0;
			value = arr[selectedCell];
		}
		//up arrow pressed - go to previous option
		else if (code == VK_UP){
			selectedCell--;
			if (selectedCell == -1) selectedCell = arr.size() - 1;
			value = arr[selectedCell];
		}
	}
	//if the options box is closed
	else{
		//enter key opens the box
		if (code == VK_RETURN){
			_size.Y = arr.size() + 3;
			drawFrame(graphics, _position.X, _position.Y);
			for (int option = 0; option < arr.size(); option++){
				graphics.moveTo(_position.X + 1, _position.Y + 2 + option);
				graphics.write(arr[option]);
			}
			isPressed = true;
		}

	}
}