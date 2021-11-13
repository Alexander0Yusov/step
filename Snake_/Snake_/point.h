#pragma once
using namespace std;
#include <iostream>

class point {
public:
    int x;
    int y;

    point() :x{ 0 }, y{ 0 }{
    }

    point(int _x, int _y) :x{ _x }, y{ _y }{
    }

    virtual int getX() {
        return x;
    }
    virtual int getY() {
        return y;
    }

    void deltaX(int _x) {
        x = x + _x;
    }
    void deltaY(int _y) {
        y = y + _y;
    }

    virtual void print() {
        cout << x << "|" << y;
    }


    point(const point& sourth) :x{ sourth.x }, y{ sourth.y }{
    }

    /*
        void print() {
            if (y > 0) {
                for (int i = 0; i < y - 1; i++) {
                    cout << endl;
                }
                if (x > 0) {
                    for (int i = 0; i < x - 1; i++) {
                        cout << " ";
                    }
                    cout << "*";
                }
                if (x == 0) {
                    cout << "*";
                }
            }
            if (y == 0) {
                if (x > 0) {
                    for (int i = 0; i < x - 1; i++) {
                        cout << " ";
                    }
                    cout << "*";
                }
                if (x == 0) {
                    cout << "*";
                }
            }
        }
        */
};

bool operator==(const point& first, const point& second) {
    if (first.x == second.x && first.y == second.y) {
        return true;
    }
    else
    {
        return false;
    }
}