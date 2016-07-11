#include "MessageBox.h"
// C'tor
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

// D'tor
MessageB::~MessageB() {;
}
// Set 4 layer for messagebox 
void MessageB::setLayer(size_t layer){
	Panel::setLayer(4);
}
// Set title
void MessageB::setTitle(string title) {
	_title.setText(title);
}
// Set text
void MessageB::setText(string text) {
	_text.setText(text);
}
// is messagebox can be in focus
bool MessageB::canGetFocus() {
	return false;
}
// Draw messagebox by x,y and its children
void MessageB::draw(Graphics& graphics, int x, int y, size_t layer){
	Control::draw(graphics,x,y,layer);
	Panel::draw(graphics, x, y, layer+1);
	if (getVisibility())
	Control::setFocus(this);
}
// Mouse event
void MessageB::mousePressed(int x, int y, bool isLeft){

}
// Key Event
void MessageB::keyDown(int code, char ch){

}
