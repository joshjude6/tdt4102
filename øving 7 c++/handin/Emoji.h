#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji{
    protected:
        Point centre;
        int radius;
    public:
        virtual void draw(AnimationWindow& win) override{
            win.draw_circle(centre, radius, Color::yellow);
        }
        Face(Point c, int r);
};

class EmptyFace : public Face{
    public:
    EmptyFace(Point c, int r) : Face{c, r} {};
    virtual void draw(AnimationWindow& win) override{
         Face::draw(win);
         win.draw_circle(Point{centre.x - 10, centre.y - 5}, 5, Color::blue);
         win.draw_circle(Point{centre.x + 10, centre.y - 5}, 5, Color::blue);
         cout << "Test" << endl;
        }
};

class WinkingFace : public Face{
    public:
    WinkingFace(Point c, int r) : Face{c, r} {};
    virtual void draw(AnimationWindow& win) override{
         Face::draw(win);
         win.draw_circle(Point{centre.x - 10, centre.y - 5}, 5, Color::blue);
         win.draw_arc(Point{centre.x + 10, centre.y - 7}, 15, 7, -180, 0);
         win.draw_arc(Point{centre.x, centre.y + 15}, 40, 20, -180, 0);
         cout << "Test" << endl;
        }
};


class SadFace : public EmptyFace{
    public:
    SadFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow& win) override{
         EmptyFace::draw(win);
         win.draw_arc(Point{centre.x, centre.y + 20}, 20, 20, 0, 180);
         cout << "Test" << endl;
        }
};

class SurprisedFace : public EmptyFace{
    public:
    SurprisedFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow& win) override{
         EmptyFace::draw(win);
         win.draw_arc(Point{centre.x, centre.y + 20}, 20, 20, 0, 360);
         cout << "Test" << endl;
        }
};

class SmilingFace : public EmptyFace{
    public:
    SmilingFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow& win) override{
         EmptyFace::draw(win);
         win.draw_arc(Point{centre.x, centre.y + 15}, 40, 20, -180, 0);
         cout << "Test" << endl;
        }
};

class AngryFace : public EmptyFace{
    public:
    AngryFace(Point c, int r) : EmptyFace{c, r} {};
    virtual void draw(AnimationWindow& win) override{
         EmptyFace::draw(win);
         win.draw_arc(Point{centre.x, centre.y + 20}, 20, 20, 0, 180);
         win.draw_arc(Point{centre.x - 10, centre.y - 26}, 20, 20, -180, -90);
         win.draw_arc(Point{centre.x + 10, centre.y - 26}, 20, 20, -90, 0);
         cout << "Test" << endl;
        }
};

void draw_emojis(AnimationWindow& win);