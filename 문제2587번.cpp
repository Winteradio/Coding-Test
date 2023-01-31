#include <stdio.h>

int main()
{
	int Average = 0, Middle, Temp;
	
	int Num[5] = {0};
	for ( int i=0;i<5;i++)
	{
		scanf("%d", &Num[i]);
		Average += Num[ i ];
	}
	
	for ( int i =0; i < 5; i++ )
	{
		for ( int j = 0; j < 4 - i; j++ )
		{
			if ( Num[ j+1 ] <= Num[ j ])
			{
				Temp = Num[ j ];
				Num[j] = Num[j+1];
				Num[j+1] = Temp;
			}
		}
	}
	
	Middle = Num[2];
	printf("%d\n", Average / 5);
	printf("%d", Middle);
	return 0;
 } 
