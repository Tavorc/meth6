#include "Control.h"

CONTROL::CONTROL(){
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
void CONTROL::draw(Graphics, int, int, size_t){
}
int CONTROL::getLeft(){
	return 0;
}
int CONTROL::getTop(){
	return 0;
}