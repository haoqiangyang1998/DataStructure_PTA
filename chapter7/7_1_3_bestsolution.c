//
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//
//#define MAXN 1000000
//#define MAXM 10
//
//typedef int EleType;
//
//void Input(EleType *P, int N)
//{
//    for(int i=0; i<N; i++)
//        scanf("%d", &P[i]);
//}
//
//void PrintResults(EleType *P, int N)
//{
//    printf("%d", P[0]);
//    for(int i=1; i<N; i++)
//        printf(" %d", P[i]);
//}
//
//void Swap(EleType *A, EleType *B)
//{
//    EleType tmp = *A; *A = *B; *B = tmp;
//}
//
//void InsertionSort(EleType *P, int N)
//{
//    int i,j;
//    EleType tmp;
//    for(i=1; i<N; i++)
//    {
//        tmp = P[i];
//        for(j=i; j>0 && P[j-1]<tmp; j--)
//            P[j] = P[j-1];
//        P[j] = tmp;
//    }
//}
//
//void Adjust(EleType *P, int i, int N)
//{
//    int child;
//    EleType tmp;
//
//    for(tmp=P[i]; i*2+1<N; i=child)
//    {
//        child = 2*i+1;
//        if(child != N-1 && P[child]>P[child+1])        //build the minimal heap
//            child++;
//        if(tmp>P[child])
//            P[i] = P[child];
//        else
//            break;
//    }
//    P[i] = tmp;
//}
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    scanf("%d %d", &N, &M);
//    EleType *P = (EleType *)malloc(M*sizeof(EleType));
//    Input(P, M);
//
//    //build the minimal heap
//    int i;
//    for(i=(M-1)/2; i>=0; i--)
//        Adjust(P, i, M);
//
//    // input the rest of elements
//    EleType tmp;
//    for(i=M; i<N; i++)
//    {
//        scanf("%d", &tmp);
//        if(tmp>P[0])
//        {
//            P[0] = tmp;
//            Adjust(P, 0, M);
//        }
//    }
//
//    //adjust the heap's elements ranking from high to low
//    for(i=M-1; i>0; i--)
//    {
//        Swap(&P[0], &P[i]);
//        Adjust(P, 0, i);
//    }
//
//
//    if(M<N)
//        PrintResults(P, M);
//    else
//        PrintResults(P, N);
//
//    return 0;
//}
