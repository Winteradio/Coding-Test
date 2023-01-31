#include <stdio.h>
#define NUMBER 8000

int main()
{
	int Num, Middle, Many, Range, Temp;
	scanf("%d", &Num);
	
	int Average = 0;
	
	int NumArray[ NUMBER ] = {0};
	for ( int I = 0; I < Num; I++ )
	{
		scanf("%d", &Temp);
		Temp += 4000;
		NumArray[ Temp ]++;
		Average += Temp;
	}
	Average = Average;
	return 0;	
}
