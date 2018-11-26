// MazeGenerator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<Windows.h>
#include<ctime>
#define WIDTH 50
#define HEIGHT 50

int temp = 0;

void printMap(void);
void printNum(void);
void gotoxy(int x, int y);
bool IsLock(int x, int y);

int arr[HEIGHT + 1][WIDTH + 1] = { 0, };

enum Map {
	WALL, NONE, ROAD
};

enum Direction {
	TOP, RIGHT, BOTTOM, LEFT
};

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool IsLock(int x, int y)
{
	if (arr[y][x] == WALL ||
		(arr[y - 1][x] != NONE &&
			arr[y][x - 1] != NONE &&
			arr[y + 1][x] != NONE &&
			arr[y][x + 1] != NONE)) {
		return true;
		
	}
	return false;
}

void makeMaze(int x, int y, int cnt)
{
	temp++;
	if (temp % 15 == 0)
	{
		gotoxy(0, 0);
		printMap();
	}
	if (x == 39 && y == 39) return;
	if (IsLock(x, y)) {
		return;
	}
	int num = 1;

	arr[y][x] = ROAD;
	try
	{

		num = rand() % 4;
		switch (num)
		{
		case TOP:
			if (arr[y - 1][x] == NONE && y > 1)
			{
				arr[y - 1][x] = ROAD;
				if (x > 0 && arr[y][x - 1] == NONE)
					arr[y][x - 1] = WALL;
				if (x < WIDTH - 1 && arr[y][x + 1] == NONE)
					arr[y][x + 1] = WALL;
				makeMaze(x, y - 1, cnt + 1);

			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		case RIGHT:
			if (arr[y][x + 1] == NONE && x < WIDTH - 1)
			{
				arr[y][x + 1] = ROAD;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x + 1, y, cnt + 1);

			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		case BOTTOM:
			if (arr[y + 1][x] == NONE && y < HEIGHT - 1)
			{
				arr[y + 1][x] = ROAD;
				if (x > 0 && arr[y][x - 1] == NONE)
					arr[y][x - 1] = WALL;
				if (x < WIDTH - 1 && arr[y][x + 1] == NONE)
					arr[y][x + 1] = WALL;
				makeMaze(x, y + 1, cnt + 1);
			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		case LEFT:
			if (arr[y][x - 1] == NONE && x > 1)
			{
				arr[y][x - 1] = ROAD;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x - 1, y, cnt + 1);
			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		default:
			return;
			break;
		}
	}
	catch (const std::exception&)
	{
		return;
	}
	try
	{

		num = rand() % 4;
		switch (num)
		{
		case TOP:
			if (arr[y - 1][x] == NONE && y > 1)
			{
				arr[y - 1][x] = ROAD;
				if (x > 0 && arr[y][x - 1] == NONE)
					arr[y][x - 1] = WALL;
				if (x < WIDTH - 1 && arr[y][x + 1] == NONE)
					arr[y][x + 1] = WALL;
				makeMaze(x, y - 1, cnt + 1);

			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		case RIGHT:
			if (arr[y][x + 1] == NONE && x < WIDTH - 1)
			{
				arr[y][x + 1] = ROAD;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x + 1, y, cnt + 1);

			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		case BOTTOM:
			if (arr[y + 1][x] == NONE && y < HEIGHT - 1)
			{
				arr[y + 1][x] = ROAD;
				if (x > 0 && arr[y][x - 1] == NONE)
					arr[y][x - 1] = WALL;
				if (x < WIDTH - 1 && arr[y][x + 1] == NONE)
					arr[y][x + 1] = WALL;
				makeMaze(x, y + 1, cnt + 1);
			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		case LEFT:
			if (arr[y][x - 1] == NONE && x > 1)
			{
				arr[y][x - 1] = ROAD;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x - 1, y, cnt + 1);
			}
			else
			{
				makeMaze(x, y, cnt);
			}
			if (IsLock(x, y))
			{
				return;
			}
			break;
		default:
			return;
			break;
		}
	}
	catch (const std::exception&)
	{
		return;
	}

}

void printMap(void)
{
	for (int i = 0; i <= HEIGHT; i++) {
		for (int j = 0; j <= WIDTH; j++) {
			if (arr[i][j] == WALL) {
				printf("■");
			}
			else if (arr[i][j] == ROAD)
			{
				printf("  ");
			}
			else if (arr[i][j] == NONE) {
				printf("□");
			}
			else {
				printf("▒");
			}
		}
		printf("\n");
	}
}

void printNum(void)
{
	for (int i = 1; i < HEIGHT; i++) {
		for (int j = 1; j < WIDTH; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	srand((int)time(NULL));
	for (int i = 1; i < HEIGHT; i++)
	{
		for (int j = 1; j < WIDTH; j++) {
			arr[i][j] = NONE;
		}
	}
	makeMaze(1, 1, 0);
	//makeMaze(WIDTH - 1, HEIGHT - 1, 1200);
	arr[0][1] = 4;
	arr[HEIGHT][WIDTH - 1] = 4;
	arr[HEIGHT-1][WIDTH - 1] = ROAD;
	gotoxy(0, 0);
	printMap();
	return 0;

}
