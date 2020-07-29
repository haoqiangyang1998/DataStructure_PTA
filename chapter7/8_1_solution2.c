//
//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAXN 100000
//
//void InputCouple(int *CP, int N)
//{
//    int i;
//    for(i=0; i<MAXN; i++)
//    {
//        CP[i] = MAXN;   //Prevent array from crossing bounds
//    }
//
//
//    int couple1, couple2;
//    for(i=0; i<N; i++)
//    {
//        scanf("%d %d", &couple1, &couple2);
//        CP[couple1] = couple2;
//        CP[couple2] = couple1;
//    }
//}
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,M;
//    int *CP = (int *)malloc(MAXN*sizeof(int));
//    scanf("%d", &N);
//    InputCouple(CP, N);
//
//    scanf("%d", &M);
//    int B[MAXN+1] = {0};
//    int i,tmp;
//    for(i=0; i<M; i++)
//    {
//        scanf("%d", &tmp);
//        B[tmp] = 1;
//    }
//
//    //
//    int count = 0;
//    int out[MAXN];
//    for(i=0; i<MAXN; i++)
//    {
//        if(B[i]!=0 && B[CP[i]] == 0)
//        {
//            out[count] = i;
//            count++;
//        }
//    }
//
//    printf("%d\n", count);
//
//    for(i=0; i<count; i++)
//    {
//        if(i==0)
//            printf("%05d", out[i]);
//        else
//            printf(" %05d", out[i]);
//    }
//
//
//    return 0;
//}
