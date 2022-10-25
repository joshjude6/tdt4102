#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int radius = 50;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	Point centre{500, 300};

    vector <unique_ptr<Emoji>> emojiVector;

    SmilingFace smiley{Point{1000 / 2 - radius, 600 / 2 - radius}, radius};

	SadFace sad{Point{1000 / 2 + radius, 600 / 2 - radius}, radius};

	SurprisedFace surprised{
		Point{1000 / 2 - radius, 600 / 2 + radius}, radius};

	AngryFace angry{
		Point{1000 / 2 + radius, 600 / 2 + radius}, radius};

	EmptyFace neutral{
		Point{1000 / 2 + 3 * radius, 600 / 2 - radius}, radius};

	WinkingFace wink{
		Point{1000 / 2 + 3 * radius, 600 / 2 + radius}, radius};

    emojiVector.emplace_back(new SmilingFace(smiley));
	emojiVector.emplace_back(new SadFace(sad));
    emojiVector.emplace_back(new SurprisedFace(surprised));
    emojiVector.emplace_back(new AngryFace(angry));
    emojiVector.emplace_back(new EmptyFace(neutral));
    emojiVector.emplace_back(new WinkingFace(wink));
	
    for (int i = 0; i < emojiVector.size(); i++){
        emojiVector.at(i)->draw(win);
    }

	win.wait_for_close();
}
