#include <windows.h>
#include <stdio.h>
#include "EventEngine.h"
#include "Panel.h"
#include "TextBox.h"
#include "Form.h"
#include "NumericBox.h"
#include "ComboBox.h"
using namespace System;

int main(VOID)
{
	EventEngine * engine = new	EventEngine();
	// main panel creation
	CONTROL * main = new Form();
	// panel creation
	CONTROL * p1 = new Panel("Panel-1", 10, 4, 45, 25);
	//  tb creations
	CONTROL * tb1 = new TextBox("", 20, 2, 15, 3);
	CONTROL * tb2 = new TextBox("", 3, 2, 15, 3);
//	CONTROL * cb1 = new ComboBox("tb2", 5, 10, 10, 5);
	// set focus on tb1
	CONTROL::setFocus(*tb1);
	// assign p1 to the form
	((Panel*)main)->AddControl(*p1);
	//// assign  tb1 to p1
	((Panel*)p1)->AddControl(*tb1);
	((Panel*)p1)->AddControl(*tb2);
	//((Panel*)p1)->AddControl(*cb1);

	//naama's edit
	//CONTROL * numericBox = new NumericBox("n", 15, 25, 10, 3, 0, 10);
	//((Panel*)main)->AddControl(*numericBox);

	engine->run(*main);
	return 0;
}

