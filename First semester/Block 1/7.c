#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N, n1, ent, lvl, lvlc, i, ent1, lvl1;
	scanf("%d", &N);
	scanf("%d %d %d %d", &n1, &ent, &lvl, &lvlc);
	i = n1 / (((ent - 1) * lvlc) + lvl);   // определяем кол-во квартир на этаже
	if (n1 % (((ent - 1) * lvlc) + lvl) != 0) i++; //округляем в большую сторону
	ent1 = N / (i*lvlc);
	if (N % (i * lvlc) != 0) ent1++;//получаем номер подъезда
	lvl1 = (N - lvlc * i*(ent1-1))/i;
	if ((N - lvlc * i * (ent1 - 1)) % i != 0) lvl1++;//получаем номер этажа
	printf("%d ""%d" , ent1, lvl1);
	return 0;
}