#include <stdio.h>
#define NUMBER 10000

int main()
{
	int Num, Temp;
	scanf("%d",&Num);
	int NumArray[NUMBER+1] = {0};
	for ( int I = 0; I < Num; I++ )
	{
		scanf("%d", &Temp);
		NumArray[ Temp ]++;
	}
	
	for ( int I = 1; I <= NUMBER; I++ )
	{
		if ( NumArray[ I ] != 0 )
		for ( int J = 0; J < NumArray[ I ]; J++ )
		{
			printf("%d\n",I);
		}
	}
	
	return 0;
}
