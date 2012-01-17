#include "testApp.h"

int n3;

//--------------------------------------------------------------
void JPPEVENT_CB testApp::eventHandler1(jppevent::Event *e)
{
	//get this pointer
	testApp *target = static_cast<testApp*>(e->getTarget());
	ofLog(OF_LOG_NOTICE, "called 1: type = %s, n1 = %d", e->getType().c_str(), target->n1);
}

void JPPEVENT_CB testApp::eventHandler2(jppevent::Event *e)
{
	//get this pointer
	testApp *target = static_cast<testApp*>(e->getTarget());
	ofLog(OF_LOG_NOTICE, "called 2: type = %s, n2 = %d", e->getType().c_str(), target->n2);
}

//Global function
void JPPEVENT_CB eventHandler3(jppevent::Event *e)
{
	ofLog(OF_LOG_NOTICE, "called 3: type = %s, n3 = %d", e->getType().c_str(), n3);
}

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	n1 = 10;
	n2 = 20;
	n3 = 30;

	//create dispatcher
	jppevent::EventDispatcher dispatcher(this);

	//add listener
	dispatcher.addEventListener("A", eventHandler1);
	dispatcher.addEventListener("B", eventHandler1);
	dispatcher.addEventListener("B", eventHandler2, 100); //high priority
	dispatcher.addEventListener("B", eventHandler3);

	//dispatch test
	ofLog() << "----------------------------------------";
	jppevent::Event eA("A");
	dispatcher.dispatchEvent(&eA);

	ofLog() << "----------------------------------------";
	dispatcher.dispatchEvent("A");

	ofLog() << "----------------------------------------";
	jppevent::Event eB("B");
	dispatcher.dispatchEvent(&eB);
}

//--------------------------------------------------------------
void testApp::update()
{
}

//--------------------------------------------------------------
void testApp::draw()
{
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{
}