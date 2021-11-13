
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


    body b;
    apple a;    

    int key = 8;
    bool for_open = false;

    while (!GetAsyncKeyState(VK_ESCAPE)) { // (key)
        point last_point = b.l_points.back();
                
        if (b.head() == a) {             
            for_open = true;
            apple a2;
            a = a2;
        }        
        
        b.print(a);
        //a.print(); 

        GetAsyncKeyState(VK_PAUSE);
        
        if (GetAsyncKeyState(VK_UP)) {
            key = 8;
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            key = 5;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            key = 6;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            key = 4;
        }
        switch (key) {
        case 8:b.move(up);
            break;
        case 5:b.move(down);
            break;
        case 6:b.move(Right);
            break;
        case 4:b.move(Left);
            break;
        }

        if (for_open) {
            b.add(last_point);              
            for_open = false;
        }        

        system("cls");

        // ловля бездействия
        if (key == 1) {
            key = 0;
        }
        //Sleep(200);        
        //system("pause");
    }    
}

/*
    int key = _getch();
  while (key != Console::keyEscape) {
    short LX = Pen->getX();
    short LY = Pen->getY();
    Pen->Hide();
    switch (key) {
    case Console::keyLeft : { LX--; break; }
    case Console::keyRight: { LX++; break; }
    case Console::keyUp   : { LY--; break; }
    case Console::keyDown : { LY++; break; }
    case Console::keyF5   : { Objects = AddBank(Objects, Pen->getX(), Pen->getY()); break; }
    case Console::keyF6   : { Objects = AddShop(Objects, Pen->getX(), Pen->getY()); break; }
    case Console::keyF7   : { Objects = AddHouse(Objects, Pen->getX(), Pen->getY()); break; }
    }
    if (!(LX >= 0)) { LX = 0; }
    if (!(LX < 81)) { LX = 80; }
    if (!(LY > 0)) { LY = 1; }
    if (!(LY < 26)) { LY = 25; }
    Pen->setXY(LX, LY);
    if (NULL != Objects) {
      Objects->ListDraw();
    }
    Pen->Draw();

    key = _getch();
  }
  // очи

  коды клавишь:

  static const int keyEscape = 27;
  static const int keySpace = 32;
  static const int keyBackspace = 8;
  static const int keyTab = 9;
  static const int keyEnter = 13;
  static const int keyInsert = 82;
  static const int keyDelete = 83;
  static const int keyUp = 72;
  static const int keyDown = 80;
  static const int keyLeft = 75;
  static const int keyRight = 77;
  static const int keyPageUp = 73;
  static const int keyPageDown = 81;
  static const int keyHome = 71;
  static const int keyEnd = 79;
  static const int keyCenter = 76;
  static const int keyF1 = 59;
  static const int keyF2 = 60;
  static const int keyF3 = 61;
  static const int keyF4 = 62;
  static const int keyF5 = 63;
  static const int keyF6 = 64;
  static const int keyF7 = 65;
  static const int keyF8 = 66;
  static const int keyF9 = 67;
  static const int keyF10 = 68;
  static const int keyF11 = 69;
  static const int keyF12 = 70;

    */

