#include "MinesweeperWindow.h"
#include "Tile.h"


MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->callback(cb_click, this);
			add(tiles.back().get()); 
		}
	}

	// Legger til miner paa tilfeldige posisjoner
	for (int m = 0; m < mines; m++){
		int randomTile = (rand() % ((height*width)+1));
		if(tiles[randomTile]->getMine() == 0){ //hvorfor funker ikke at ?
			tiles[randomTile]->setMine(1); // setter bombe på tile på den tilfeldige genererte tilen
		}  else {
			m--; // slik at vi ikke plasserer flere miner på samme
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	shared_ptr<Tile>& t = at(xy);
	if (t->getState() == Cell::closed) {
			t->open();
		if (!(t->getMine())){
			vector<Point> adjacentPointVector = adjacentPoints(xy);
			int minesNumber = countMines(adjacentPointVector);
			if (minesNumber > 0) {
				t->setAdjMines(minesNumber);
			} else {
				for (Point a : adjacentPointVector) {
					openTile(a);
				}
			}

			int countTiles = tiles.size();
			for (auto t : tiles) {
					if(t->getState() == Cell::open){
						countTiles--;
					}
				}
			if (countTiles == mines){
				for (auto t : tiles) {
				t->open(); //åpner alle felt om alle vanlige felt er åpne, er sånn man vinner
				}
			}
		} else {
			for (auto t : tiles) {
				t->open(); //åpner alle felt om t er en mine, er sånn man taper
			}
		}
	} else {
		return; 
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	shared_ptr<Tile>& t = at(xy);
	if(t->getState() == Cell::closed){
		t->flag();
	} else if (t->getState() == Cell::flagged) {
		t->open();
	} else {
		return;
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int numberOfMines = 0;
	for (auto i : coords){
		if(at(i)->getMine() == 1){
			numberOfMines++;
		}
	}
	return numberOfMines;
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
}
