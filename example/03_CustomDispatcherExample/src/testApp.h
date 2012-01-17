#pragma once

#include "ofMain.h"
#include "JPPEvent.h"
#include "MyEvent.h"
#include "MyDispatcher.h"

class testApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		static void JPPEVENT_CB eventHandler(MyEvent *e);
		MyDispatcher myDispatcher;
		int n;
};