#include "sinx_ispc.h"
#include <x86intrin.h>
#include <stdio.h>

void scalar_sinx(int N, int terms, float x[], float y[]);

int main(int argc, char** argv)
{
	int N = 1024;
	int terms = 5;
	int start, end;
	float* x = new float[N];
	float* result = new float[N];
	float* result_2 = new float[N];
	
	//initialize x here
	for(int i=0;i<N;i++)
	{
		x[i] = (rand()%1000)/500.0;
	}

	//exucute Scalar code
	start = __rdtsc();
	scalar_sinx(N, terms, x, result);
	end = __rdtsc();
	printf("Scalar Elapsed time : %d\n", end-start);

	//execute ISPC code
	start = __rdtsc();
	ispc::sinx(N, terms, x, result_2);
	end = __rdtsc();
	printf("ISPC Elapsed time : %d\n\n",end-start);

	for(int i=0;i<N;i++)
	{
		if(result[i]!=result_2[i])
		{
			printf("Results are not same!\n");
			return 0;
		}
	}
	printf("Results are same!\n");

	return 0;
}

void scalar_sinx(int N, int terms, float x[], float y[])
{
	for(int i=0;i<N;i++)
	{
		float value = x[i];
		float numer = x[i] * x[i] * x[i];
		int denom = 6; //3!
		int sign = -1;

		for(int j=1;j<=terms;j++)
		{
			value += sign * numer / denom;
			numer *= x[i] * x[i];
			denom *= (2*j+2) * (2*j+3);
			sign *= -1;
		}
		y[i] = value;
	}
}
