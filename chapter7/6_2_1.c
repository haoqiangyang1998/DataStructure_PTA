//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAXN 10
//#define INFINITY 100000
//#define MAXSIZE 10+1
//
//typedef int WeightType;
//typedef int Vertex;
//
//typedef struct QNode *Queue;
//struct QNode
//{
//    int Start;
//    int End;
//    Vertex Arr[MAXSIZE];
//};
//
//
//typedef struct GNode *PtrToGNode;
//typedef PtrToGNode MGraph;
//struct GNode
//{
//    int Nv;
//    int Ne;
//    WeightType G[MAXN][MAXN];
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
//    Vertex i,j;
//    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
//    Graph->Nv = VertexNum;
//    Graph->Ne = 0;
//    for(i=0; i<Graph->Nv; i++)
//        for(j=0; j<Graph->Nv; j++)
//            Graph->G[i][j] = INFINITY;
//
//    return Graph;
//}
//
//void InsertEdge(MGraph Graph, Edge E)
//{
//    Graph->G[E->V1][E->V2] = E->W;
//    Graph->G[E->V2][E->V1] = E->W;
//}
//
//MGraph BuildGraph(int VertexNum, int EdgeNum)
//{
//    MGraph Graph = CreateGraph(VertexNum);
//    Graph->Ne = EdgeNum;
//
//    int i;
//    Edge E = (Edge)malloc(sizeof(struct ENode));
//    for(i=0; i<Graph->Ne; i++)
//    {
//        scanf("%d %d", &E->V1, &E->V2);
//        E->W = 1;
//        InsertEdge(Graph, E);
//    }
//
//    return Graph;
//}
//
//void Visit(Vertex i)
//{
//    printf("%d ", i);
//}
//
//int Visited[MAXN] = {0};
//void DFS(MGraph Graph, Vertex V, void (*Visit)(Vertex))
//{
//    Visit(V);
//    Visited[V] = 1;
//
//    Vertex W;
//    for(W=0; W<Graph->Nv; W++)
//    {
//        if(!Visited[W] && Graph->G[V][W] != INFINITY)
//            DFS(Graph, W, Visit);
//    }
//
//}
//
//Queue CreateQueue()
//{
//    Queue Q = (Queue)malloc(sizeof(struct QNode));
//    Q->Start = 0;
//    Q->End = 0;
//    return Q;
//}
//
//void AddQ(Queue Q, Vertex V)
//{
//    Q->Arr[Q->End++] = V;
//    if(Q->End >= MAXSIZE)
//        Q->End = Q->End % MAXSIZE;
//}
//
//Vertex DeleteQ(Queue Q)
//{
//    Vertex tmp = Q->Arr[Q->Start++];
//    if(Q->Start >= MAXSIZE)
//        Q->Start = Q->Start % MAXSIZE;
//    return tmp;
//}
//
//int IsEmptyQ(Queue Q)
//{
//    if(Q->Start == Q->End)
//        return 1;
//    else
//        return 0;
//}
//
//void BFS(MGraph Graph, Vertex V, void (*Visit)(Vertex))
//{
//    Visit(V);
//    Visited[V] = 1;
//
//    Queue Q = CreateQueue();
//    AddQ(Q, V);
//
//    Vertex tmpV,i;
//    while(!IsEmptyQ(Q))
//    {
//        tmpV = DeleteQ(Q);
//        for(i=0; i<Graph->Nv; i++)
//        {
//            if( Graph->G[tmpV][i] != INFINITY && !Visited[i] )
//            {
//                Visit(i);
//                Visited[i] = 1;
//                AddQ(Q, i);
//            }
//        }
//    }
//
//
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    scanf("%d %d", &N, &M);
//    MGraph Graph = BuildGraph(N, M);
//
//    Vertex StartPoint = 0;
//    while(StartPoint < Graph->Nv)
//    {
//        if(Visited[StartPoint] == 0)
//        {
//            printf("{ ");
//            DFS(Graph, StartPoint, Visit);
//            printf("}\n");
//        }
//        StartPoint++;
//    }
//
//    //clear the Visited[]
//    for(StartPoint = 0; StartPoint<Graph->Nv; StartPoint++)
//        Visited[StartPoint] = 0;
//
//    StartPoint = 0;
//    while(StartPoint < Graph->Nv)
//    {
//        if(Visited[StartPoint] == 0)
//        {
//            printf("{ ");
//            BFS(Graph, StartPoint, Visit);
//            printf("}\n");
//        }
//        StartPoint++;
//    }
//
//
//
//
//    return 0;
//}
