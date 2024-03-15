void fangjian3(int a[32][18], int x, int y) {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 8; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 7) {
				a[x + i][y + j] = 2;
			}
			else if (i == 1 || i == 8 || j == 1 || j == 6) {
				a[x + i][y + j] = 1;
			}
			else a[x + i][y + j] = 3;
		}
	}
	a[x + 2][y + 7] = 18;
	a[x + 2][y + 6] = 17;
	a[x + 7][y + 2] = 11;
	a[x +7][y + 4] = 12;
}