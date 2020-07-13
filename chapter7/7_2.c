//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//
//void Swap(int *a, int *b)
//{
//    int tmp = *a; *a = *b; *b = tmp;
//}
//
//bool IsEqual(int *P, int *PMid, int N)
//{
//    for(int i=0; i<N; i++)
//    {
//        if(P[i] != PMid[i])
//            return false;
//    }
//    return true;
//}
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
//int InsertSortTest(int *P, int *PMid, int N)
//{
//    int i,j;
//    int flag = 0;
//    for(i=1; i<N; i++)
//    {
//        int tmp = P[i];
//        for(j=i-1; j>=0; j--)
//        {
//            P[j+1] = P[j];
//            if(P[j]<=tmp)
//                break;
//        }
//        Swap(&P[j+1], &tmp);
//        if(IsEqual(P, PMid, N))
//        {
//            printf("Insertion Sort\n");
//            flag = 1;
//            continue;
//        }
//        if(flag==1)
//        {
//            PrintResult(P, N);
//            return 1;
//        }
//
//    }
//    return 0;
//}
//
//void Merge(int *P, int *tmpP, int L, int R, int RightEnd)
//{
//    int LeftEnd = R-1;
//    int tmp = L;
//    int ElementN = RightEnd-L+1;
//    while(L<=LeftEnd && R<=RightEnd)
//    {
//        if(P[L]>P[R])
//            tmpP[tmp++] = P[R++];
//        else
//            tmpP[tmp++] = P[L++];
//    }
//    while(L<=LeftEnd) tmpP[tmp++] = P[L++];
//    while(R<=RightEnd) tmpP[tmp++] = P[R++];        //build the whole tmp[]
//
//    for(int i=0; i<ElementN; i++,RightEnd--)        //copy to P[]
//        P[RightEnd] = tmpP[RightEnd];
//}
//
//void Merge_pass(int A[], int TmpA[], int N, int length )
//{
//     int i, j;
//
//     for ( i=0; i <= N-2*length; i += 2*length )
//         Merge( A, TmpA, i, i+length, i+2*length-1 );
//     if ( i+length < N )
//         Merge( A, TmpA, i, i+length, N-1);
//     else
//         for ( j = i; j < N; j++ )
//            TmpA[j] = A[j];
//}
//
//int MergeSortTest(int A[], int *PMid, int N )
//{
//     int length;
//     int *TmpA;
//      int flag = 0;
//     length = 1;
//     TmpA = malloc( N * sizeof( int) );
//     if ( TmpA != NULL ) {
//          while( length < N ) {
//              Merge_pass( A, TmpA, N, length );
//              length *= 2;
//            if(IsEqual(A, PMid, N))
//            {
//                printf("Merge Sort\n");
//                flag = 1;
//                continue;
//            }
//            if(flag==1)
//            {
//                PrintResult(A, N);
//                return 1;
//            }
//          }
//          free( TmpA );
//     }
//     return 0;
//}
//
//int main()
//{
//    //freopen("yhq.txt", "r", stdin);
//    int N;
//    scanf("%d", &N);
//    int *P1 = (int *)malloc(N*sizeof(int));
//    int *P2 = (int *)malloc(N*sizeof(int));
//    int *PMid = (int *)malloc(N*sizeof(int));
//    for(int i=0; i<N; i++)
//    {
//        scanf("%d", &P1[i]);
//    }
//    for(int i=0; i<N; i++)
//        P2[i] = P1[i];
//    for(int i=0; i<N; i++)
//    {
//        scanf("%d", &PMid[i]);
//    }
//
//    if(!InsertSortTest(P1, PMid, N))
//        MergeSortTest(P2, PMid, N);
//
//    free(P1);
//    free(P2);
//    free(PMid);
//
//    return 0;
//}
