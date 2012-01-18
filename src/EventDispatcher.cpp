/*
Copyright (c) 2012 Yukiya Okuda
See LICENSE for full license information.
*/

#include "EventDispatcher.h"

//--------------------------------------------------------------
jppevent::EventDispatcher::EventDispatcher(void *target)
{
	target_ = target;
	id_ = 0;
}

//--------------------------------------------------------------
jppevent::EventDispatcher::~EventDispatcher(void)
{
	target_ = NULL;
}

//--------------------------------------------------------------
void *jppevent::EventDispatcher::getTarget()
{
	return target_;
}

//--------------------------------------------------------------
void jppevent::EventDispatcher::setTarget(void *target)
{
	target_ = target;
}

//--------------------------------------------------------------
void jppevent::EventDispatcher::dispatchEvent(jppevent::Event *e)
{
	e->target_ = target_;
	
	std::vector<jppevent::EventListener> *list = &listeners_[e->getType()];
	std::vector<jppevent::EventListener>::iterator it;
	for (it = list->begin(); it != list->end(); ++it)
	{
		//jppevent::Event ee = e->clone();
		//ee.target_ = target_;
		//(*it).handler(&ee);

		(*it).handler(e);
	}
}

//--------------------------------------------------------------
void jppevent::EventDispatcher::dispatchEvent(jppevent::EventType type)
{
	jppevent::Event e(type);
	dispatchEvent(&e);
}

//--------------------------------------------------------------
void jppevent::EventDispatcher::addEventListener(jppevent::EventType type, jppevent::EventHandler handler, unsigned int priority)
{
	std::vector<jppevent::EventListener> *list = &listeners_[type];

	if (list->size() > 0)
	{
		std::vector<jppevent::EventListener>::iterator it;
		for (it = list->begin(); it != list->end(); ++it)
		{
			if (*it->handler == handler) return;
		}
	}

	jppevent::EventListener listener;
	listener.type = type;
	listener.handler = handler;
	listener.priority = priority;
	listener.id = id_++;

	list->push_back(listener);
	std::sort(list->begin(), list->end());
}

//--------------------------------------------------------------
void jppevent::EventDispatcher::removeEventListener(jppevent::EventType type, jppevent::EventHandler handler)
{
	if (!hasEventListener(type)) return;
	std::vector<jppevent::EventListener> *list = &listeners_[type];
	std::vector<jppevent::EventListener>::iterator it;
	for (it = list->begin(); it != list->end(); ++it)
	{
		if (*it->handler == handler)
		{
			list->erase(it);
			if (list->size() == 0) listeners_.erase(type);
			return;
		}
	}
}

//--------------------------------------------------------------
bool jppevent::EventDispatcher::hasEventListener(const jppevent::EventType type)
{
	return listeners_.count(type) > 0;
}