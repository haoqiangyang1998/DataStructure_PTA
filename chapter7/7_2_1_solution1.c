//#include<stdio.h>
//#include<stdlib.h>
//
//void InputNumber(int *P, int N)
//{
//    int i;
//    for(i=0; i<N; i++)
//    {
//        scanf("%d", &P[i]);
//    }
//}
//
//int compareID(const void *a, const void *b)
//{
//    int k = *((const int *)a) - *((const int *)b);
//    return -k;
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    scanf("%d", &N);
//    int *PN = (int *)malloc(N*sizeof(int));
//    InputNumber(PN, N);
//
//    scanf("%d", &M);
//    int *PM = (int *)malloc(M*sizeof(int));
//    InputNumber(PM, M);
//
//    qsort(PN, N, sizeof(int), compareID);
//    qsort(PM, M, sizeof(int), compareID);
//
//    int i;
//    int sum = 0;
//    int tmp;
//
//    int tag = N>M?M:N;      //get the min
//    for(i=0; i<tag; i++)
//    {
//        tmp = PN[i]*PM[i];
//        if(tmp>0)
//            sum = sum + tmp;
//        else
//            break;
//    }
//
//    if(i!=tag)
//    {
//
//    int countN = N-1;
//    int countM = M-1;
//    tmp = PN[countN]*PM[countM];
//    while(tmp>0)
//    {
//        sum = sum + tmp;
//        countM--;
//        countN--;
//
//        tmp = PN[countN]*PM[countM];
//    }
//
//    }
//
//    printf("%d", sum);
//}
