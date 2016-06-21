#include <windows.h>
#include <stdio.h>
#include "EventEngine.h"


int main(VOID)
{
	EventEngine * engine = new	EventEngine();
	CONTROL * control = new CONTROL();
	engine->run(*control);
	return 0;
}

