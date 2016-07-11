#pragma once

#include <Windows.h>
#include <vector>
#include "../Graphics/Graphics.h"
using namespace std;

enum Single { S_TOP_LEFT_CHAR = '\xDA', S_TOP_RIGHT_CHAR = '\xBF', S_HORZ_CHAR = '\xB3', S_VERT_CHAR = '\xC4', S_BOTTOM_LEFT_CHAR = '\xC0', S_BOTTOM_RIGHT_CHAR = '\xD9' };
enum Double { D_TOP_LEFT_CHAR = '\xC9', D_TOP_RIGHT_CHAR = '\xBB', D_HORZ_CHAR = '\xBA', D_VERT_CHAR = '\xCD', D_BOTTOM_LEFT_CHAR = '\xC8', D_BOTTOM_RIGHT_CHAR = '\xBC' };

enum class BorderType { Single, Double, None };

class Control {
private:

	bool			_isVisible;
	string			_value;
	size_t			_layer;
	BackgroundColor	_bgColor;
	ForegroundColor	_fgColor;
	BorderType		_border;

protected:
	COORD	_position;
	COORD _cursor;
	int				_width;
	int				_height;

public:
	Control(int);
	~Control();

	void setWidth(int);
	void setCursor(int, int);
	void setHeight(int);
	virtual void setVisibility(bool);
	virtual void setLayer(size_t);
	virtual void setPosition(COORD);
	void setText(string);
	void setBackground(Color);
	void setForeground(Color);
	void setBorderosition(BorderType);
	static void setFocus(Control*);
	void show();
	void hide();

	int getWidth() const;
	int getHeight() const;
	bool getVisibility() const;
	size_t getLayer() const;
	COORD getPosition() const;
	string getText() const;
	BorderType getBorder() const;
	static Control* getFocus();
	BackgroundColor getBackgroundColor() const;
	ForegroundColor getForegroundColor() const;
	vector<Control*> getControls() const;
	bool isClicked(int x, int y);
	int GetLeft() const;
	int getTop() const;

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool) = 0;
	virtual void keyDown(int, char) = 0;
	virtual bool canGetFocus() const;
	virtual bool canClicked() const;

	virtual void getAllControls(vector<Control*>&) {}
	virtual void showCursorOnScreen(Graphics &);
	virtual bool isCursorable();

	void drawBorder(Graphics&, int, int, size_t);

};

static Control* focus = NULL;
static vector<Control*> controlsList;