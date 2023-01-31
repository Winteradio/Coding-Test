#include <stdio.h>

int main()
{
	int Num, CutNum, Temp;
	scanf("%d %d", &Num, &CutNum );
	
	int* NumArray = new int[Num];
	for ( int I = 0; I < Num; I++ )
	{
		scanf("%d", &NumArray[ I ] );
	}
	
	for ( int I = 0; I < Num; I++ )
	{
		for ( int J = I + 1; J < Num ; J++ )
		{
			if ( NumArray[ J ] >= NumArray[ I ] )
			{
				Temp = NumArray[ J ];
				NumArray[ J ] = NumArray[ I ];
				NumArray[ I ] = Temp;
			}
		}
	 }
	  
	printf("%d", NumArray[CutNum - 1]);
	return 0;
}
