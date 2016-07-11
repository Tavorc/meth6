#include "ComboBox.h"


ComboBox::ComboBox(vector <string> entries, int width) : Control(width), _entries(entries){
	_isPressed = false;
	_text = "";			//set default choice 
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

	graphics.setForeground((Color)getForegroundColor());
	graphics.setBackground((Color)getBackgroundColor());

	if (getFocus() != this) _isPressed = false;
	if (_isPressed) {
		setHeight(_entries.size() + 1);
		// draw frame of control
		Control::draw(graphics, 0, 0, layer);
		graphics.write(_position.X + 1, _position.Y + 1, _text);
		// init position
		for (int option = 0; option < _entries.size(); option++){
			if (_selectedIndex == option){
				graphics.setForeground((Color)getBackgroundColor());
				graphics.setBackground((Color)getForegroundColor());
			}
			graphics.write(_position.X + 1, _position.Y + 2 + option, _entries[option]);
			graphics.setForeground((Color)getForegroundColor());
			graphics.setBackground((Color)getBackgroundColor());
		}
	}
	else{
		setHeight(1);
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
			setLayer(1);
		}
		else{
			//open the options box
			_isPressed = true;
			setLayer(2);
		}
	}
	else if (_isPressed){
		_isPressed = false;
		setLayer(1);
	}
}

void ComboBox::keyDown(int code, char ch){
	//if the box is already open
	if (_isPressed){
		//enter key pressed - close box
		if (code == VK_RETURN || code == VK_SPACE){
			setHeight(1);
			_isPressed = false;
			setLayer(1);
		}
		//down arrow key pressed - go to next option
		else if (code == VK_DOWN || code == VK_NUMPAD8){
			_selectedIndex++;
			if (_selectedIndex == _entries.size()) _selectedIndex = 0;
			_text = _entries[_selectedIndex];
		}
		//up arrow key pressed - go to previous option
		else if (code == VK_UP || code == VK_NUMPAD2){
			_selectedIndex--;
			if (_selectedIndex == -1) _selectedIndex = _entries.size() - 1;
			_text = _entries[_selectedIndex];
		}
	}
	//if the options box is closed
	else{
		//enter key opens the box
		if (code == VK_RETURN || code == VK_SPACE){
			setLayer(2);
			setHeight(_entries.size() + 1);
			_isPressed = true;
		}

	}
}