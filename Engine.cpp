#include "Engine.h"
// Add component to the form
ENGINE::ENGINE(){
}
void ENGINE::Add(CONTROL* comp){
	comps.push_back(comp);
}
// Draw and setup the components
void ENGINE::Run(){
	// Prints Componnents.
	for (CONTROL *n : comps) {
		n->Show();
	}
	// Get the standard input handle. 
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");
	// Save the current input mode, to be restored on exit. 
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");
	// Enable the window and mouse input events. 
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");
	// Loop to read and handle the next input events. 
	while (true)
	{
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 	
			{
								
					for (CONTROL*n : comps) {
						
						n->Handle(irInBuf);
					}
					break;
			}
			case MOUSE_EVENT: // mouse input 

				
			//	Handle(irInBuf, i); // asign form
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}

	// Restore input mode on exit.
	SetConsoleMode(hStdin, fdwSaveOldMode);
}



bool ENGINE::NextEditableComponent(int start){
	/*
	int tempIndex = start;
	while (++tempIndex < this->comps.size()){


	}
	*/
	return false;
}
// On error 
VOID ENGINE::ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);
	// Restore input mode on exit.
	SetConsoleMode(hStdin, fdwSaveOldMode);
	ExitProcess(0);
}

// Handle and events
void ENGINE::Handle(INPUT_RECORD *inpt){
	switch (inpt[i].EventType)
	{
	case KEY_EVENT: // keyboard input 
	{
		KEY_EVENT_RECORD ker = inpt[i].Event.KeyEvent;
		switch (ker.wVirtualKeyCode){
			case VK_BACK:
				break;
			case VK_TAB:
				if (inpt[i].Event.KeyEvent.bKeyDown){

				}
				break;
			case VK_RIGHT:
			case VK_NUMPAD6:
				break;
			case VK_LEFT:
			case VK_NUMPAD4:
				break;
			case VK_RETURN:
				break;
			case VK_DELETE:
				break;
			default:
				break;
			}
		}
	}
}
