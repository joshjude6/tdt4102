#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

enum class Campus{Trondheim, Ålesund, Gjøvik};

std::ostream& operator<<(std::ostream& os, const Campus& c);

class Meeting {
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const shared_ptr<Person> leader;
        vector<shared_ptr<Person>> participants;
    public:
        Meeting(int d, int st, int et, Campus lo, string sub, shared_ptr<Person> lead) : 
        day{d}, startTime{st}, endTime{et}, location{lo}, subject{sub}, leader{lead}{
            addParticipant(lead);
        }; //konstruktør for møte
        int getDay();
        int getStartTime();
        int getEndTime();
        Campus getLocation();
        string getSubject();
        shared_ptr<Person> getLeader();
        void addParticipant(shared_ptr<Person> p);
        vector<string> getParticipantList();
        vector <shared_ptr<Person>> findPotentialCoDriving(Meeting m);
        
        
};

ostream& operator<<(ostream& os, Meeting& meeting);