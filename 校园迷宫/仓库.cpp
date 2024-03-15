void fangjian5(int a[32][18], int x, int y) {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				a[x + i][y + j] = 2;
			}
			else if (i == 1 || i == 8 || j == 1 || j == 8) {
				a[x + i][y + j] = 1;
			}
			else a[x + i][y + j] = 3;
		}
	}
	a[x + 4][y + 8] = 17;
	a[x + 5][y + 8] = 17;
	a[x + 4][y + 9] = 20;
	a[x + 5][y + 9] = 20;
	a[x + 2][y + 2] = 15;
}