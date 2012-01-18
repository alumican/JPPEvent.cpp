/*
Copyright (c) 2012 Yukiya Okuda
See LICENSE for full license information.
*/

#pragma once
#ifndef __JPPEVENT_EVENTDISPATCHER_H__ 
#define __JPPEVENT_EVENTDISPATCHER_H__

#include <vector>
#include <map>
#include <algorithm>
#include "EventType.h"
#include "Event.h"
#include "EventListener.h"

namespace jppevent
{
	class EventDispatcher
	{
		public:
			EventDispatcher(void *target = NULL);
			~EventDispatcher(void);

			void *getTarget();
			void setTarget(void *target);

			void dispatchEvent(jppevent::Event *e);
			void dispatchEvent(jppevent::EventType type);

			void addEventListener(jppevent::EventType type, jppevent::EventHandler handler, unsigned int priority = 0);
			void removeEventListener(jppevent::EventType type, jppevent::EventHandler handler);
			
			bool hasEventListener(jppevent::EventType type);

		private:
			std::map<jppevent::EventType, std::vector<jppevent::EventListener>> listeners_;
			void *target_;
			unsigned int id_;
	};
}

#endif