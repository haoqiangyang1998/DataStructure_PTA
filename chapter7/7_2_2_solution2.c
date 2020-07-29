//
//
//#include<stdio.h>
//#include<stdlib.h>
//
//void Swap(int *a, int *b)
//{
//    int tmp = *a; *a = *b; *b = tmp;
//}
//
//void InsertionSortOneStep(int *P, int i, int N)
//{
//    int j;
//    int tmp = P[i];
//    for(j=i; j>0; j--)
//    {
//        if(tmp<P[j-1])
//            P[j] = P[j-1];
//        else
//            break;
//    }
//    P[j] = tmp;
//}
//
//void ScanNumber(int *P, int N)
//{
//    for(int i=0; i<N; i++)
//        scanf("%d", &P[i]);
//}
//
//
//
//void ShowResult(int *P ,int N)
//{
//    printf("%d", P[0]);
//    for(int i=1; i<N; i++)
//        printf(" %d", P[i]);
//}
//
//
//void PerDown(int *P, int i, int N)
//{
//    int Child;
//    int tmp = P[i];
//    for(; 2*i+1<N; i=Child)
//    {
//        Child = 2*i+1;
//        if(P[Child]<P[Child+1] && Child!=N-1)
//            Child++;
//        if(tmp<P[Child])
//            P[i] = P[Child];
//        else
//            break;
//    }
//    P[i] = tmp;
//}
//
//int FindBeginIndex(int *CP, int N)
//{
//    for(int i=1; i<N; i++)
//    {
//        if(CP[i]<CP[i-1])
//            return i;
//    }
//}
//
//int FindHeapBeginIndex(int *CP, int N)
//{
//    for(int i=N-1; i>=0; i--)
//    {
//        if(CP[i]<CP[0])
//            return i;
//    }
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N;
//    scanf("%d", &N);
//    int *P = (int *)malloc(N*sizeof(int));
//    ScanNumber(P, N);
//
//    int *CP = (int *)malloc(N*sizeof(int));
//    ScanNumber(CP, N);
//
//
//    //InsertionSort Test
//    int k = FindBeginIndex(CP, N);
//    int i;
//    int flag = 0;
//    for(i=k; i<N; i++)
//    {
//        if(P[i]!=CP[i])
//        {
//            flag = 1;
//            break;
//        }
//    }
//
//    if(flag == 0)
//    {
//        printf("Insertion Sort\n");
//        InsertionSortOneStep(CP, k, N);
//        ShowResult(CP, N);
//    }
//    else
//    {
//        printf("Heap Sort\n");
//        k = FindHeapBeginIndex(CP, N);
//        Swap(&CP[k], &CP[0]);
//        PerDown(CP, 0, k);
//        ShowResult(CP, N);
//    }
//
//
//    return 0;
//}
