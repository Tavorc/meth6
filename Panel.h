#pragma once

#include "CONTROL.h"
#include <vector>

class Panel : public CONTROL
{
protected:
	vector<CONTROL*> controls;
public:
	Panel(string);
	virtual ~Panel();
	void AddControl(CONTROL&);
	//void RemoveControl(CONTROL&); 
	
private:
};