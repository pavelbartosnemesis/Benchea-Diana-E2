#include <iostream>
#include <cstring>
#include <cmath>
#include "Canvas.h"
using namespace std;

Canvas::Canvas(int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			matrix[i][j] = ' ';
		}
	}
	latime = width;
	inaltime = height;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			int c = (i - x + ray) * (i - x + ray) + (j - y + ray) * (j - y + ray);
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				matrix[j][i] = ch;
			}
		}
	}
	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			int c = (i - x + ray) * (i - x + ray) + (j - y + ray) * (j - y + ray);
			if ((i - x) * (i - x) + (j - y) * (j - y) <= (ray-1) * (ray-1))
			{
				matrix[j][i] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			int c = (i - x + ray) * (i - x + ray) + (j - y + ray) * (j - y + ray);
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				matrix[j][i] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)  
{
	for (int i = left; i <= right; i++)
	{
		matrix[top][i] = ch;
		matrix[bottom][i] = ch;
	}
	for (int i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i < bottom; i++)
	{
		for (int j = left + 1; j < right; j++)
		{
			matrix[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	//aici nu stiu
}

void Canvas::Print()
{
	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}