#include <stdio.h>
#include <string.h>
#define MAX 10

void Sort( int* Array, int Size, int Start, int End )
{
	int* Temp = new int[ Size ];
	
	int T_Start = Start;
	int T_End = End;
	
	int L_Start = Start;
	int L_End = ( End + Start ) / 2;
	int R_Start = ( End + Start ) / 2 + 1;
	int R_End = End;
	int Index;
	
	while( T_Start <= T_End )
	{
		if ( L_Start > L_End )
		{
			Index = R_Start;
			R_Start++;
		}
		else if ( R_Start > R_End )
		{
			Index = L_Start;
			L_Start++;
		}
		else 
		{
			if ( Array[ L_Start ] >= Array[ R_Start ] )
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
		Temp[ T_Start ] = Array[ Index ];
		T_Start++;
	}
	
	for ( int I = Start; I <= End; I++ )
	{
		Array[ I ] = Temp [ I ];
	}
}

void Merge( int* Array, int Size, int Start, int End )
{
	int Middle = ( Start + End ) / 2;
	if ( Start != End )
	{
		Merge( Array, Size, Start, Middle );
		Merge( Array, Size, Middle + 1, End );
	}
	else
	{
		return;
	}
	
	Sort( Array, Size, Start, End );
}

int main()
{
	char Data[10];
	scanf("%s", &Data);
	
	int Size = strlen( Data );
	int* NumArray = new int[ Size ];
	for ( int I = 0; I < Size; I++ )
	{
		NumArray[ I ] = Data[ I ] - '0';
	}
	
	
	Merge( NumArray, Size, 0, Size - 1);
	
	for ( int I = 0; I < Size; I++ )
	{
		printf("%d", NumArray[ I ] );
	}
	
	return 0;
}
