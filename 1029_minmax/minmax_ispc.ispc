#define INT_MAX 2147483647

export uniform int32 find_min(uniform int N, uniform int x[], uniform int min_result[])
{
	//assume N % programCount = 0;

	uniform int32 minimum=INT_MAX;
	uniform int32 cur_min;

	for(uniform int i=0;i<N;i+=programCount)
	{
		int idx = i + programIndex;
		cur_min = reduce_min(x[idx]);
		if(minimum>cur_min)
		{
			minimum = cur_min;
		}
	}
	min_result[0] = minimum;
}

export void find_max(uniform int N, uniform int x[], uniform int max_result[])
{
	//assume N % programCount = 0;
	
	uniform int32 maximum=0;
	uniform int32 cur_max;

	for(uniform int i=0;i<N;i+=programCount)
	{
		int idx = i + programIndex;
		cur_max = reduce_max(x[idx]);

		if(maximum<cur_max)
		{
			maximum = cur_max;
		}
	}
	max_result[0] = maximum;
}
