#include "Canon.h"


void Canon::move(CanonDirection direction, int x, int y) {
	switch (direction) {
	case Up:
		setnewXPosition(x);
		setnewYPosition(y - 1);
		break;
	case Down:
		setnewXPosition(x);
		setnewYPosition(y + 1);
		break;
	case Left:
		setnewXPosition(x);
		setnewYPosition(y - 1);
		break;
	case Right:
		setnewXPosition(x + 1);
		setnewYPosition(y);
		break;
	case UpLeft:
		setnewXPosition(x - 1);
		setnewYPosition(y - 1);
		break;
	case UpRight:
		setnewXPosition(x + 1);
		setnewYPosition(y - 1);
		break;
	case DownLeft:
		setnewXPosition(x - 1);
		setnewYPosition(y + 1);
		break;
	case DownRight:
		setnewXPosition(x + 1);
		setnewYPosition(y + 1);
		break;
	}
	//printToScreen(x, y, canonChar, true);
}

//void Canon::draw(CanonDirection canonDirection, int x, int y) {
//	restoreErasedPoints();
//	switch (canonDirection) {
//	case Up:
//		printToScreen(x, y + 1, ch);
//		break;
//	case UpRight:
//		printToScreen(x + 1, y + 1, ch);
//		break;
//	case Right:
//		printToScreen(x + 1, y, ch);
//		break;
//	case DownRight:
//		printToScreen(x + 1, y - 1, ch);
//		break;
//	case Down:
//		printToScreen(x, y - 1, ch);
//		break;
//	case DownLeft:
//		printToScreen(x - 1, y - 1, ch);
//		break;
//	case Left:
//		printToScreen(x - 1, y, ch);
//		break;
//	case UpLeft:
//		printToScreen(x - 1, y + 1, ch);
//		break;
//	}
//}


