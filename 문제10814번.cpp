#include <stdio.h>
#define MAX 101

struct Member
{
	int Num;
	char Name[ MAX ];
	int Age;	
}; 



void Sort( Member* Data, int Size, int Start, int End )
{
	Member* Temp = new Member[ Size ];
	
	int Middle = ( Start + End ) / 2;
	
	int T_Start = Start;
	int L_Start = Start;
	int R_Start = Middle + 1;
	
	int Index;
	
	while ( T_Start <= End ) 
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
			if ( Data[ L_Start ].Age > Data[ R_Start ].Age )
			{
				Index = R_Start;
				R_Start++;
			}
			else if ( Data[ L_Start].Age == Data[ R_Start ].Age )
			{
				if ( Data[ L_Start ].Num > Data[ R_Start ].Num )
				{
					Index = R_Start;
					R_Start++;
				}
				else
				{
					Index = L_Start;
					L_Start++;
				}
			}
			else if ( Data[ L_Start ].Age < Data[ R_Start ].Age )
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

void Merge( Member* Data, int Size, int Start, int End )
{
	if ( Start != End )
	{
		int Middle = ( Start + End ) / 2;
		Merge( Data, Size, Start, Middle );
		Merge( Data, Size, Middle + 1, End );
	}
	else
	{
		return;
	}
	
	Sort( Data, Size, Start, End );
}

int main()
{
	int Num;
	scanf("%d", &Num);
	
	Member* members = new Member[ Num ];
	for ( int I = 0; I < Num; I++ )
	{
		members[ I ].Num = I;
		scanf("%d %s", &members[ I ].Age, &members[ I ].Name );
	}
	
	Merge( members, Num, 0, Num - 1 );
	
	for ( int I = 0; I < Num; I++ )
	{
		printf("%d %s\n", members[I].Age, members[I].Name);
	}
	
	delete members;
	
	return 0; 
}
