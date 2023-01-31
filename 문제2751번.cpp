#include <stdio.h>

void Sort( int* Array, int* TempArray, int Start, int End )
{
	int Real_Start = Start;
	int L_Start = Start;
	int L_End = ( End + Start ) / 2;
	int R_Start = ( End + Start ) / 2 + 1;
	int R_End = End;
	int Index;
	while( L_Start <= L_End || R_Start <= R_End )
	{
		if ( L_Start <= L_End && R_Start <= R_End )
		{
			if ( Array[ L_Start ] <= Array[ R_Start ] )
			{
				Index = L_Start;
				L_Start++;
			}
			else
			{
				Index = R_Start;
				R_Start++;
			}
		}
		else if ( L_Start <= L_End && R_Start > R_End )
		{
			Index = L_Start;
			L_Start++;
		}
		else if ( L_Start > L_End && R_Start <= R_End )
		{
			Index = R_Start;
			R_Start++;
		}
		TempArray[Start] = Array[ Index ];
		Start++;
	}
	
	for ( int I = Real_Start; I <= End; I++ )
	{
		Array[ I ] = TempArray[ I ];
	}
}

void Merge( int* Array, int* TempArray, int Start, int End )
{
	printf(" Start %d End %d\n", Start, End );
	if ( Start != End )
	{
		Merge( Array, TempArray, Start, ( End + Start ) / 2);
		Merge( Array, TempArray, ( End + Start ) / 2 + 1, End );
	}
	else
	{
		return ;
	}
	
	printf("Sorting! %d %d \n", Start, End );
	Sort( Array, TempArray, Start, End );
}

int main()
{
	int Num;
	scanf("%d", &Num);
	int* NumArray = new int[Num];
	int* TempArray = new int[Num];
	for ( int I = 0; I < Num; I++ )
	{
		scanf("%d", &NumArray[ I ] );
	}
	
	Merge( NumArray, TempArray, 0, Num-1 );
	
	for ( int I = 0; I < Num; I++ )
	{
		printf("%d\t", TempArray[ I ] );
	}
	
	return 0;
}
