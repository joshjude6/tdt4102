#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{{1, Color::blue},
								   {2, Color::red},
								   {3, Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow}};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{{Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"}};

void Tile::open()
{
	if (state == Cell::open){
		return;
	} else {
		this->set();// Setter en button som trykket på, tilsvarer åpnet rute
		state = Cell::open;
		if(isMine == 1) {
			set_label("X");
			set_label_color(Color::red);
		}
	}
}

void Tile::flag()
{
	if (state == Cell::flagged) {
		set_label("");
		state = Cell::closed;
	} else if (state == Cell::closed) {
		set_label("@<");
		set_label_color(Color::dark_blue);
		state = Cell::flagged;
	} else { 
		return; 
	}
}


bool Tile::getMine(){
	return isMine;
}

void Tile::setMine(bool b){
	isMine = b;
}

void Tile::setAdjMines(int n){
	string bombNumber = to_string(n);
	set_label(bombNumber);
	set_label_color(minesToColor.at(n));
}
