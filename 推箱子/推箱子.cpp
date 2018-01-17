// 推箱子.cpp: 定义控制台应用程序的入口点。□○※▧■●◆▒★
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

struct Location
{
	int m;
	int n;
};

class Operate
{
public:
	Operate(int mp[10][10],int m,int n);
	~Operate();
	void Find(int m, int n);//寻找人所在的位置；
	void up();//向上操作；
	void down();// 向下操作；
	void left();//向左操作；
	void right();//向右操作；
	void display(int, int);//显示地图；
	bool judge();//判断人是否站在目的地上；
	int end(int,int);//判断游戏结束；
private:
	Location L;
	Location J[10];//分配最多十个目的地
	bool flag = 0;
	int map[10][10], count = 0;
	int m, n;//表示人的位置；
	
};

Operate::Operate(int mp[10][10],int r,int  c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = mp[i][j];
			if (map[i][j] == 2) {                  //存储目的地的位置
				J[count].m = i;
				J[count].n = j;
				count++;
			}
		}
	}
	
}

Operate::~Operate()
{
}

void Operate::Find(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 4) {
				m = i;
				n = j;
			}
		}
	}
}

void Operate::up() {
	if (map[m - 1][n] == 0|| map[m - 1][n] == 2) {
		map[m - 1][n] = 4;
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m - 1;
		n = n;
	}
	if (map[m - 1][n] == 3 && (map[m - 2][n] == 0 || map[m - 2][n] == 2)) {
		map[m - 2][n] = map[m - 1][n];
		map[m - 1][n] = map[m][n];
		if(judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m - 1;
		n = n;
	}
}

void Operate::down() {
	if (map[m + 1][n] == 0 || map[m + 1][n] == 2) {
		map[m + 1][n] = 4;
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m + 1;
		n = n;
	}
	if (map[m + 1][n] == 3 && (map[m + 2][n] == 0 || map[m + 2][n] == 2)) {
		map[m + 2][n] = map[m + 1][n];
		map[m + 1][n] = map[m][n];
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m + 1;
		n = n;
	}
}

void Operate::left() {
	if (map[m][n-1] == 0 || map[m][n - 1] == 2) {
		map[m][n - 1] = 4;
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m;
		n = n-1;
	}
	if (map[m][n - 1] == 3 && (map[m][n - 2] == 0 || map[m][n - 2] == 2)) {
		map[m][n - 2] = map[m][n - 1];
		map[m][n - 1] = map[m][n];
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m;
		n = n-1;
	}
}

void Operate::right() {
	if (map[m][n + 1] == 0 || map[m][n + 1] == 2) {
		map[m][n + 1] = 4;
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m;
		n = n + 1;
	}
	if (map[m][n + 1] == 3 && (map[m][n + 2] == 0 || map[m][n + 2] == 2)) {
		map[m][n + 2] = map[m][n + 1];
		map[m][n + 1] = map[m][n];
		if (judge()) map[m][n] = 2;
		else map[m][n] = 0;
		m = m;
		n = n + 1;
	}
}

bool Operate::judge() {
	for (int i = 0; i < count; i++) {
		if (m == J[i].m&&n == J[i].n) return 1;
	}
	return 0;
}

void Operate::display(int r,int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 0) cout << setw(2) << " ";
			else if  (map[i][j] == 1) cout << setw(2) << "■";
			else if (map[i][j] == 2) cout << setw(2) << "◆";
			else if (map[i][j] == 3) cout << setw(2) << "★";
			else if (map[i][j] == 4) cout << setw(2) << "●";
		}
		cout << endl;
	}
}
int Operate::end(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 2) {
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	/*0代表空格，1代表墙，2代表目的地，3代表箱子，4代表人*/
	int map1[10][10] = {
		{ 0,0,1,1,1,0,0,0,0,0 }, //0
		{ 0,0,1,2,1,0,0,0,0,0 },//1
		{ 0,0,1,0,1,1,1,1,0,0 },//2
		{ 1,1,1,3,0,3,2,1,0,0 },//3
		{ 1,2,0,3,4,1,1,1,0,0 },//4
		{ 1,1,1,1,3,1,0,0,0,0 },//5
		{ 0,0,0,1,2,1,0,0,0,0 },//6
		{ 0,0,0,1,1,1,0,0,0,0 },//7
		{ 0,0,0,0,0,0,0,0,0,0 },//8
		{ 0,0,0,0,0,0,0,0,0,0 },//9
	};
	int map2[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,0,0,1,1},
		{1,0,3,0,0,0,0,3,1,1},
		{1,0,0,1,1,1,0,0,1,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,0,1,2,2,2,1,0,1,1},
		{1,0,0,0,0,3,0,0,0,1},
		{1,0,0,1,0,0,4,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	int chioces;
	Operate op(map1, 10, 10);
	Operate op1(map2, 10, 10);
	char ch;
	do {
		cout << "-------主菜单-------" << endl;
		cout << "1-开始游戏" << endl;
		cout << "2-退出游戏" << endl;
		cout << "Enter Chioces:";
		cin >> chioces;
		switch (chioces)
		{
		case 1:
			do{
				cout << "1-第一关" << endl;
				cout << "2-第二关" << endl;
				cout << "3-退出" << endl;
				cout << "Enter Chioces:";
				cin >> chioces;
				switch (chioces)
				{
				case 1:
					op.display(10, 10);
					op.Find(10,10);
					do
					{
					    ch = _getch();
						ch = _getch();
						switch (ch)
						{
						case 72:
							op.up();
							op.display(10, 10);
							break;
						case 75:
							op.left();
							op.display(10, 10);
							break;
						case 77:
							op.right();
							op.display(10, 10);
							break;
						case 80:
							op.down();
							op.display(10, 10);
							break;
						default:
							break;
						}
					} while(op.end(10,10)==1);
					if (!op.end(10, 10)) cout << "游戏结束！" << endl;
					break;
				case 2:
					op1.display(10, 10);
					op1.Find(10, 10);
					do
					{
						ch = _getch();
						ch = _getch();
						switch (ch)
						{
						case 72:
							op1.up();
							op1.display(10, 10);
							break;
						case 75:
							op1.left();
							op1.display(10, 10);
							break;
						case 77:
							op1.right();
							op1.display(10, 10);
							break;
						case 80:
							op1.down();
							op1.display(10, 10);
							break;
						default:
							break;
						}
					} while (op1.end(10, 10) == 1);
					if (!op1.end(10, 10)) cout << "游戏结束！" << endl;
					break;
				case 3:
					break;
				default:
					break;
				}
			} while (chioces != 3);
			break;
		case 2:
			break;
		default:
			break;
		}
	} while (chioces != 2);
    return 0;
}

