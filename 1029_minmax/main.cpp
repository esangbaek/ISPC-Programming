#include "minmax_ispc.h"
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <x86intrin.h>

using namespace std;
using namespace ispc;

int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));

	int N = 1024;
	int* x = new int[N];

	int* min = new int;
	int* max = new int;
	int maximum, minimum;
	int start, end;

	//initialize x here
	for(int i=0;i<N;i++)
	{
		x[i] = rand();
		//printf("%d\n",x[i]);
	}

	//find maximum and minimum number with c++ function
	printf("< Using C++ library >\n\n");
	start = __rdtsc();
	maximum = *max_element(&x[0], &x[N]);
	end = __rdtsc();
	printf("Max element : %d\n",maximum);
	printf("max_element function Elapsed time : %d\n\n",end-start);

	start = __rdtsc();
	minimum = *min_element(&x[0], &x[N]);
	end = __rdtsc();
	printf("Min element : %d\n", minimum);
	printf("min_element function Elapsed time : %d\n\n", end-start);

	//execute ISPC code
	printf("< Using ISPC program >\n\n");

	start = __rdtsc();
	find_max(N, x, max);
	end = __rdtsc();
	printf("ISPC maximum : %d\n", max[0]);
	printf("ISPC maximum Elapsed time : %d\n\n", end-start);

	start = __rdtsc();
	find_min(N, x, min);
	end = __rdtsc();
	printf("ISPC minimum : %d\n", min[0]);
	printf("ISPC minimum Elapsed time : %d\n", end-start);

	return 0;
}
