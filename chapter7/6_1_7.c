//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAXN 1000
//#define INFINITY 100000
//#define ERROR -1
//
//
//typedef int Vertex;
//typedef int WeightType;
//
//typedef struct AdjVNode *PtrToAdjVNode;
//struct AdjVNode
//{
//    Vertex AdjV;
//    WeightType Weight;
//    PtrToAdjVNode Next;
//};
//
//
//typedef struct VNode
//{
//    PtrToAdjVNode FirstEdge;
//}AdjList[MAXN];
//
//typedef struct GNode *LGraph;
//struct GNode
//{
//    int Nv;
//    int Ne;
//    AdjList G;
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
//LGraph CreateGraph(int VertexNum)
//{
//    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
//    Graph->Nv = VertexNum;
//    Graph->Ne = 0;
//
//    Vertex i;
//    for(i=0; i<Graph->Nv; i++)
//    {
//        Graph->G[i].FirstEdge = NULL;
//    }
//
//    return Graph;
//}
//
//void InsertEdge(LGraph Graph, Edge E)
//{
//    PtrToAdjVNode NewEdge = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
//    NewEdge->AdjV = E->V2;
//    NewEdge->Weight = E->W;
//    NewEdge->Next = Graph->G[E->V1].FirstEdge;
//    Graph->G[E->V1].FirstEdge = NewEdge;
//
//    NewEdge = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
//    NewEdge->AdjV = E->V1;
//    NewEdge->Weight = E->W;
//    NewEdge->Next = Graph->G[E->V2].FirstEdge;
//    Graph->G[E->V2].FirstEdge = NewEdge;
//}
//
//LGraph BuildGraph(int VertexNum, int EdgeNum)
//{
//    LGraph Graph = CreateGraph(VertexNum);
//    Graph->Ne = EdgeNum;
//
//    if(Graph->Ne != 0)
//    {
//        int i;
//        Edge E = (Edge)malloc(sizeof(struct ENode));
//        for(i=0; i<Graph->Ne; i++)
//        {
//            scanf("%d %d %d", &E->V1, &E->V2, &E->W);
//            E->V1--;
//            E->V2--;
//            InsertEdge(Graph, E);
//        }
//    }
//
//    return Graph;
//}
//
//Vertex FindMinDist(LGraph Graph, WeightType *dist)
//{
//    Vertex i,MinV;
//    WeightType MinDist = INFINITY;
//    for(i=0; i<Graph->Nv; i++)
//    {
//        if(dist[i] != 0 && dist[i]<MinDist)
//        {
//            MinDist = dist[i];
//            MinV = i;
//        }
//    }
//    if(MinDist == INFINITY)
//        return ERROR;
//    else
//        return MinV;
//}
//
//WeightType Prim(LGraph Graph, LGraph MST)
//{
//    Vertex V;
//    //define and intialize, the start point is 0
//    WeightType *dist = (WeightType*)malloc(Graph->Nv*sizeof(WeightType));
//    Vertex *parent = (Vertex*)malloc(Graph->Nv*sizeof(Vertex));
//    for(V=0; V<Graph->Nv; V++)
//    {
//        dist[V] = INFINITY;
//        parent[V] = 0;
//    }
//
//    PtrToAdjVNode TmpE = Graph->G[0].FirstEdge;
//    while(TmpE != NULL)
//    {
//        dist[TmpE->AdjV] = TmpE->Weight;
//        TmpE = TmpE->Next;
//    }
//
//    int Vcount = 0;
//
//    dist[0] = 0;
//    parent[0] = -1;
//    Vcount++;
//
//    Edge E = (Edge)malloc(sizeof(struct ENode));
//    WeightType TotalWeight = 0;
//    while(1)
//    {
//        V = FindMinDist(Graph, dist);
//        if(V==ERROR)
//            break;
//
//        E->V1 = parent[V];
//        E->V2 = V;
//        E->W = dist[V];
//        InsertEdge(MST, E);
//        TotalWeight = TotalWeight + dist[V];
//
//        dist[V] = 0;
//        Vcount++;
//
//        //search the adjacent Vertexes of Vertex V
//        TmpE = Graph->G[V].FirstEdge;
//        while(TmpE != NULL)
//        {
//            if(TmpE->Weight < dist[TmpE->AdjV])     //update the dist[]
//            {
//                dist[TmpE->AdjV] = TmpE->Weight;
//                parent[TmpE->AdjV] = V;
//            }
//            TmpE = TmpE->Next;
//        }
//    }
//
//    if(Vcount < Graph->Nv)
//        TotalWeight = ERROR;
//    return TotalWeight;
//
//
//}
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    scanf("%d %d", &N, &M);
//    LGraph Graph = BuildGraph(N, M);
//    LGraph MST = CreateGraph(N);
//
//    WeightType TotalWeight = Prim(Graph, MST);
//    printf("%d", TotalWeight);
//
//
//    return 0;
//}
