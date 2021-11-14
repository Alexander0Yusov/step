
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include <time.h>

#include <windows.h>
#include "Time.h"
#include <stdio.h>
#include <stdlib.h>

#include"point.h"
#include"body.h"
#include"apple.h"
using namespace std;


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");

    point p3(3, 5);
    point p4(3, 6);


    // ход
    // условие на яблоко и реакция - удлиниться и добавить новое
    // условие на стенку и реакция
    // условие на себя и реакция
    // условие на длину
    // заново

    body b1("first");
    body b2("second");
    apple a;    

    int key1, key2;
    key1 = key2 = 1;

    bool for_open1, for_open2;
    for_open1 = for_open2 = false;

    while (!GetAsyncKeyState(VK_ESCAPE)) { // (key)
        // сохранение в буферную переменную последней точки змейки
        point last_point1 = b1.l_points.back();
        point last_point2 = b2.l_points.back();
        
        // при условии что голова змейки совпадает с яблоком, добавим буферную переменную
        // last_point1(2) к телу змейки, но после выполнения хода в любом направлении
        if (b1.head() == a) {             
            for_open1 = true;
            apple a2;
            a = a2;
        } 

        if (b2.head() == a) {
            for_open2 = true;
            apple a2;
            a = a2;
        }
                
        b1.print(a, b2);        

        GetAsyncKeyState(VK_PAUSE);
        
        // управление 1
        if (GetAsyncKeyState(VK_UP)) {
            key1 = 1;
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            key1 = 2;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            key1 = 3;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            key1 = 4;
        }

        // управление 2
        if (GetAsyncKeyState(VK_NUMPAD8)) {
            key2 = 1;
        }
        if (GetAsyncKeyState(VK_NUMPAD5)) {
            key2 = 2;
        }
        if (GetAsyncKeyState(VK_NUMPAD6)) {
            key2 = 3;
        }
        if (GetAsyncKeyState(VK_NUMPAD4)) {
            key2 = 4;
        }

        // выполнение хода 1 змейки
        switch (key1) {
        case 1:b1.move(up);
            break;
        case 2:b1.move(down);
            break;
        case 3:b1.move(Right);
            break;
        case 4:b1.move(Left);
            break;
        }

        // выполнение хода 2 змейки
        switch (key2) {
        case 1:b2.move(up);
            break;
        case 2:b2.move(down);
            break;
        case 3:b2.move(Right);
            break;
        case 4:b2.move(Left);
            break;
        }

        // если переменная for_open1(2) истина, то добавление буферной переменной происходит
        // и снова for_open1 делаем ложью, чтобы при каждом шаге не плюсовалось
        if (for_open1) {
            b1.add(last_point1);              
            for_open1 = false;
        }
        if (for_open2) {
            b2.add(last_point2);
            for_open2 = false;
        }

        system("cls");
    }    
}


