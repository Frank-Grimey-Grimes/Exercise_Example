#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TransponeSquareMatrix(const void**,const int,const int);

int main()
{
    int **matrix=malloc(sizeof(int*)*3);
    int i,j;
    for(i=0;i<3;i++)
    {
        *(matrix+i)=malloc(sizeof(int)*3);
    }
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            *(*(matrix+i)+j)=(i+1)*(j+1);
        }
    }
    *(*(matrix+1))=8;
    *(*(matrix+2))=7;
    *(*(matrix+2)+1)=5;
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",*(*(matrix+j)+i));
        }
        puts("");
    }
    TransponeSquareMatrix(matrix,3,sizeof(int));
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",*(*(matrix+i)+j));
        }
        puts("");
    }
    free(*(matrix));
    free(*(matrix+1));
    free(*(matrix+2));
    free(matrix);
    return 0;
}

void TransponeSquareMatrix(const void** matrix,const int MatrixSize, const int SizeOfElementInBytes)
{
    int i,j,sizeOfPointerInBytes=sizeof(void*),sizeOfRowInBytes=MatrixSize*SizeOfElementInBytes;
    void *aux=malloc(SizeOfElementInBytes);
    for(j=0;j<MatrixSize;j++)
    {
        for(i=0;i<0+j;i++)
        {
            memcpy(aux,(*(matrix+(i*(sizeOfPointerInBytes+sizeOfRowInBytes)))+(j*SizeOfElementInBytes)),SizeOfElementInBytes);
            memcpy((*(matrix+(i*(sizeOfPointerInBytes+sizeOfRowInBytes)))+(j*SizeOfElementInBytes)),(*(matrix+(j*(sizeOfPointerInBytes+sizeOfRowInBytes)))+(i*SizeOfElementInBytes)),SizeOfElementInBytes);
            memcpy((*(matrix+(j*(sizeOfPointerInBytes+sizeOfRowInBytes)))+(i*SizeOfElementInBytes)),aux,SizeOfElementInBytes);
        }
    }
    return;
}
