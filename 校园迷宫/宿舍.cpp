void fangjian6(int a[32][18], int x, int y) {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 7; j++) {
			if (i == 0 || i == 8 || j == 0 || j == 6) {
				a[x + i][y + j] = 2;
			}
			else if (i == 1 || i == 7 || j == 1 || j == 5) {
				a[x + i][y + j] = 1;
			}
			else a[x + i][y + j] = 3;
		}
	}
	a[x][y + 3] = 8;
	a[x + 1][y + 3] = 17;
	a[x + 3][y + 2] = 10;
	a[x + 5][y + 2] = 9;
}