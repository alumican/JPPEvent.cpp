#include "MyDispatcher.h"

//--------------------------------------------------------------
MyDispatcher::MyDispatcher() : jppevent::EventDispatcher()
{
	setTarget(this);
}

//--------------------------------------------------------------
MyDispatcher::~MyDispatcher(void)
{
}

//--------------------------------------------------------------
void MyDispatcher::start()
{
	MyEvent e(MyEvent::START, 123, "ABC");
	dispatchEvent(&e);
}

//--------------------------------------------------------------
void MyDispatcher::complete()
{
	MyEvent e(MyEvent::COMPLETE, 456, "DEF");
	dispatchEvent(&e);
}

//--------------------------------------------------------------
std::string MyDispatcher::getName()
{
	return "MyDispatcher";
}