#pragma once
void ditu(int a[32][18]);
void shuchu(int a[32][18], int x, int y, int x2, int y2);
void right(int a[32][18], int x, int y, int x2, int y2);
void left(int a[32][18], int x, int y, int x2, int y2);
void up(int a[32][18], int x, int y, int x2, int y2);
void down(int a[32][18], int x, int y, int x2, int y2);
void zhuizhujisuan(int x1, int y1, int* x2, int* y2);
void chushen(int a[32][18], int* x1, int* y1, int* x2, int* y2);
void shenpan(int a[32][18], int* x1, int* y1, int* x2, int* y2, int* c);
void panduan(int a[32][18], int* x1, int* y1, int* x2, int* y2, int b[17]);
void kaichang();