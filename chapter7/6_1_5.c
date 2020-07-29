//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//#define INFINITY 100000
//#define ERROR -2
//
//typedef int Vertex;
//
//struct Weight
//{
//    int Length;
//    int Fee;
//};
//typedef struct Weight WeightType;
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
//        {
//            Graph->G[i][j].Length = INFINITY;
//            Graph->G[i][j].Fee = INFINITY;
//        }
//
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
//        scanf("%d %d %d %d", &E->V1, &E->V2, &E->W.Length, &E->W.Fee);
//        InsertEdge(Graph, E);
//    }
//
//    return Graph;
//}
//
//Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
//{
//    Vertex MinV, V;
//    int MinDist = INFINITY;
//    for(V=0; V<Graph->Nv; V++)
//    {
//        if(collected[V] == 0 && dist[V]<MinDist)
//        {
//            MinDist = dist[V];
//            MinV = V;
//        }
//    }
//
//    if(MinDist == INFINITY)
//        return ERROR;
//
//    return MinV;
//
//}
//
//bool Dijkstra(MGraph Graph, int dist[], int path[], int cost[], Vertex S)
//{
//    int *collected = (int *)malloc(Graph->Nv*sizeof(int));
//
//    Vertex V;
//    for(V=0; V<Graph->Nv; V++)
//    {
//        dist[V] = Graph->G[S][V].Length;
//        cost[V] = Graph->G[S][V].Fee;
//        if(dist[V] < INFINITY)
//            path[V] = S;
//        else
//            path[V] = -1;
//        collected[V] = 0;
//    }
//    dist[S] = 0;
//    collected[S] = 1;
//
//
//    Vertex W;
//    while(1)
//    {
//        V = FindMinDist(Graph, dist, collected);
//        if(V == ERROR)
//            break;
//        collected[V] = 1;
//        for(W=0; W<Graph->Nv; W++)
//        {
//            if(collected[W] == 0 && Graph->G[W][V].Length < INFINITY)
//            {
//                if(Graph->G[W][V].Length<0)
//                    return false;
//                if(dist[W] > dist[V]+Graph->G[W][V].Length || (dist[W] == dist[V]+Graph->G[W][V].Length && cost[W] > cost[V]+Graph->G[W][V].Fee))
//                {
//                    dist[W] = dist[V]+Graph->G[W][V].Length;
//                    cost[W] = cost[V]+Graph->G[W][V].Fee;
//                    path[W] = V;
//                }
//            }
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    Vertex S,D;
//    scanf("%d %d %d %d", &N, &M, &S, &D);
//    MGraph Graph = BuildGraph(N, M);
//
//    int *dist = (int *)malloc(Graph->Nv * sizeof(int));
//    int *cost = (int *)malloc(Graph->Nv * sizeof(int));
//    int *path = (int *)malloc(Graph->Nv * sizeof(int));
//
//    Dijkstra(Graph, dist, path, cost, S);
//    printf("%d %d", dist[D], cost[D]);
//
//    return 0;
//}
