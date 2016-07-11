#include "MessageBox.h"

MessageB::MessageB(int height, int width) : Panel(height, width + 2), _accept(8), _cancele(8), _title(width), _text(width), _acceptListener(*this), _cancelListener(*this) {
	setBorderosition(BorderType::Single);
	
	_accept.setText("accept");
	_accept.setBorderosition(BorderType::Single);
	_accept.addListener(_acceptListener);
	_accept.setWidth(_accept.getText().size());
	this->addControl(_accept,width/2+2 , height-2);

	_cancele.setText("cancel");
	_cancele.setBorderosition(BorderType::Single);
	_cancele.addListener(_cancelListener);
	_cancele.setWidth(_cancele.getText().size());
	this->addControl(_cancele, width /2-8, height - 2);

	this->addControl(_title, 2, 1);
	this->addControl(_text, 2,  3);
}


MessageB::~MessageB() {;
}
void MessageB::setLayer(size_t layer){
	Panel::setLayer(4);
}
void MessageB::setTitle(string title) {
	_title.setText(title);
}
void MessageB::setText(string text) {
	_text.setText(text);
}
bool MessageB::canGetFocus() {
	return false;
}

void MessageB::draw(Graphics& graphics, int x, int y, size_t layer){
	Control::draw(graphics,x,y,layer);
	Panel::draw(graphics, x, y, layer+1);
	if (getVisibility())
	Control::setFocus(this);
}

void MessageB::mousePressed(int x, int y, bool isLeft){

}

void MessageB::keyDown(int code, char ch){

}
