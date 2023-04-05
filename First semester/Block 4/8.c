#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(int d1, int d2, char* s) {
	if (d1 < 2 || d1 > 16 || d2 < 2 || d2 > 16)
	{
		return 1;
	}
	int i = 0;
	int x;
	int k = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 'A')
		{
			x = s[i] - '0';
		}
		else
			x = s[i] - '0' - 7; //7={: ; < = > ? @} //('A'-'9'-1)
		if ((x >= d1) || ((x > '9') && (x < 'A')))
		{
			return 1;
		}
		if (s[i] == '.')
			k++;
		if (k >= 2)
		{
			return 1;
		}
		i++;
	}
	if ((s[0] == '.') || (s[i - 1] == '.'))
	{
		return 1;
	}
	return 0;
}
double transTo10(int d1, int d2, char* s, double R) {
	if (d1 == 10)
	{
		R = atof(s);
	}
	else {
		int i = 0;
		int T = -1;
		int kc = 0;
		int kd = -1;
		while (s[i] != '\0')
		{
			if (s[i] == '.')
				T = i + 1;
			if (T == -1)
				kc++;
			else
				kd++;
			i++;
		}
		int n = 1;
		for (int i = 1; i < kc; i++)
		{
			n = n * d1;
		}
		i = 0;
		double z;


		while ((kc > 0) || (kd > 0))
		{
			if (s[i] == '.')
				i++; //kost
			if (n == 0)
				n = 1; //kost õ2
			z = s[i] - '0';
			if (s[i] >= 'A')
				z = z - 7.0; //7={: ; < = > ? @}
			if (kc > 0)
			{
				R = R + (int)z * n;
				n = n / d1;
				kc = kc - 1;
			}
			else
			{
				if (kd > 0)
				{
					n = n * d1;
					R = R + z / n;
					kd = kd - 1;
				}
			}
			i++;
		}
	}
	return R;
}

void trans(int d1, int d2, char* s, double* R) {
	int cel;
	double drob;
	cel = (int)*R;
	drob = *R - cel;

	char Sdrob[13];
	char sim;
	int a;
	int killdrob = 0;
	double dr;
	Sdrob[0] = '.';
	int i = 0;
	for (i = 1; i < 13; i++)
	{

		a = (int)(drob * d2);
		dr = (drob * d2) - a;
		if (killdrob == 1) { Sdrob[i] = '0'; }
		else {
			if (a < 10)
				sim = '0' + a;
			else
				sim = '0' + a + 7; //7={: ; < = > ? @}
			Sdrob[i] = sim;
		}
		if (dr == 0.0) killdrob = 1;
		drob = (drob * d2) - a;
	} //Drob(d2)~(.aaaaa\0)
	int C, B, A;
	int KS = 0;
	char Csim;
	char Sce[60]; //(999999999999(10)->(2))
	if (cel == 0) { Sce[0] = '0'; Sce[1] = 'Z'; }
	else {
		Sce[0] = 'Z';
		while (cel > 0)
		{
			C = cel % d2;
			KS++;
			if (C < 10)
				Csim = '0' + C;
			else
				Csim = '0' + C + 7;//7={: ; < = > ? @}
			A = Sce[0];
			for (int i = 0; i < KS; i++)
			{
				B = Sce[i + 1];
				Sce[i + 1] = A;
				A = B;
			}
			i = 0;
			Sce[0] = Csim;
			cel = cel / d2;
		}
	}//Cel(d2)~(aaaMMMMMMMM\0)
	//Ñel+Drob
	char Srez[75];
	i = 0;
	while (Sce[i] != 'Z')
	{
		Srez[i] = Sce[i];
		i++;
	}
	int iK = 0;
	for (iK = 0; iK < 13; iK++)
	{
		Srez[i] = Sdrob[iK];
		i++;
	}
	Srez[i] = 'Z';
	i = 0;
	while (Srez[i] != 'Z') {
		printf("%c", Srez[i]);
		i++;
	}
}

int main(void)
{
	int d1, d2;
	char s[13];
	scanf("%d %d", &d1, &d2);
	scanf("%s", &s);
	if (check(d1, d2, &s) == 1) {
		printf("bad input");
		return 0;
	}
	if (d1 == d2)
	{
		printf("%s", s);
		return 0;
	}
	double R = 0.0;
	R = transTo10(d1, d2, &s, R);
	if (d2 == 10)
	{
		printf("%f", R);
		return 0;
	}
	else {
		R = 0.0;
		R = 24.210000000000;
		trans(d1, d2, &s, &R);
	}
	return 0;
}