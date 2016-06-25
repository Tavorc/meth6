#ifndef _MOUSE_LISTENER_H_
#define _MOUSE_LISTENER_H_

#include "Control.h"

struct MouseListener {
private:

public:
	virtual void MousePressed(CONTROL&, int, int, bool) = 0;
};

#endif