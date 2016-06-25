#include <windows.h>
#include <stdio.h>
#include "EventEngine.h"
#include "Panel.h"
#include "TextBox.h"
#include "Form.h"
#include "NumericBox.h"

using namespace System;

int main(VOID)
{
	EventEngine * engine = new	EventEngine();
	// main panel creation
	CONTROL * main = new Form(); 
	// panel creation
	CONTROL * p1 = new Panel("Panel-1",10,4,30,15);
	//  tb creations
	CONTROL * tb1 = new TextBox("tb1", 15, 2, 10, 5);
	CONTROL * tb2 = new TextBox("tb2", 5, 2, 10, 5);
	//CONTROL * tb3 = new TextBox("tb3", 15, 2, 10, 5);

	//naama's edit
	//CONTROL * numericBox = new NumericBox(0, 10, "1", 15, 15, 3, 3);
	////////////////

	// set focus on tb1
	CONTROL::setFocus(*tb1);
	// assign p1 to the form
	((Panel*)main)->AddControl(*p1);
	// assign  tb1 to p1
	((Panel*)p1)->AddControl(*tb1); 
	((Panel*)p1)->AddControl(*tb2);

	//naama's edit
	//((Panel*)p1)->AddControl(*numericBox);
	////////////////

	//((Panel*)p1)->AddControl(*tb3); // tb3 won't be shown	
	engine->run(*main);
	return 0;
}

