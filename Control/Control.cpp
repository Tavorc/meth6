#include "Control.h"

Control::Control(int width) : _width(width), _height(1), _bgColor(BackgroundColor::Black), _fgColor(ForegroundColor::White),
							  _isVisible(true), _layer(0), _border(BorderType::None), _position({ 0, 0 }) {
	controlsList.push_back(this);
	this->_layer = 4;
}

Control::~Control() {

}

void Control::SetCursor(int x, int y){
	_cursor.X = x;
	_cursor.Y = y;
}

void Control::SetText(string value){
	_value = value;
}

void Control::SetWidth(int width) {
	_width = width;
}

void Control::SetHeight(int height) {
	_height = height;
}

void Control::SetVisibility(bool visibility) {
	if (visibility) Show();
	else Hide();
}

void Control::SetLayer(size_t layer) {
	_layer = layer;
}

void Control::SetPosition(COORD position) {
	_position = position;
}

void Control::SetBackground(BackgroundColor background) {
	_bgColor = background;
}

void Control::SetForeground(ForegroundColor foreground) {
	_fgColor = foreground;
}

void Control::SetBorderosition(BorderType border) {
	_border = border;
}


void Control::SetFocus(Control* c){
	focus = c;
}

void Control::showCursorOnScreen(Graphics & graphics) {
	graphics.moveTo(GetFocus()->_cursor.X, GetFocus()->_cursor.Y);
	graphics.setCursorVisibility(isCursorable());
}

void Control::Show() {
	_isVisible = true;
	_layer = 5;
}

void Control::Hide() {
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

vector<Control*> Control::GetControls() const{
	return controlsList;
}

int Control::GetWidth() const {
	return _width;
}
int Control::GetHeight() const {
	return _height;
}

bool Control::GetVisibility() const {
	return _isVisible;
}

string Control::GetText(){
	return _value;
}

size_t Control::GetLayer() const {
	return _layer;
}

COORD Control::GetPosition() const {
	return _position;
}

BorderType Control::GetBorder() const {
	return _border;
}

Control* Control::GetFocus() {
	return focus;
}

BackgroundColor Control::GetBackgroundColor() const {
	return _bgColor;
}

ForegroundColor Control::GetForegroundColor() const {
	return _fgColor;
}

void Control::draw(Graphics &g, int left, int top, size_t layer) {
	if (_border != BorderType::None) drawBorder(g, left, top, layer);
}

bool Control::canGetFocus() const {
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

void Control::drawBorder(Graphics& g, int x, int y, size_t layer) {
	x += _position.X;
	y += _position.Y;
	g.moveTo(x, y);
	g.setForeground((Color)GetForegroundColor());
	g.setBackground((Color)GetBackgroundColor());
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