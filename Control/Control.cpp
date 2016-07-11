#include "Control.h"

Control::Control(int width) : _width(width), _height(1), _bgColor(BackgroundColor::Black), _fgColor(ForegroundColor::White),
_isVisible(true), _layer(0), _border(BorderType::None), _position({ 0, 0 }) {
	controlsList.push_back(this);
	this->_layer = 0;
}

Control::~Control() {

}

void Control::setCursor(int x, int y){
	_cursor.X = x;
	_cursor.Y = y;
}

void Control::setText(string value){
	_value = value;
}

void Control::setWidth(int width) {
	_width = width;
}

void Control::setHeight(int height) {
	_height = height;
}

void Control::setVisibility(bool visibility) {
	if (visibility) show();
	else hide();
}

void Control::setLayer(size_t layer) {
	_layer = layer;
}

void Control::setPosition(COORD position) {
	_position = position;
}

void Control::setBackground(Color background) {
	_bgColor = (BackgroundColor)background;
}

void Control::setForeground(Color foreground) {
	_fgColor = (ForegroundColor)foreground;
}

void Control::setBorderosition(BorderType border) {
	_border = border;
}

void Control::setFocus(Control* c){
	focus = c;
}
//find the cursor and show it
void Control::showCursorOnScreen(Graphics & graphics) {
	graphics.moveTo(getFocus()->_cursor.X, getFocus()->_cursor.Y);
	graphics.setCursorVisibility(isCursorable());
}

void Control::show() {
	_isVisible = true;
	_layer = 5;
}

void Control::hide() {
	_isVisible = false;
	_layer = 0;
}

// Determines whether the control is in the click area
bool Control::isClicked(int x, int y){
	for (int i = this->_position.Y; i < this->_position.Y + this->_height + 1; i++){
		for (int j = this->_position.X; j < this->_position.X + this->_width + 1; j++){
			if (i == y && j == x){
				return true;
			}
		}
	}
	return false;
}

vector<Control*> Control::getControls() const{
	return controlsList;
}

int Control::getWidth() const {
	return _width;
}
int Control::getHeight() const {
	return _height;
}

bool Control::getVisibility() const {
	return _isVisible;
}

string Control::getText() const{
	return _value;
}

size_t Control::getLayer() const {
	return _layer;
}

COORD Control::getPosition() const {
	return _position;
}

BorderType Control::getBorder() const {
	return _border;
}

Control* Control::getFocus() {
	return focus;
}

BackgroundColor Control::getBackgroundColor() const {
	return _bgColor;
}

ForegroundColor Control::getForegroundColor() const {
	return _fgColor;
}

void Control::draw(Graphics &g, int left, int top, size_t layer) {
	if (_layer == layer){
		if (_border != BorderType::None) drawBorder(g, left, top, layer);
	}
}
//check if the control can get focus
bool Control::canGetFocus() const {
	return false;
}

bool Control::canClicked() const {
	return false;
}

bool Control::isCursorable(){
	return false;
}

int Control::GetLeft() const {
	return _position.X;
}

int Control::getTop() const {
	return _position.Y;
}
//draw the border of the control
void Control::drawBorder(Graphics& g, int x, int y, size_t layer) {
	x += _position.X;
	y += _position.Y;
	g.moveTo(x, y);
	g.setForeground((Color)getForegroundColor());
	g.setBackground((Color)getBackgroundColor());
	g.write(string(1, _border == BorderType::Single ? S_TOP_LEFT_CHAR : D_TOP_LEFT_CHAR));
	g.write(string(_width, _border == BorderType::Single ? S_VERT_CHAR : D_VERT_CHAR));
	g.write(string(1, _border == BorderType::Single ? S_TOP_RIGHT_CHAR : D_TOP_RIGHT_CHAR));

	for (int i = 0; i < _height; i++) {
		g.write(x, y + 1 + i, string(1, _border == BorderType::Single ? S_HORZ_CHAR : D_HORZ_CHAR));
		g.write(string(_width, ' '));
		g.write(string(1, _border == BorderType::Single ? S_HORZ_CHAR : D_HORZ_CHAR));
	}

	g.write(x, y + _height + 1, string(1, _border == BorderType::Single ? S_BOTTOM_LEFT_CHAR : D_BOTTOM_LEFT_CHAR));
	g.write(string(_width, _border == BorderType::Single ? S_VERT_CHAR : D_VERT_CHAR));
	g.write(string(1, _border == BorderType::Single ? S_BOTTOM_RIGHT_CHAR : D_BOTTOM_RIGHT_CHAR));

	g.moveTo(x + _width, y + _height + 1);
}