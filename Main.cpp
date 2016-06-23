#include <windows.h>
#include <stdio.h>
#include "EventEngine.h"
#include "Panel.h"
#include "TextBox.h"

int main(VOID)
{
	EventEngine * engine = new	EventEngine();
	CONTROL * main = new Panel("Main",0,0,50,20);
	CONTROL * p1 = new Panel("Panel-1",10,4,30,15);
	CONTROL * tb1 = new TextBox("tb1", 15, 2, 10, 5);
	CONTROL::setFocus(*tb1);
	CONTROL * tb2 = new TextBox("tb2", 5, 2, 10, 5);
	CONTROL * tb3 = new TextBox("tb3", 5, 2, 10, 5);
	((Panel*)main)->AddControl(*p1);
	((Panel*)p1)->AddControl(*tb3);

	engine->run(*main);
	return 0;
}

