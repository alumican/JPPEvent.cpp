#include "testApp.h"

//--------------------------------------------------------------
void JPPEVENT_CB testApp::eventHandler(MyEvent *e)
{
	MyDispatcher *target = static_cast<MyDispatcher*>(e->getTarget());
	ofLog(OF_LOG_NOTICE, "called : type = %s [%d, %s, %s]", e->getType().c_str(), e->getNum(), e->getStr().c_str(), target->getName().c_str());
}

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	n = 99;

	//add event listener
	myDispatcher.addEventListener(MyEvent::START, (jppevent::EventHandler)testApp::eventHandler);
	myDispatcher.addEventListener(MyEvent::COMPLETE, (jppevent::EventHandler)testApp::eventHandler);

	//dispatch custom event
	ofLog() << "----------------------------------------";
	myDispatcher.start();

	ofLog() << "----------------------------------------";
	myDispatcher.complete();
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