#include "Control.h"

CONTROL* CONTROL::focus = 0;
vector<CONTROL*> CONTROL::controlsList;

CONTROL::CONTROL(string str, int x, int y, int width, int height){
	this->value = str;
	this->_position.X = x;
	this->_position.Y = y;
	this->_size.X = width;
	this->_size.Y = height;
	this->bt = BorderType::Double;
	this->bc = Color::Red;
	this->fc = Color::Green;
	this->controlsList.push_back(this);
	this->z_index = -1;
}
CONTROL::~CONTROL(){
}
string CONTROL::getValue(){
	return this->value;
}
CONTROL*  CONTROL::getFocus(){
	return focus;
}
void CONTROL::setFocus(CONTROL&c){
	 focus = &c;
}
void CONTROL::mousePressed(int x, int y, unsigned long button){
}
void CONTROL::keyDown(unsigned short, char){
}
// Gets all the control that been created
void CONTROL::getAllControls(vector<CONTROL*>* vc){
	std::vector<CONTROL*> a(CONTROL::controlsList);
	*vc = a;
}
bool CONTROL::canGetFocus(){
	return false;
}
void CONTROL::setPosition(int x, int y){
	this->_position.X = x;
	this->_position.Y = y;
}
void CONTROL::draw(Graphics g, int x, int y, size_t p){

}
int CONTROL::getLeft(){
	return _position.X;
}
int CONTROL::getTop(){
	return _position.Y;
}
// Determines whether the control is in the click area
bool CONTROL::isClicked(int x, int y){
	for (int i = this->_position.Y; i < this->_position.Y + this->_size.Y + 1;i++){
		for (int j = this->_position.X; j < this->_position.X + this->_size.X + 1;j++){
			if (i == y && j == x){
				return true;
			}
		}
	}
	return false;
}

// Gets the panel that contains this control
CONTROL& CONTROL::GetParent(){
	return *this->parent;
}
//Sets the panel that contains this control
void CONTROL::SetParent(CONTROL& c){
	this->parent = &c;
}
// Gets the layer of this control
int CONTROL::getZIndex(){
	return this->z_index;
}
// Sets the layer of this control
void CONTROL::setZIndex(int z_index){
	this->z_index = z_index;

}
int CONTROL::getWidth(){
	return _size.X;
}
int CONTROL::getHeight(){
	return _size.Y;
}
void CONTROL::SetBorder(BorderType bt){
	this->bt = bt;
}
void CONTROL::setGraphics(){
	graphics.setBackground(bc);
	graphics.setForeground(fc);
}
// Gets x/y position and draw a frame by height and width of this control 
void CONTROL::drawFrame(Graphics graphics, int x, int y){
	for (int i = 0; i <this->_size.Y; i++){
		for (int j = 0; j < this->_size.X; j++){
			graphics.moveTo(x + j, y + i);
			// first line
			if (i == 0){
				if (j == 0){
					//top-left
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xDA");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xC9");
					}
				}
				else if (j == this->_size.X - 1){
					//top-right
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xBF");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xBB");
					}
				}
				else{
					// top-middle
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xC4");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xCD");
					}
				}
			}

			// center lines
			else if (i > 0 && i < _size.Y - 1){
				if (j == 0 || (j == this->_size.X - 1)){
					//middle-left
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xB3");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xBA");
					}
				}
				else{
					// middle-middle
					graphics.write(" ");
				}
			}
			else if (true){
				if (j == 0){
					//bottom-left
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xC0");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xC8");
					}
				}
				else if (j == this->_size.X - 1){
					//bottom-right
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xD9");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xBC");
					}
				}
				else{
					// bottom-middle
					if (bt == BorderType::None){
						graphics.write(" ");
					}
					else if (bt == BorderType::Single){
						graphics.write("\xC4");
					}
					else if (bt == BorderType::Double){
						graphics.write("\xCD");
					}
				}
			}
		}
	}
}