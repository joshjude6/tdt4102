#include "Emoji.h"
#include "AnimationWindow.h"

Face::Face(Point c, int r) : centre{c}, radius{r} {};

/*
void draw_emojis(AnimationWindow& win){
    vector <unique_ptr<Emoji>> emojiVector;
    SmilingFace smiley{
		Point{1000 / 2 - radius, 600 / 2 - radius}, radius};

	SadFace sad{Point{1000 / 2 + radius, 600 / 2 - radius}, radius};

	SurprisedFace surprised{
		Point{1000 / 2 - radius, 600 / 2 + radius}, radius};

	AngryFace angry{
		Point{1000 / 2 + radius, 600 / 2 + radius}, radius};

	EmptyFace neutral{
		Point{1000 / 2 + 3 * radius, 600 / 2 - radius}, radius};

	WinkingFace wink{
		Point{1000 / 2 + 3 * radius,  / 2 + radius}, radius};

    emojiVector.emplace_back(sad);
    emojiVector.emplace_back(surprised);
    emojiVector.emplace_back(smiley);
    emojiVector.emplace_back(neutral);
    emojiVector.emplace_back(wink);
    for (int i = 0; i < emojiVector.size(); i++){
        emojiVector.at(i)->draw(win);
    }
} */