#include<stdio.h>
#include<Windows.h>
const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
inline int _drgb(bool d, bool r, bool g, bool b)
{
	return (d << 3) + (r << 2) + (g << 1) + (b << 0);
}
inline int _clr(int fc, int bc)
{
	return (fc << 0) + (bc << 4);
}


void color(int a1,int b1,int c1,int d1,int a2,int b2,int c2,int d2)
{
	int fore = _drgb(a1, b1, c1, d1);
	int back = _drgb(a2, b2, c2, d2);
	int color = _clr(fore, back);

	SetConsoleTextAttribute(h, color);
}