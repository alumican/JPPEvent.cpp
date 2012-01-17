#pragma once

#include "JPPEvent.h"

class MyEvent : public jppevent::Event
{
	public:
		//Custom event type
		static const jppevent::EventType START;
		static const jppevent::EventType COMPLETE;

		//Constructor, destructor
		MyEvent::MyEvent(jppevent::EventType type, int num, std::string str);
		~MyEvent(void);

		//Override
		jppevent::Event clone();

		//Custom member function
		int getNum();
		std::string getStr();

	private:
		//Custom member variables
		int num_;
		std::string str_;
};