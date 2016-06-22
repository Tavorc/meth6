#include "Control.h"

CONTROL::CONTROL(string name){
	this->name = name;
}

 CONTROL*  CONTROL::getFocus(){
	return nullptr;
}
 void CONTROL::setFocus(CONTROL){

}
void CONTROL::mousePressed(int, int, unsigned long){

}
void CONTROL::keyDown(unsigned short, char){
}
void CONTROL::getAllControls(vector<CONTROL*>*){
}
bool CONTROL::canGetFocus(){
	return false;
}
void CONTROL::draw(Graphics graphics, int x, int y, size_t t){
	graphics.write(this->name);
}
int CONTROL::getLeft(){
	return 0;
}
int CONTROL::getTop(){
	return 0;
}