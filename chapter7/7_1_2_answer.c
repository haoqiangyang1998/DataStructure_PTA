//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//
//void PrintResult(int *P, int N)
//{
//    for(int i=0; i<N; i++)
//    {
//        if(i==0)
//            printf("%d", P[i]);
//        if(i!=0)
//            printf(" %d", P[i]);
//    }
//}
//
//int IsInsertion(int *P, int *PMid, int N)
//{
//    int i;
//    for(i=0; i<N-1; i++)
//    {
//        if(PMid[i]>PMid[i+1])
//            break;
//    }
//    for(int j=i+1; j<N; j++)
//    {
//        if(P[j]!=PMid[j])
//            return 0;
//    }
//  //finishing the sort is impossible, beacause the InsertionSort is the same as MergeSort in this situation
//        return i;
//
//}
//
//void NextInsertion(int *PMid, int k, int N)
//{
//    printf("Insertion Sort\n");
//    int i;
//    int tmp = PMid[k+1];
//    for(i=k+1; i>0 && PMid[i-1]>tmp ; i--)
//        PMid[i] = PMid[i-1];
//    PMid[i] = tmp;
//    PrintResult(PMid, N);
//}
//
//int MergeLength(int *PMid, int N)
//{
//    int L,i;
//    for(L=2; L<N; L=2*L)
//    {
//        for(i=1; L*i<N; i+=2)
//        {
//            if(PMid[L*i-1]>PMid[L*i])
//                return L;
//        }
//    }
//}
//
//void Merge(int *A, int *tmpA, int L, int R, int RightEnd)
//{
//    int LeftEnd = R-1;
//    int tmpi = L;
//    while(L<=LeftEnd && R<=RightEnd)
//    {
//        if(A[L]>A[R])
//            tmpA[tmpi++] = A[R++];
//        else
//            tmpA[tmpi++] = A[L++];
//    }
//    for(; L<=LeftEnd; )    tmpA[tmpi++] = A[L++];
//    for(; R<=RightEnd; )   tmpA[tmpi++] = A[R++];
//
//}
//
//void NextMerge(int *PMid, int N)
//{
//    printf("Merge Sort\n");
//    int *tmpA = (int *)malloc(N*sizeof(int));
//
//    int L = MergeLength(PMid, N);
//
//    int i,j;
//    for(i=0; (i+1)*2*L-1<N ;i++)
//        Merge(PMid, tmpA, i*2*L, i*2*L+L, (i+1)*2*L-1);
//
//    if(i*2*L+L-1<N)     //one part is complete, and the other part is incomplete
//    {
//        Merge(PMid, tmpA, i*2*L, i*2*L+L, N-1);
//    }
//    if(i*2*L+L-1>=N)     //surplus part is incomplete
//    {
//        for(j=i*2*L; j<N; j++)
//            tmpA[j] = PMid[j];
//    }
//
//
//
//    PrintResult(tmpA, N);
//
//    free(tmpA);
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N;
//    scanf("%d", &N);
//    int *P = (int *)malloc(N*sizeof(int));
//    int *PMid = (int *)malloc(N*sizeof(int));
//    for(int i=0; i<N; i++)
//        scanf("%d", &P[i]);
//    for(int i=0; i<N; i++)
//        scanf("%d", &PMid[i]);
//
//    int k = IsInsertion(P, PMid, N);
//    if(k)
//        NextInsertion(PMid, k, N);
//    else
//        NextMerge(PMid, N);
//    free(P);
//    free(PMid);
//
//    return 0;
//}
//
