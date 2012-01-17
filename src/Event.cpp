/*
Copyright (c) 2012 Yukiya Okuda
See LICENSE.txt for full license information.
*/

#include "Event.h"

//--------------------------------------------------------------
jppevent::Event::Event(jppevent::EventType type)
{
	type_ = type;
	target_ = NULL;
}

//--------------------------------------------------------------
jppevent::Event::~Event(void)
{
}

//--------------------------------------------------------------
jppevent::Event jppevent::Event::clone()
{
	jppevent::Event e(getType());
	return e;
}

//--------------------------------------------------------------
jppevent::EventType jppevent::Event::getType()
{
	return type_;
}

//--------------------------------------------------------------
void *jppevent::Event::getTarget()
{
	return target_;
}