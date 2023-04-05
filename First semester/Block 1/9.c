#include <stdio.h>
#include <math.h>

int main()
{
	long long input, a = 1, b = 1, c = 1, k;
	long long count = 0;
	double rootb, roota;

	scanf_s("%lld", &input);

	roota = sqrt(input);
	k = floor(roota);

	while (a <= cbrt(input))
	{

		count += input / b / a - 1 * (b - 1);
		//printf("%lld: %lld %lld %lld = %lld\n", count, a, b, c, a * b * c);
		b++;
		c = b;
		rootb = sqrt(input / a);
		//printf("%f", rootb);

		if (b > rootb)
		{
			a++;
			b = a;
			c = a;
			//count++;
		}
		//printf("=========================\n");
	}



	printf("%lld", count);

	return 0;
}