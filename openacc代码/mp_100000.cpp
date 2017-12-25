#include <stdio.h>
#include <omp.h>

int main()
{
	int i, n;
	double start, end, time;
	float a[100000], b[100000], result;

	n = 100000;
	result = 0.0;
	for (i = 0; i < n; i++)
	{
		a[i] = i * 1.0;
		b[i] = i * 2.0;

	}

	start = omp_get_wtime();
#pragma omp parallel for private(i)
	for (i = 0; i < n; i++)

	{

		result = result + (a[i] * b[i]);
	}
	end = omp_get_wtime();
	time = end - start;
	printf("a*b= %12.6lf\n", result);
	printf("time(s)=%12.6lf\n", time);
	return 0;
}