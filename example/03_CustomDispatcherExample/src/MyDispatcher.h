#pragma once

#include "JPPEvent.h"
#include "MyEvent.h"

class MyDispatcher : public jppevent::EventDispatcher
{
	public:
		MyDispatcher::MyDispatcher();
		~MyDispatcher(void);

		void start();
		void complete();

		std::string getName();
};