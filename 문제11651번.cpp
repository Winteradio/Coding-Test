#include <stdio.h>

struct POS
{
	int X;
	int Y;
};

void Sort( POS* Data, int Size, int Start, int End )
{
	POS* Temp = new POS[ Size ];
	
	int Middle = ( Start + End ) / 2;
	
	int T_Start = Start;
	int L_Start = Start;
	int R_Start = Middle + 1;
	
	int Index;
	
	while( T_Start <= End )
	{
		if ( L_Start > Middle )
		{
			Index = R_Start;
			R_Start++;
		}
		else if ( R_Start > End )
		{
			Index = L_Start;
			L_Start++;
		}
		else
		{
			if ( Data[ L_Start ].Y > Data[ R_Start].Y )
			{
				Index = R_Start;
				R_Start++;
			}
			else if ( Data[ L_Start ].Y == Data[ R_Start].Y )
			{
				if ( Data[ L_Start ].X > Data[ R_Start ].X )
				{
					Index = R_Start;
					R_Start++;
				}
				else if ( Data[ L_Start ].X < Data[ R_Start ].X)
				{
					Index = L_Start;
					L_Start++;
				}
			}
			else if ( Data[ L_Start ].Y < Data[ R_Start ].Y )
			{
				Index = L_Start;
				L_Start++;
			}
		}
		Temp[ T_Start ] = Data[ Index ];
		T_Start++;
	}
	
	for ( int I = Start; I <= End; I++ )
	{
		Data[ I ] = Temp[ I ];
	}
	
	delete Temp;
}

void Merge( POS* Data, int Size, int Start, int End )
{
	int Middle = ( Start + End ) / 2;
	if ( Start != End )
	{
		Merge( Data, Size, Start, Middle );
		Merge( Data, Size, Middle + 1, End );
	}
	else
	{
		return ;
	}
	
	Sort( Data, Size, Start, End );
}

int main()
{
	int Num;
	scanf("%d", &Num);
	POS* Data = new POS[Num];
	for ( int I = 0; I < Num; I++ )
	{
		scanf("%d %d", &Data[I].X, &Data[I].Y );
	}	
	
	Merge( Data, Num, 0, Num - 1);
	
	for ( int I = 0; I < Num; I++ )
	{
		printf("%d %d\n", Data[I].X, Data[I].Y);
	} 
	
	delete Data;
	return 0;
}
