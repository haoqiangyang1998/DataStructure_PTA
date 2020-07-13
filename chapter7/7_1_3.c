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
//void SelectionSort(EleType *P, int N)
//{
//    int i,j,Max;
//    for(i=0; i<N; i++)
//    {
//        Max = i;
//        for(j=i; j<N; j++)
//        {
//            if(P[j]>P[Max])
//                Max = j;
//        }
//        Swap(&P[i], &P[Max]);
//    }
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
//void BubbleSort(EleType *P, int N)
//{
//    int i,j;
//    bool flag;
//    for(i=0; i<N; i++)
//    {
//        flag = false;
//        for(j=1; j<N-i; j++)
//        {
//            if(P[j-1]<P[j])
//            {
//                Swap(&P[j-1], &P[j]);
//                flag = true;
//            }
//        }
//        if(flag==false)
//            break;
//    }
//}
//
//void QuickSort(EleType *P, int N)
//{
//    QSort(P, 0, N-1);
//}
//
//EleType median3(EleType *P, int Left, int Right)
//{
//    int center = (Left+Right)/2;
//    if(P[Left]<P[center])
//        Swap(&P[Left], &P[center]);
//    if(P[Left]<P[Right])
//        Swap(&P[Left], &P[Right]);
//    if(P[center]<P[Right])
//        Swap(&P[center], &P[Right]);
//
//    Swap(&P[center], &P[Right-1]);
//    return P[Right-1];
//}
//
//void QSort(EleType *P, int Left, int Right)
//{
//    int cutoff = 3;
//    if(cutoff<=Right-Left)
//    {
//        int i = Left;
//        int j = Right-1;
//        EleType pivot;
//        pivot = median3(P, Left, Right);
//
//        while(1)
//        {
//            while(P[i]>=pivot) i++;
//            while(P[j]<=pivot) j--;
//            if(i<j)
//                Swap(&P[i], &P[j]);
//            else
//                break;
//        }
//        Swap(&P[i], &P[Right-1]);
//        QSort(P, Left, i-1);
//        QSort(P, i+1, Right);
//    }
//    else
//        SelectionSort(&P[Left], Right-Left+1);
//}
//
//
//int CompareMoney(const void *a, const void *b)
//{
//    int k = *((const EleType *) a) -  *((const EleType *) b);
//    return -k;
//}
//
//
//
//
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    scanf("%d %d", &N, &M);
//    EleType *P = (EleType *)malloc(N*sizeof(EleType));
//    Input(P, N);
//
//
//    //SelectionSort(P, N);
//    //InsertionSort(P, N);
//    //BubbleSort(P, N);
//    QuickSort(P, N);
//    //qsort(P, N, sizeof(EleType), CompareMoney);
//
//    if(M<N)
//        PrintResults(P, M);
//    else
//        PrintResults(P, N);
//
//    return 0;
//}
