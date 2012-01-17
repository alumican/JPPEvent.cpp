/*
Copyright (c) 2012 Yukiya Okuda
See LICENSE.txt for full license information.
*/

#pragma once
#ifndef __JPPEVENT_EVENTLISTENER_H__ 
#define __JPPEVENT_EVENTLISTENER_H__

#include "EventType.h"

namespace jppevent
{
	class EventListener
	{
		public:
			EventListener(void);
			~EventListener(void);

			jppevent::EventType type;
			jppevent::EventHandler handler;
			unsigned int priority;
			unsigned int id;

			friend bool operator < (const jppevent::EventListener& a, const jppevent::EventListener& b)
			{
				return a.priority == b.priority ? a.id < b.id : a.priority > b.priority;
			};
	};
}

#endif