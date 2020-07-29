//#include<stdio.h>
//#include<stdlib.h>
//
//#define INFINITY 1000000;
//
//typedef int WeightType;
//typedef int DataType;
//
//typedef struct GNode *PtrToGNode;
//typedef PtrToGNode MGraph;
//struct GNode
//{
//    int Nv;
//    int Ne;
//    WeightType **G;
//    DataType *Data
//};
//
//MGraph CreateGraph(int Nv)
//{
//    int i,j;
//    MGraph M = (MGraph)malloc(sizeof(struct GNode));
//    M->Nv = Nv;
//    M->Ne = 0;
//
//    M->G = (WeightType**)malloc(Nv*sizeof(WeightType*));        //row
//    for(i=0; i<Nv; i++)
//        M->G[i] = (WeightType *)malloc(Nv*sizeof(WeightType));  //column
//
//    M->Data = (DataType *)malloc(Nv*sizeof(DataType));
//
//    for(i=0; i<M->Nv; i++)
//    {
//        for(j=0; j<M->Nv; j++)
//            M->G[i][j] = INFINITY;
//    }
//
//    return M;
//}
//
//
//
//int main()
//{
//    int Nv;
//    scanf("%d", &Nv);
//    MGraph Graph = CreateGraph(Nv);
//    for(int i=0; i<Graph->Nv; i++)
//    {
//        for(int j=0; j<Graph->Nv; j++)
//            printf("%d ", Graph->G[i][j]);
//        printf("\n");
//    }
//
//
//    return 0;
//}
