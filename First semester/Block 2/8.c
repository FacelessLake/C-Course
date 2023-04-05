#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int a[13] = {0,31,30,31,30,31,30,31,31,30,31,30,31};
	int d, m, y, k;
	scanf("%d" "%d" "%d" "%d", &d, &m, &y, &k);
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) a[2] = 29; else a[2] = 28;
	d += k;
	while(d>31){ //пока есть достаточное кол-во дней ищем кол-во пройденных месяцев
		d = d - a[m];
		m++;
		if (m > 12) {
			m = 1;
			y++;
			if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) a[2] = 29; else a[2] = 28; //пока ведутся подсчёты, может наступить високосный год
		}
    }
	printf("%d %d %d", d, m, y);
	return 0;
}