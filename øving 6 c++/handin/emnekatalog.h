#pragma once



class CourseCatalog{
    private:
        map<string, string> courses;
    public:
        void addCourse(const string& code, const string& alias);
        void removeCourse(const string& code);
        string getCourse(const string& code);
        void saveCourse();
        void loadCourse(const string& filename);
        friend ostream& operator<<(ostream& os, const CourseCatalog& c);
};

