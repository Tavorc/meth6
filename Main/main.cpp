#include "..\EventEngine\EventEngine.h"
#include "..\TextBox\TextBox.h"
#include "..\Label\Label.h"
#include "..\Panel\Panel.h"
#include "..\ComboBox\ComboBox.h"
#include "..\Button\Button.h"
#include "..\NumericBox\NumericBox.h"
#include "..\Checklist\Checklist.h"
#include "..\Radiolist\Radiolist.h"
using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control  &b, int x, int y, bool isLeft)
	{
		_c.setForeground(Color::Red);
	}
private:
	Control &_c;
};

int main(int argc, char **argv)
{
	Label lName(20);
	lName.setText("Name: ");
	Label lAddress(20);
	lAddress.setText("Address:");
	Label lCountry(20);
	lCountry.setText("Counrty:");
	Label lSex(20);
	lSex.setText("Sex:");
	Label lInterests(20);
	lInterests.setText("Interests:");
	Label lAge(20);
	lAge.setText("Age:");


	TextBox tName(20);
	tName.setText("Sherlock Holmes");
	tName.setBorderosition(BorderType::Double);
	TextBox tAddress(25);
	tAddress.setText("221B Baker Street, London");
	tAddress.setBorderosition(BorderType::Single);
	ComboBox cCountry({ "Israel", "Great Britain", "United States" }, 20);
	cCountry.setSelectedIndex(1);
	cCountry.setBorderosition(BorderType::Single);
	Radiolist rSex(2, 15, { "Male", "Female" });
	rSex.setBorderosition(BorderType::Single);
	Checklist clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.selectIndex(1);
	clInterests.setBorderosition(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorderosition(BorderType::Single);

	MyListener listener(tAddress);
	Button bSubmit(10);
	bSubmit.setText("Submit");
	bSubmit.addListener(listener);
	bSubmit.setBorderosition(BorderType::Double);
	Panel main;
	main.addControl(lName, 1, 2);
	main.addControl(lAddress, 1, 5);
	main.addControl(lCountry, 1, 8);
	main.addControl(lSex, 1, 11);
	main.addControl(lInterests, 1, 15);
	main.addControl(lAge, 1, 20);
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
	main.addControl(nAge, 25, 20);

	main.addControl(bSubmit, 1, 22);
	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(main);
	return 0;
}