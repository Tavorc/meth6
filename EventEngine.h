#pragma once

#include "CONTROL.h"
#include "Graphics.h"
#include <Windows.h>
#include <vector>
 
class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(CONTROL &c);
	virtual ~EventEngine();
private:
	void moveFocus(CONTROL &main, CONTROL *focused);
	void setFocusByPosition(vector<CONTROL*> &vc, int, int);
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};