void fangjian1(int  a[32][18], int x, int y) {
	int i,j;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (i == 0 || i == 6 || j == 0 || j == 6) {
				a[x + i][y + j] = 2;
			}
			else if (i == 1 || i == 5 || j == 1 || j == 5) {
				a[x + i][y + j] = 1;
			}
			else a[x + i][y + j] = 3;
		}
	}
	a[x+3][y+5] = 3;
	a[x+3][y+6] = 5;
	a[x+3][y+3] = 4;
}