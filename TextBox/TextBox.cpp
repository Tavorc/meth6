#include "TextBox.h"

TextBox::TextBox(int width) : Control(width) {
	_cursor = { GetLeft() + GetText().length() + 1, getTop() + 1 };

}

TextBox::~TextBox() {

}

void TextBox::draw(Graphics& g, int x, int y, size_t layer) {
	//g.setBackground(GetBackgroundColor());
	//g.setForeground(GetForegroundColor());
	Control::draw(g, x, y, layer);
	if (GetBorder() != BorderType::None) g.write(GetLeft() + 1, getTop() + 1, GetText());
	else {
		g.write(GetLeft(), getTop(), GetText());
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft) {
	if (isClicked(x,y) && y-1==getTop() && x > GetLeft()){
		this->_cursor.X = x;
		this->_cursor.Y = y;
	}
}

void TextBox::keyDown(int code, char ch) {
	COORD crd;
	crd.Y = _cursor.Y;
	crd.X = _cursor.X;
	Graphics().moveTo(this->_position.X + 1, this->_position.Y + 1);

	if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122) || (code >= 48 && code <= 57) || (code == 32))
	{
		if (this->GetText().length() < this->_position.X - 6 || this->GetText().length() == this->_position.X - 6)
		{
			string a = this->GetText() + string(1, ch);
			this->SetText(a);
			crd.X++;
			_cursor = (crd);
		}
	}
	COORD coord;
	string temp;
	coord.Y = _cursor.Y;
	switch (code){
	case VK_BACK:
		coord.X = _cursor.X - 1;
		_cursor = (coord);
		temp = GetText();
			temp.erase(coord.X - _position.X - 1, 1);
		SetText(temp);
			break;
	case VK_RIGHT:
	case VK_NUMPAD6:
		
		temp = GetText();
		if (_cursor.X< this->_position.X + GetWidth())
		{
			coord.X = _cursor.X + 1;
			_cursor = (coord);
		}
		break;
	case VK_LEFT:
	case VK_NUMPAD4:
		if (_cursor.X>this->_position.X+1)
		{
			coord.X = _cursor.X - 1;
			_cursor = (coord);
		}	
		break;
	case VK_RETURN:
		break;
	case VK_DELETE:
		coord.X = _cursor.X - 1;
		
		temp = GetText();
		if (coord.X <temp.length() + _position.X )
		{
			temp.erase(coord.X - _position.X+1, 1);
			_cursor = (coord);
		}
		SetText(temp);
		break;
	default:
		break;
		}
	}

bool TextBox::canGetFocus() const {
	return true;
}
void TextBox::Clear(){
	for (int i = this->_position.X; i < this->_position.X + this->GetText().length(); i++){
		SetCursor(i, this->_position.Y);
		printf("%c", ' ');
	}
}
