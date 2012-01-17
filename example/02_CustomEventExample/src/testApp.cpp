#include "testApp.h"

//--------------------------------------------------------------
void JPPEVENT_CB testApp::eventHandler(MyEvent *e)
{
	testApp *target = static_cast<testApp*>(e->getTarget());
	ofLog(OF_LOG_NOTICE, "called : type = %s [%d, %s, %d]", e->getType().c_str(), e->getNum(), e->getStr().c_str(), target->n);
}

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	n = 99;

	//create dispatcher
	jppevent::EventDispatcher dispatcher(this);

	//add event listener
	dispatcher.addEventListener(MyEvent::START, (jppevent::EventHandler)testApp::eventHandler);
	dispatcher.addEventListener(MyEvent::COMPLETE, (jppevent::EventHandler)testApp::eventHandler);

	//dispatch custom event
	ofLog() << "----------------------------------------";
	MyEvent eA(MyEvent::START, 123, "ABC");
	dispatcher.dispatchEvent(&eA);

	ofLog() << "----------------------------------------";
	MyEvent eB(MyEvent::COMPLETE, 456, "DEF");
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