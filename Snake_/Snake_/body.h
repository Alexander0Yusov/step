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
    int size = 11;
    string player_num;
    list <point> l_points;

    // две точки изначально    
    body() {
        list <point> tmp{ point(5, 8), point(5,9) };
        l_points = tmp;
    }

    body(string anyplayer) :player_num{ anyplayer } {
        if (anyplayer == "first") {
            list <point> tmp{ point(3, 8), point(3,9) };
            l_points = tmp;
        }
        if (anyplayer == "second") {
            list <point> tmp{ point(7, 8), point(7,9) };
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

        // размер поля
        int X, Y;
        X = Y = size;

        // блок средних строк
        for (int i = 0; i < Y; i++) { // смена строки

            for (int j = 0; j < X; j++) { // ПЕРЕБОР вдоль строки 

                // графика горизонтальных границ            
                if (i == 0 || i == Y - 1) {
                    cout << "#";
                }

                 // графика вертикальных границ            
                if ((j == 0 || j == (X - 1)) && (i > 0 && i < Y - 1)) {
                    cout << "#";
                }

                // графика пустого поля и рисовка змейки и яблока
                if (j != 0 && j != (X - 1) && (i > 0 && i < Y - 1)) {
                    // условие наличия точки
                    bool flag = true;
                    for (point iter : l_points)
                    {
                        // если данная координата совпадает с любой из точек змейки то закрашиваем*
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
        
        Sleep(300);
    }

    // возвращает начало списка
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

        // размер поля
        int X, Y;
        X = Y = size;
        
        // вывод игрового поля
        for (int i = 0; i < Y; i++) { // смена строки

            for (int j = 0; j < X; j++) { // ПЕРЕБОР вдоль строки 
                 // графика горизонтальных границ            
                if (i == 0 || i == Y-1) {
                    cout << "#";                    
                }

                // графика вертикальных границ
                if ((j == 0 || j == (X - 1)) && (i > 0 && i < Y-1)) {
                    cout << "#";
                }

                // графика пустого поля и рисовка змейки и яблока
                if (j != 0 && j != (X - 1) && (i > 0 && i < Y - 1)) {
                    // условие наличия точки
                    bool flag = true;
                    for (point iter : l_points)
                    {
                        // если данная координата (i, j) совпадает с любой из точек змейки1 то закрашиваем*
                        if (j == iter.getX() && i == iter.getY()) {
                            cout << "*";
                            flag = false;
                        }
                    }
                    for (point iter2 : b2.l_points)
                    {
                        // если данная координата (i, j) совпадает с любой из точек змейки2 то закрашиваем*
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
        Sleep(700);        
    }

    bool interferention(body b2) {
        point head1 = head();
        for (point iter : b2.l_points)
        {
            // если данная координата (i, j) совпадает с любой из точек змейки1 то закрашиваем*
            if (head1 == iter) {
                return true;                
            }           
        }
        return false;
    }

    bool is_wall() {
        point head_ = head();        
            
                if (head_.getX() == 0 || head_.getX() == size-1 || head_.getY() == 0 || head_.getY() == size-1) {
                    return true;
                } 
                else {
                    return false;
                }
    }

    bool is_full() {
        return get_len() == 10;
    }
    
};

