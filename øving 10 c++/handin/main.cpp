#include "MinesweeperWindow.h"

//øving 10, levér denne

int main()
{
	
	Fl::background(200, 200, 200);
	constexpr int width = 5;
	constexpr int height = 5;
	constexpr int mines = 5;

	Point startPoint{ 200,300 };
	MinesweeperWindow mw{startPoint.x, startPoint.y, width, height, mines, "Minesweeper"};
	return gui_main();
}

//srand(time(nullptr));
