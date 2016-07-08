#include <string>
#include "../EventEngine/EventEngine.h"
#include "../TextBox/TextBox.h"
#include "../Label/Label.h"
#include "../Panel/Panel.h"
#include "../ComboBox/ComboBox.h"
#include "../Button/Button.h"
//#include "NumericBox.h"
using namespace System;
using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control &b, int x, int y, bool isLeft)
	{
		_c.SetForeground(ForegroundColor::Red);
	}
private:
	Control &_c;
};

int main(int argc, char **argv)
{
	Label lName(20);
	lName.SetText("Name: ");
	Label lAddress(20);
	lAddress.SetText("Address:");
	Label lCountry(20);
	lCountry.SetText("Counrty:");
	Label lSex(20);
	lSex.SetText("Sex:");
	Label lInterests(20);
	lInterests.SetText("Interests:");
	Label lAge(20);
	lAge.SetText("Age:");


	TextBox tName(20);
	tName.SetText("Sherlock Holmes");
	tName.SetBorderosition(BorderType::Double);
	TextBox tAddress(25);
	tAddress.SetText("221B Baker Street, London");
	tAddress.SetBorderosition(BorderType::Single);
	ComboBox cCountry({ "Israel", "Great Britain", "United States" }, 20);
	cCountry.setSelectedIndex(1);
	cCountry.SetBorderosition(BorderType::Single);
	/*Radiolist rSex(2, 15, { "Male", "Female" });
	rSex.SetBorderosition(BorderType::Single);
	Checklist clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.selectIndex(1);
	clInterests.SetBorderosition(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.SetBorderosition(BorderType::Single);
	*/
	MyListener listener(tAddress);
	Button bSubmit(10);
	bSubmit.SetText("Submit");
	bSubmit.AddListener(listener);
	bSubmit.SetBorderosition(BorderType::Double);
	Panel main;
	main.SetBorderosition(BorderType::Single);
	main.SetWidth(Console::WindowWidth-4);
	main.SetHeight(Console::WindowHeight-4);
	main.AddControl(lName, 1, 2);
	main.AddControl(lAddress, 1, 5);
	main.AddControl(lCountry, 1, 8);
	main.AddControl(lSex, 1, 11);
	main.AddControl(lInterests, 1, 15);
	main.AddControl(lAge, 1, 20);
	main.AddControl(tName, 25, 2);
	main.AddControl(tAddress, 25, 5);
	main.AddControl(cCountry, 25, 8);
	/*main.AddControl(rSex, 25, 11);
	main.AddControl(clInterests, 25, 15);
	main.AddControl(nAge, 25, 20);
	*/
	main.AddControl(bSubmit, 1, 22);
	Control::SetFocus(&tName);
	EventEngine engine;
	engine.run(main);
	return 0;
}