#include <stdio.h>
#include <time.h>

int findGCDv1(int a,int b);
int findGCDv2(int a,int b);
int findGCDv3(int a,int b);

float Benchmark(int bound , int type)
{
	int (*fp)(int,int);
	switch(type)
	{
		case 1:
			fp = findGCDv1;
			break;
		case 2:
			fp = findGCDv2;
			break;
		case 3:
			fp = findGCDv3;
			break;
	}
	float startTime = 0;
	float endTime = 0;
	int v = 0;
	int i,j;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	for(i=2;i<bound;i++){
		for(j=2;j<bound;j++)
		{
		v = (*fp)(i,j);
		}
	}
	endTime = (float)clock()/CLOCKS_PER_SEC;
	return endTime-startTime;
}

int main(void)
{	
	printf("v1:%f\n",Benchmark(9999,1));
	printf("v2:%f\n",Benchmark(9999,2));
	printf("v3:%f\n",Benchmark(9999,3));
	return 0;
}
