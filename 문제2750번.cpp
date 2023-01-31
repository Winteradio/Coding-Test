#include <stdio.h>

int main()
{
    int Num;
    scanf("%d", &Num);
    int* NumArray = new int[ Num ];
    for ( int I = 0; I < Num; I++ )
    {
        scanf("%d", &NumArray[I] );
    }
    
    int Temp;
    for ( int I = 1; I < Num; I++ )
    {
        for ( int J = 0; J < I; J++ )
        {
            if ( NumArray[ I ] > NumArray[ J ] )
            {
                Temp = NumArray[ J ];
                NumArray[ J ] = NumArray[ I ];
                NumArray[ I ] = Temp;
            }
        }
    }
    
    for ( int I = 0; I < Num; I++ )
    {
        printf("%d\n", NumArray[ I ]);
    }
    
    return 0;
}
