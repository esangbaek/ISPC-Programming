#include "sinx_ispc.h"
#include <x86intrin.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
	int N = 1024;
	int terms = 5;
	int start, end;
	float* x = new float[N];
	float* result = new float[N];
	float* result_2 = new float[N];

	for(int i=0;i<N;i++)
	{
		x[i] = (rand()%1000)/500.0;
	}

	//initialize x here

	//exucute ISPC interleaved code
	start = __rdtsc();
	ispc::sinx_interleaved(N, terms, x, result);
	end = __rdtsc();
	printf("<ISPC Interleaved>\n");
	printf("Elapsed time : %d\n", end-start);
	printf("\n\n");

	/*
	for(int i=0;i<N;i++)
	{
		printf("%f ",result[i]);
	}
	printf("\n\n");
	*/

	//execute ISPC blocked code
	start = __rdtsc();
	ispc::sinx_blocked(N, terms, x, result_2);
	end = __rdtsc();
	printf("<ISPC Blocked>\n");
	printf("Elapsed time : %d\n",end-start);
	printf("\n\n");

	/*
	for(int i=0;i<N;i++)
	{
		printf("%f ",result_2[i]);
	}
	*/
	
	for(int i=0;i<N;i++)
	{
		if(result[i]!=result_2[i])
		{
			printf("Results are not same!\n");
			return 0;
		}
	}
	printf("Same results\n");

	return 0;
}
