#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define MAXN 100+1
#define INFINITY 10000

int JumpDist = 0;

typedef int Vertex;
typedef int WeightType;
typedef struct DataT DataType;
struct DataT
{
    int X;
    int Y;
};

typedef struct GNode *PtrToGNode;
typedef PtrToGNode MGraph;
struct GNode
{
    int Nv;
    WeightType G[MAXN][MAXN];
    DataType D[MAXN];
};

typedef struct TestNode *TestFE;
struct TestNode
{
    int Num;
    Vertex Arr[MAXN];
};

MGraph CreateGraph(int VertexNum)
{
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;

    Vertex i,j;
    for(i=0; i<Graph->Nv; i++)
        for(j=0; j<Graph->Nv; j++)
            Graph->G[i][j] = INFINITY;

    return Graph;
}

int IsEdge(DataType P1, DataType P2)
{
    int deltaX = P1.X - P2.X;
    int deltaY = P1.Y - P2.Y;

    if(deltaX*deltaX + deltaY*deltaY <= JumpDist*JumpDist)
        return 1;
    else
        return 0;
}

MGraph BuildGraph(int VertexNum)
{
    MGraph Graph = CreateGraph(VertexNum);
//    Graph->Date[0].X = 0;
//    Graph->Data[0].Y = 0;

    Vertex i,j;
    for(i=0; i<Graph->Nv; i++)
        scanf("%d %d", &Graph->D[i].X, &Graph->D[i].Y);

    for(i=0; i<Graph->Nv; i++)
    {
        Graph->G[i][i] = 0;

        for(j=i+1; j<Graph->Nv; j++)
        {
            if(IsEdge(Graph->D[i], Graph->D[j]))
            {
                Graph->G[i][j] = 1;
                Graph->G[j][i] = 1;
            }
        }
    }

    return Graph;
}

void Floyd(MGraph Graph, int Path[][MAXN], int Dist[][MAXN])
{
    Vertex i,j,k;
    for(i=0; i<Graph->Nv; i++)
    {
        for(j=0; j<Graph->Nv; j++)
        {
            Dist[i][j] = Graph->G[i][j];
            Path[i][j] = -1;
        }
    }

    for(k=0; k<Graph->Nv; k++)
        for(i=0; i<Graph->Nv; i++)
            for(j=0; j<Graph->Nv; j++)
    {
        if(Dist[i][k] + Dist[k][j] < Dist[i][j])
        {
            Dist[i][j] = Dist[i][k] + Dist[k][j];
            Path[i][j] = k;
        }
    }

}

TestFE SearchFirstJump(MGraph Graph)
{
    TestFE FirstJump = (TestFE)malloc(sizeof(struct TestNode));
    FirstJump->Num = 0;

    Vertex i;
    int deltaX, deltaY;
    for(i=0; i<Graph->Nv; i++)
    {
        deltaX = Graph->D[i].X;
        deltaY = Graph->D[i].Y;
        if(deltaX*deltaX + deltaY*deltaY < (JumpDist+7.5)*(JumpDist+7.5))
        {
            FirstJump->Arr[FirstJump->Num++] = i;
        }
    }

    return FirstJump;
}

TestFE SearchEndJump(MGraph Graph)
{
    TestFE EndJump = (TestFE)malloc(sizeof(struct TestNode));
    EndJump->Num = 0;

    Vertex i;
    int deltaX, deltaY;
    for(i=0; i<Graph->Nv; i++)
    {
        deltaX = Graph->D[i].X;
        deltaY = Graph->D[i].Y;
        if( Graph->D[i].X+JumpDist>=50 || Graph->D[i].X-JumpDist<=-50 || Graph->D[i].Y+JumpDist>=50 || Graph->D[i].Y-JumpDist<=-50)
        {
            EndJump->Arr[EndJump->Num++] = i;
        }
    }

    return EndJump;
}

int IsClose(MGraph Graph, Vertex V1, Vertex V2)
{
    if(pow(Graph->D[V1].X, 2) + pow(Graph->D[V1].Y, 2) < pow(Graph->D[V2].X, 2) + pow(Graph->D[V2].Y, 2))
        return 1;
    else
        return 0;
}

void PrintResult(MGraph Graph, int Path[][MAXN], Vertex Start, Vertex End)
{
    int k = Path[Start][End];
    if(k == -1)
    {
        printf("%d %d\n", Graph->D[Start].X, Graph->D[Start].Y);

    }
    else
    {
        PrintResult(Graph, Path, Start, k);
        PrintResult(Graph, Path, k, End);
    }
    //printf("%d %d\n", Graph->D[End].X, Graph->D[End].Y);
}

int main()
{
    freopen("yhq.txt", "r", stdin);
    int N;
    scanf("%d %d", &N, &JumpDist);
    //N = N+1;
    if(JumpDist >= 50-7.5)
    {
        printf("1\n");
        printf("0 0");
    }
    else
    {
        MGraph Graph = BuildGraph(N);
        int Path[MAXN][MAXN];
        int Dist[MAXN][MAXN];

        Floyd(Graph, Path, Dist);
        TestFE FirstJump = SearchFirstJump(Graph);
        TestFE EndJump = SearchEndJump(Graph);

        WeightType MinJumNum = INFINITY;
        Vertex MinStart, MinEnd;
        MinStart = 0;

        int i,j, FirstPoint, EndPoint;

        for(i=0; i<FirstJump->Num; i++)
        {
            FirstPoint = FirstJump->Arr[i];
            for(j=0; j<EndJump->Num; j++)
            {
                EndPoint = EndJump->Arr[j];
                if(Dist[FirstPoint][EndPoint] < MinJumNum)
                {
                    MinJumNum = Dist[FirstPoint][EndPoint];
                    MinStart = FirstPoint;
                    MinEnd = EndPoint;
                }
                else if(Dist[FirstPoint][EndPoint] == MinJumNum && IsClose(Graph, FirstPoint, MinStart))
                {
                    MinStart = FirstPoint;
                    MinEnd = EndPoint;
                }
            }
        }
        if(MinJumNum == INFINITY)
        {
            printf("0");
        }
        else
        {
            printf("%d\n", MinJumNum+2);
            PrintResult(Graph, Path, MinStart, MinEnd);
            printf("%d %d\n", Graph->D[MinEnd].X, Graph->D[MinEnd].Y);
        }

    }



    return 0;
}
