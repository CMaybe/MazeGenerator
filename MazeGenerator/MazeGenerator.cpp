// MazeGenerator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<ctime>
#define WIDTH 80
#define HEIGHT 80


void printMap(void);
void printNum(void);
bool IsLock(int x, int y);
void makeMaze(int x, int y);

int arr[HEIGHT + 1][WIDTH + 1] = { 0, };

int tem = 0;
enum Map {
	WALL, NONE, ROAD
};

enum Direction {
	TOP, RIGHT, BOTTOM, LEFT
};

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

void makeMaze(int x, int y)
{
	if (IsLock(x, y)) {
		for (int i = 1; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (arr[i][j] == WALL &&
					(arr[i - 1][j] == ROAD ||
						arr[i][j - 1] == ROAD ||
						arr[i + 1][j] == ROAD ||
						arr[i][j + 1] == ROAD)&&
						(arr[i - 1][j] == NONE ||
							arr[i][j - 1] == NONE ||
							arr[i + 1][j] == NONE ||
							arr[i][j + 1] == NONE )) {
					arr[i][j] = ROAD;
					makeMaze(j, i);
					return;
				}
			}
		}
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
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x, y - 1);

			}
			else
			{
				makeMaze(x, y);
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
				if (x > 0 && arr[y][x - 1] == NONE)
					arr[y][x - 1] = WALL;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x + 1, y);

			}
			else
			{
				makeMaze(x, y);
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
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				makeMaze(x, y + 1);
			}
			else
			{
				makeMaze(x, y);
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
				if (x < WIDTH - 1 && arr[y][x + 1] == NONE)
					arr[y][x + 1] = WALL;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x - 1, y);
			}
			else
			{
				makeMaze(x, y);
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
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x, y - 1);

			}
			else
			{
				makeMaze(x, y);
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
				if (x > 0 && arr[y][x - 1] == NONE)
					arr[y][x - 1] = WALL;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x + 1, y);

			}
			else
			{
				makeMaze(x, y);
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
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				makeMaze(x, y + 1);
			}
			else
			{
				makeMaze(x, y);
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
				if (x < WIDTH - 1 && arr[y][x + 1] == NONE)
					arr[y][x + 1] = WALL;
				if (y > 0 && arr[y - 1][x] == NONE)
					arr[y - 1][x] = WALL;
				if (y < HEIGHT - 1 && arr[y + 1][x] == NONE)
					arr[y + 1][x] = WALL;
				makeMaze(x - 1, y);
			}
			else
			{
				makeMaze(x, y);
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
	makeMaze(1, 1);
	arr[0][1] = 4;
	arr[HEIGHT-1][WIDTH - 1] = ROAD;
	arr[HEIGHT][WIDTH - 1] = 4;
	printMap();
	return 0;

}
