#include <windows.h>
#include <stdio.h>

#include "Engine.h"
#include "Label.h"


int main(VOID)
{
	
	ENGINE *e = new ENGINE();
	LABEL *l = new LABEL();
	e->Add((CONTROL*)l);
	e->Run();
	return 0;
}

