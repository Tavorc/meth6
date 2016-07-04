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
	int				_width;
	int				_height;
	bool			_isVisible;
	string			_value;
	size_t			_layer;
	BackgroundColor	_bgColor;
	ForegroundColor	_fgColor;
	BorderType		_border;

protected:
	COORD	_position;
	COORD _cursor;
	//Graphics _graphics;			//? CHECK IF MUST

public:
	Control(int);
	~Control();

	void SetWidth(int);
	void SetCursor(int, int);
	void SetHeight(int);
	void SetVisibility(bool);
	void SetLayer(size_t);
	void SetPosition(COORD);
	void SetText(string);
	void SetBackground(BackgroundColor);
	void SetForeground(ForegroundColor);
	void SetBorderosition(BorderType);
	static void SetFocus(Control*);
	void Show();
	void Hide();

	int GetWidth() const;
	int GetHeight() const;
	bool GetVisibility() const;
	size_t GetLayer() const;
	COORD GetPosition() const;
	string GetText();
	BorderType GetBorder() const;
	static Control* GetFocus();
	BackgroundColor GetBackgroundColor() const;
	ForegroundColor GetForegroundColor() const;
	vector<Control*> GetControls() const;
	bool isClicked(int x, int y);
	int GetLeft() const;
	int getTop() const;

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool) = 0;
	virtual void keyDown(int, char) = 0;
	virtual bool canGetFocus() const;
	virtual void getAllControls(vector<Control*>&) {}
	virtual void showCursorOnScreen(Graphics &);
	
	void drawBorder(Graphics&, int, int, size_t);

};

static Control* focus = NULL;
static vector<Control*> controlsList;