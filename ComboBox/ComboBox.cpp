#include "ComboBox.h"


ComboBox::ComboBox(vector <string> entries, int width) : Control(width), _entries(entries){
	_isPressed = false;
	_text = entries[0];			//set default choice as option #1 
	_selectedIndex = -1;
}

ComboBox::~ComboBox(){

}

bool ComboBox::canGetFocus() const {
	return true;
}

size_t ComboBox::getSelectedIndex(){
	return _selectedIndex;
}
void ComboBox::setSelectedIndex(size_t index){
	_selectedIndex = index;
}

void ComboBox::draw(Graphics& graphics, int x_relative, int y_relative, size_t layer){
	// change color of textbox in focus
	/*if (this == focus)
	{
		graphics.setBackground(Color::White);
		graphics.setForeground(Color::Black);
	}*/

	if (_isPressed) {
		SetHeight(_entries.size() + 1);
		// draw frame of control
		Control::draw(graphics, 0, 0, layer);
		graphics.write(_position.X + 1, _position.Y + 1, _text);
		// init position
		for (int option = 0; option < _entries.size(); option++){
			graphics.write(_position.X + 1, _position.Y + 2 + option, _entries[option]);
		}
	}
	else{
		SetHeight(1);
		// draw frame of control
		Control::draw(graphics, 0, 0, layer);
		graphics.write(_position.X + 1, _position.Y + 1, _text);
	}
	graphics.setCursorVisibility(false);

}

void ComboBox::mousePressed(int x, int y, bool isLeft){
	if (isClicked(x, y)){
		//if the box is already open
		if (_isPressed){
			int pos = (y - _position.Y) - 2;
			if (pos >= 0){
				_text = _entries[pos];
				_selectedIndex = pos;
			}
			//close the options box
			_isPressed = false;
		}
		else{
			//open the options box
			_isPressed = true;
		}
	}
	else if (_isPressed) _isPressed = false;
}

void ComboBox::keyDown(int code, char ch){
	//if the box is already open
	if (_isPressed){
		//enter key pressed - close box
		if (code == VK_RETURN){
			SetHeight(1);
			_isPressed = false;
		}
		//down arrow key pressed - go to next option
		else if (code == VK_DOWN){
			_selectedIndex++;
			if (_selectedIndex == _entries.size()) _selectedIndex = 0;
			_text = _entries[_selectedIndex];
		}
		//up arrow key pressed - go to previous option
		else if (code == VK_UP){
			_selectedIndex--;
			if (_selectedIndex == -1) _selectedIndex = _entries.size() - 1;
			_text = _entries[_selectedIndex];
		}
	}
	//if the options box is closed
	else{
		//enter key opens the box
		if (code == VK_RETURN){
			SetHeight(_entries.size() + 1);
			_isPressed = true;
		}

	}
}