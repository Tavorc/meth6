#pragma once

#include "../Control/Control.h"

class ComboBox : public Control {
private:
	vector <string> _entries;
	bool _isPressed;
	string _text;
	int _selectedIndex;

public:
	ComboBox(vector <string>, int);
	virtual ~ComboBox();

	size_t getSelectedIndex();
	void setSelectedIndex(size_t);

	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void keyDown(int, char);
	virtual bool canGetFocus() const;
};