//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//#define INFINITY 100000
//#define ERROR -2
//
//typedef int Vertex;
//typedef int WeightType;
//
//typedef struct GNode *PtrToGNode;
//typedef PtrToGNode MGraph;
//struct GNode
//{
//    int Nv;
//    int Ne;
//    WeightType **G;
//};
//
//typedef struct ENode *PtrToENode;
//typedef PtrToENode Edge;
//struct ENode
//{
//    Vertex V1, V2;
//    WeightType W;
//};
//
//MGraph CreateGraph(int VertexNum)
//{
//    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
//    Graph->Nv = VertexNum;
//    //allocate the room
//    int i,j;
//    Graph->G = (WeightType **)malloc(Graph->Nv*sizeof(WeightType *));
//    for(i=0; i<Graph->Nv; i++)
//    {
//        Graph->G[i] = (WeightType *)malloc(Graph->Nv*sizeof(WeightType));
//    }
//    //initial
//    for(i=0; i<Graph->Nv; i++)
//        for(j=0; j<Graph->Nv; j++)
//            Graph->G[i][j] = INFINITY;
//
//    return Graph;
//}
//
//void InsertEdge(MGraph Graph, Edge E)
//{
//    Graph->G[E->V1][E->V2] = E->W;  //can assign it directly
//    Graph->G[E->V2][E->V1] = E->W;
//}
//
//MGraph BuildGraph(int VertexNum, int EdgeNum)
//{
//    MGraph Graph = CreateGraph(VertexNum);
//    Graph->Ne = EdgeNum;
//
//    Edge E = (Edge)malloc(sizeof(struct ENode));
//    int i;
//    for(i=0; i<Graph->Ne; i++)
//    {
//        scanf("%d %d %d", &E->V1, &E->V2, &E->W);
//        E->V1--;
//        E->V2--;
//        InsertEdge(Graph, E);
//    }
//
//    return Graph;
//}
//
//bool Floyd(MGraph Graph, WeightType **D, Vertex **Path)
//{
//    Vertex i,j,k;
//    //initial
//    for(i=0; i<Graph->Nv; i++)
//        for(j=0; j<Graph->Nv; j++)
//    {
//        //if(i == j)
//       //     D[i][j] = 0;
//       // else
//            D[i][j] = Graph->G[i][j];
//        Path[i][j] = -1;
//    }
//
//    for(k=0; k<Graph->Nv; k++)
//        for(j=0; j<Graph->Nv; j++)
//            for(i=0; i<Graph->Nv; i++)
//    {
//        if(D[i][k]+D[k][j] < D[i][j])
//        {
//            D[i][j] = D[i][k]+D[k][j];
//            if(i==j && D[i][j] < 0)
//                return false;
//            Path[i][j] = k;
//        }
//    }
//
//    return true;
//}
//
//WeightType FindMaxWeight(MGraph Graph, WeightType **D, Vertex i)
//{
//    Vertex j;
//    WeightType MaxW = 0;
//    for(j=0; j<Graph->Nv; j++)
//    {
//        if(D[i][j] > MaxW)
//            MaxW  = D[i][j];
//    }
//    return MaxW;
//}
//
//void PrintResult(MGraph Graph, WeightType **D)
//{
//    Vertex i,MinV;
//    WeightType MinRow, tmp;
//    MinRow = INFINITY;
//
//    for(i=0; i<Graph->Nv; i++)
//    {
//        tmp = FindMaxWeight(Graph, D, i);
//        if(tmp < MinRow)
//        {
//            MinRow = tmp;
//            MinV = i;
//        }
//    }
//
//    if(MinRow == INFINITY)
//        printf("0");
//    else
//        printf("%d %d", MinV+1, MinRow);
//
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M,i;
//
//    scanf("%d %d", &N, &M);
//    MGraph Graph = BuildGraph(N, M);
//
//    WeightType **D = (WeightType **)malloc(Graph->Nv*sizeof(WeightType *));
//    Vertex **Path = (Vertex **)malloc(Graph->Nv*sizeof(Vertex *));
//    for(i=0; i<Graph->Nv; i++)
//    {
//        D[i] = (WeightType *)malloc(Graph->Nv*sizeof(WeightType));
//        Path[i] = (Vertex *)malloc(Graph->Nv*sizeof(Vertex));
//    }
//
//    Floyd(Graph, D, Path);
//    PrintResult(Graph, D);
//
//
//    return 0;
//}
//
