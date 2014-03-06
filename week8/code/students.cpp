#include <iostream>
#include <string>

using namespace std;

class Faculty
{
    public:
        Faculty() {
            birth_year = 0;
            year_employed = 0;
        }
        Faculty(string name, string ssn, int birth_year, int year_employed) {
            this->name = name;
            this->ssn = ssn;
            this->birth_year = birth_year;
            this->year_employed = year_employed;
        }

    private:
        string name;
        string ssn;
        int birth_year;
        int year_employed;
};

class Student
{
    public:
        Student(string name, string ssn, int birth_year, int year_enrolled) {
            this->name = name;
            this->ssn = ssn;
            this->birth_year = birth_year;
            this->year_enrolled = year_enrolled;
        }

    private:
        string name;
        string ssn;
        int birth_year;
        int year_enrolled;
};

class MscStudent
{
    public:
        MscStudent(string name, string ssn, int birth_year, int year_enrolled, Faculty advisor) {
            this->name = name;
            this->ssn = ssn;
            this->birth_year = birth_year;
            this->year_enrolled = year_enrolled;
            this->advisor = advisor;
        }

    private:
        string name;
        string ssn;
        int birth_year;
        int year_enrolled;
        Faculty advisor;
};

int main()
{
    Faculty fac("Jimmy", "1231231", 1990, 2012);
    Student std("Eddie", "1231231", 1980, 2011);
    MscStudent msc("Michael", "1231231", 1990, 2012, fac);
    return 0;
}
