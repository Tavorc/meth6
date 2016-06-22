#include <windows.h>
#include <stdio.h>
#include "EventEngine.h"
#include "Panel.h"

int main(VOID)
{
	EventEngine * engine = new	EventEngine();
	CONTROL * main = new Panel("main");
	CONTROL * p = new Panel("p");
	((Panel*)main)->AddControl(*p);
	engine->run(*main);
	return 0;
}

