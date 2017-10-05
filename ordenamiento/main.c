#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector [5]={3,1,4,9,5};
    int aux;
    int i;
    int j;
    for (i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if (vector[i]<vector[j])
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
    for (i=0;i<5;i++)
    {
        printf("%d",vector[i]);
    }
    return 0;
}
