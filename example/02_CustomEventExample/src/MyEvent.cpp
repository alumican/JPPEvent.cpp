#include "MyEvent.h"

//--------------------------------------------------------------
MyEvent::MyEvent(jppevent::EventType type, int num, std::string str) : jppevent::Event(type)
{
	num_ = num;
	str_ = str;
}

//--------------------------------------------------------------
MyEvent::~MyEvent(void)
{
}

//--------------------------------------------------------------
jppevent::Event MyEvent::clone()
{
	MyEvent e(getType(), getNum(), getStr());
	return e;
}

//--------------------------------------------------------------
int MyEvent::getNum()
{
	return num_;
}

//--------------------------------------------------------------
std::string MyEvent::getStr()
{
	return str_;
}

//--------------------------------------------------------------
const jppevent::EventType MyEvent::START = "start";
const jppevent::EventType MyEvent::COMPLETE = "complete";