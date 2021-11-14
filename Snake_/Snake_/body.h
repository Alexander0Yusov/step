#pragma once
using namespace std;
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
#include"apple.h"

enum direction { up, down, Right, Left };

class body {
public:
    string player_num;
    list <point> l_points;

    // две точки изначально    
    body() {
        list <point> tmp{ point(5, 9), point(5,10) };
        l_points = tmp;
    }

    body(string anyplayer) :player_num{ anyplayer } {
        if (anyplayer == "first") {
            list <point> tmp{ point(3, 9), point(3,10) };
            l_points = tmp;
        }
        if (anyplayer == "second") {
            list <point> tmp{ point(7, 9), point(7,10) };
            l_points = tmp;
        }
    }

    // добавление точки    
    void add(point entering_point) {
        l_points.push_back(entering_point);
    }

    // длина змейки как критерий победы
    int get_len() {
        return l_points.size();
    }

    // вывести
    void print(apple& some_apple) {

        // размер пол€
        int X, Y;
        X = Y = 11;

        // блок первой строки
        for (int j = 0; j < Y; j++) {
            cout << "#";
            if (j == X - 1) {
                cout << endl;
            }
        }

        // блок средних строк
        for (int i = 0; i < Y; i++) { // смена строки

            for (int j = 0; j < X; j++) { // ѕ≈–≈Ѕќ– вдоль строки 
                 // графика вертикальных границ            
                if (j == 0 || j == (X - 1)) {
                    cout << "#";
                }

                // графика пустого пол€ и рисовка змейки и €блока
                if (j != 0 && j != (X - 1)) {
                    // условие наличи€ точки
                    bool flag = true;
                    for (point iter : l_points)
                    {
                        // если данна€ координата совпадает с любой из точек змейки то закрашиваем*
                        if (j == iter.getX() && i == iter.getY()) {
                            cout << "*";
                            flag = false;
                        }
                    }
                    if ((j == some_apple.getX() && i == some_apple.getY())) {
                        if (flag) {
                            cout << "@";
                            flag = false;
                        }
                        //cout << "*";
                        //flag = false;
                    }
                    // если точки нет, то "пусто"
                    if (flag) {
                        cout << " ";
                    }
                }
            }
            cout << endl;            
        }

        // блок последней строки
        for (int j = 0; j < X; j++) {
            cout << "#";
            if (j == X - 1) {
                cout << endl;
            }
        }
        Sleep(300);
    }

    // по идее не имеющий смысла метод
    point head() {
        return *l_points.begin();
    }

    void move(direction dir) {
        // сохранение точки головы в темповую переменную
        // изменение точки головы по кейсам
        // темповую переменную вперед списка, последнюю точку отбросить

        point new_step = l_points.front();

        switch (dir) {
        case up:new_step.deltaY(-1);
            break;

        case down:new_step.deltaY(+1);
            break;

        case Right:new_step.deltaX(+1);
            break;

        case Left: new_step.deltaX(-1);
            break;
        }

        l_points.push_front(new_step);
        l_points.pop_back();

        for (auto iter = l_points.begin(); iter != l_points.end(); iter++)
        {
            iter;
        }
    }

    
    // добавление второго игрока
    void print(apple some_apple2, body b2) {

        // размер пол€
        int X, Y;
        X = Y = 11;

        // блок первой строки
        for (int j = 0; j < Y; j++) {
            cout << "#";
            if (j == X - 1) {
                cout << endl;
            }
        }

        // блок средних строк
        for (int i = 0; i < Y; i++) { // смена строки

            for (int j = 0; j < X; j++) { // ѕ≈–≈Ѕќ– вдоль строки 
                 // графика вертикальных границ            
                if (j == 0 || j == (X - 1)) {
                    cout << "#";
                }

                // графика пустого пол€ и рисовка змейки и €блока
                if (j != 0 && j != (X - 1)) {
                    // условие наличи€ точки
                    bool flag = true;
                    for (point iter : l_points)
                    {
                        // если данна€ координата (i, j) совпадает с любой из точек змейки1 то закрашиваем*
                        if (j == iter.getX() && i == iter.getY()) {
                            cout << "*";
                            flag = false;
                        }
                    }
                    for (point iter2 : b2.l_points)
                    {
                        // если данна€ координата (i, j) совпадает с любой из точек змейки2 то закрашиваем*
                        if ((j == iter2.getX() && i == iter2.getY())) {
                            cout << "*";
                            flag = false;
                        }
                    }
                    if ((j == some_apple2.getX() && i == some_apple2.getY())) {
                        if (flag) {
                            cout << "@";
                            flag = false;
                        }
                    }
                    // если точки нет, то "пусто"
                    if (flag) {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }

        // блок последней строки
        for (int j = 0; j < X; j++) {
            cout << "#";
            if (j == X - 1) {
                cout << endl;
            }
        }
        Sleep(700);
    }
    
};

