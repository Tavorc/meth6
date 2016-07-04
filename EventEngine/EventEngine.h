#pragma once

#include "../Control/Control.h"
#include "../Graphics/Graphics.h"
#include <Windows.h>

class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control &c);
	virtual ~EventEngine();
private:
	void moveFocus(Control &main, Control *focused);
	void EventEngine::setFocusByPosition(Control &main, int x, int y);
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};