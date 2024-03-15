void fangjian2(int a[32][18], int x, int y) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == 0 || i == 4 || j == 4 || j == 0) {
				a[x + i][y + j] = 2;
			}
			else if (i == 1 || i == 3 || j == 1 || j == 3) {
				a[x + i][y + j] = 1;
			}
			else a[x + i][y + j] = 3;
		}
	}
	a[x + 2][y + 2] = 7;
	a[x + 2][y + 3] = 3;
}