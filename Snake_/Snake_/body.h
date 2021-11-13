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
    list <point> l_points;

    // ��� ����� ����������    
    body() {
        list <point> tmp{ point(5, 9), point(5,10) };
        l_points = tmp;
    }

    // ���������� �����    
    void add(point entering_point) {
        l_points.push_back(entering_point);
    }

    // ����� ������ ��� �������� ������
    int get_len() {
        return l_points.size();
    }

    // �������
    void print(apple& some_apple) {

        // ������ ����
        int X, Y;
        X = Y = 11;

        // ���� ������ ������
        for (int j = 0; j < Y; j++) {
            cout << "#";
            if (j == X - 1) {
                cout << endl;
            }
        }

        // ���� ������� �����
        for (int i = 0; i < Y; i++) { // ����� ������

            for (int j = 0; j < X; j++) { // ������� ����� ������ 
                 // ������� ������������ ������            
                if (j == 0 || j == (X - 1)) {
                    cout << "#";
                }

                // ������� ������� ���� � ������� ������ � ������
                if (j != 0 && j != (X - 1)) {
                    // ������� ������� �����
                    bool flag = true;
                    for (point iter : l_points)
                    {
                        // ���� ������ ���������� ��������� � ����� �� ����� ������ �� �����������*
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
                    // ���� ����� ���, �� "�����"
                    if (flag) {
                        cout << " ";
                    }
                }
            }
            cout << endl;            
        }

        // ���� ��������� ������
        for (int j = 0; j < X; j++) {
            cout << "#";
            if (j == X - 1) {
                cout << endl;
            }
        }
        Sleep(300);
    }

    // �� ���� �� ������� ������ �����
    point head() {
        return *l_points.begin();
    }

    void move(direction dir) {
        // ���������� ����� ������ � �������� ����������
        // ��������� ����� ������ �� ������
        // �������� ���������� ������ ������, ��������� ����� ���������

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

    void apple() {
        //rand() % 10;
    }


};

