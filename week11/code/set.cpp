#include <iostream>
#include <set>

using namespace std;

struct Point
{
    Point() {
        x = y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

bool compare_points(const Point& p1, const Point& p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

struct PointComparer
{
    bool operator() (const Point& p1, const Point& p2) {
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    }
};

int main()
{
    // Not readable
    set<Point, bool (*)(const Point&, const Point&)> s(compare_points);

    for(int i = 0; i < 10; i++) {
        s.insert(Point(i,10-i));
    }

    set<Point, PointComparer> s2;

    for(int i = 0; i < 10; i++) {
        s2.insert(Point(i,10-i));
    }

    return 0;
}
