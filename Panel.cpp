#include "Panel.h"

Panel::~Panel(){

}
Panel::Panel(string str):CONTROL(str) {
}
void Panel::AddControl(CONTROL& c){
	controls.push_back(&c);
}

