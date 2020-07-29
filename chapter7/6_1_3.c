//#include<stdio.h>
//#include<stdlib.h>
//
//#define INFINITY 100000
//#define MAXN 1000
//
//typedef int Vertex;
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
//    DataType *Data;     //calculate the degree of vertex
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
//    int i,j;
//    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
//    Graph->Nv = VertexNum;
//    Graph->G = (WeightType **)malloc(Graph->Nv*sizeof(WeightType *));
//    for(i=0; i<Graph->Nv; i++)
//    {
//        Graph->G[i] = (WeightType*)malloc(Graph->Nv*sizeof(WeightType));
//    }
//
//    for(i=0; i<Graph->Nv; i++)
//    {
//        for(j=0; j<Graph->Nv; j++)
//            Graph->G[i][j] = INFINITY;
//    }
//
//    Graph->Data = (DataType *)malloc(Graph->Nv*sizeof(DataType));
//    for(i=0; i<Graph->Nv; i++)
//        Graph->Data[i] = 0;
//
//    return Graph;
//}
//
//void InsertEdge(MGraph Graph, Edge E)
//{
//    Graph->G[E->V1][E->V2] = E->W;
//    Graph->G[E->V2][E->V1] = E->W;
//    Graph->Data[E->V1]++;
//    Graph->Data[E->V2]++;
//}
//
//MGraph BuildGraph()
//{
//    int i,N,M;
//    scanf("%d %d", &N, &M);
//    MGraph Graph = CreateGraph(N);
//    Graph->Ne = M;
//
//    if(Graph->Ne != 0)
//    {
//        Edge E = (Edge)malloc(sizeof(struct ENode));
//        for(i=0; i<Graph->Ne; i++)
//        {
//            scanf("%d %d", &E->V1, &E->V2);
//            E->V1--;
//            E->V2--;
//            E->W = 1;
//            InsertEdge(Graph, E);
//        }
//    }
//
//    return Graph;
//
//}
//
//
//
//int *Visited;
//
//void DFS(MGraph Graph, Vertex V)
//{
//    Visited[V] = 1;
//    int i;
//    for(i=0; i<Graph->Nv; i++)
//    {
//        if(Graph->G[V][i] == 1 && Visited[i] == 0)     //V is adjacent to i, and i is not visited
//        {
//            DFS(Graph, i);
//        }
//    }
//}
//
//
//int main()
//{
//    int i;
//    freopen("yhq.txt", "r", stdin);
//    MGraph Graph = BuildGraph();
//    Visited = (int *)malloc(Graph->Nv*sizeof(int));
//    for(i=0; i<Graph->Nv; i++)
//        Visited[i] = 0;
//
//
//    DFS(Graph, 0);
//    int flag;
//    flag = 1;
//    for(i=0; i<Graph->Nv; i++)
//    {
//        if(Visited[i] == 0 || Graph->Data[i]==0 || Graph->Data[i]%2 != 0)
//        {
//            flag = 0;
//            break;
//        }
//
//    }
//    printf("%d", flag);
//
//    return 0;
//}
