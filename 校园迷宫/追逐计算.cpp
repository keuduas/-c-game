void zhuizhujisuan(int x1, int y1,int *x2,int *y2) {
	int e, f, g, h;
	e = x1 - *x2; f = y1 - *y2;
	if (e < 0) {
		g = -e;
	}
	else {
		g = e;
	}
	if (f < 0) {
		h = -f;
	}
	else {
		h = f;
	}
	if (g >= h) {
		if (e > 0) {
			*x2 = *x2 + 1;
		}
		else if (e < 0) {
			*x2 = *x2 - 1;
		}
	}
	else {
		if (f > 0) {
			*y2 = *y2 + 1;
		}
		else if (f < 0) {
			*y2 = *y2 - 1;
		}
	}
}