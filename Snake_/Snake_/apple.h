#pragma once
using namespace std;
#include <iostream>
#include"point.h"
#include"body.h"

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class apple : public point
{
public:
    apple() { // (body sourth)

        point p(getRandomNumber(1, 9), getRandomNumber(1, 9)); // rand() % 30-15         
        x = p.x;
        y = p.y;
    }

    virtual void print() override {
        cout << x << "||" << y;
    }

    ~apple() {

    }
};


