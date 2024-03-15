#include<math.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")

void shenpan(int a[32][18], int* x1, int* y1, int* x2, int* y2,int *c) {
	void shijian2(int a[32][18], int* x1, int* y1, int* x2, int* y2, int* c);
	void shijian18(int a[32][18], int* x1, int* y1, int* x2, int* y2);
	int x, y;
	x = abs(*x1 - *x2); y = abs(*y1 - *y2);
	if ((x+y)<=1) {
		shijian18(a, x1, y1, x2, y2);
	}
	else if (a[*x1][*y1] == 5) {
		shijian2(a, x1, y1, x2, y2, c);
	}
}