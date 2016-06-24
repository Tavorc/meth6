#include "Form.h"

Form::Form() :Panel("", 0, 0, Console::WindowWidth, Console::WindowHeight+10) {
	this->bc = Color::White;
	this->fc = Color::Black;
	this->bt = BorderType::None;
	this->z_index = 0;
} 

Form::~Form(){
}
void Form::draw(Graphics g, int x, int y, size_t t){
	Panel::draw(g,x,y,t);
}
void Form::mousePressed(int, int, unsigned long){
}
void Form::keyDown(unsigned short, char){
}
bool Form::canGetFocus(){
	return false;
}