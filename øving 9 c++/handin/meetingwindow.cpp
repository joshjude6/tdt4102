#include "meeting.h"
#include "meetingwindow.h"
#include "person.h"
#include "car.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MeetingWindow::cb_quit(Fl_Widget*, void* pw){
    static_cast<MeetingWindow*>(pw)->hide();
}