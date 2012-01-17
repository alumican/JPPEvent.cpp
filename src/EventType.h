/*
Copyright (c) 2012 Yukiya Okuda
See LICENSE.txt for full license information.
*/

#pragma once
#ifndef __JPPEVENT_EVENTTYPE_H__ 
#define __JPPEVENT_EVENTTYPE_H__

#include <string>

#define JPPEVENT_CB __stdcall

namespace jppevent
{
	class Event;

	typedef std::string EventType;
	typedef void (JPPEVENT_CB *EventHandler)(jppevent::Event *e);
}

#endif