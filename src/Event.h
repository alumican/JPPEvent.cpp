/*
Copyright (c) 2012 Yukiya Okuda
See LICENSE.txt for full license information.
*/

#pragma once
#ifndef __JPPEVENT_EVENT_H__ 
#define __JPPEVENT_EVENT_H__

#include "EventType.h"

namespace jppevent
{
	class EventDispatcher;
	class Event
	{
		friend jppevent::EventDispatcher;

		public:
			Event(jppevent::EventType type);
			~Event(void);

			virtual jppevent::Event clone();

			jppevent::EventType getType();
			void *getTarget();

		private:
			jppevent::EventType type_;
			void *target_;
	};
}

#endif