//#include<stdio.h>
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
//int FindNextIndex(int *P, int begin, int N)
//{
//    int i;
//    for(i=begin; i<N; i++)
//    {
//        if(P[i]!=i)
//            return P[i];
//    }
//    return -1;
//}
//
//int BasicCount(int *P, int N)
//{
//    int i,count;
//    count = 0;
//    for(i=0; i<N; i++)
//    {
//        if(P[i]!=i)
//            count++;
//    }
//    return count;
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N;
//    scanf("%d", &N);
//    int *P = (int *)malloc(N*sizeof(int));
//    InputNumber(P, N);
//
//    // Calculate the number of circles
//    int CT = 0;         //change times
//    int CN = 0;         //circle numbers
//    int BasicN = BasicCount(P, N);
//
//    int flag;       //tag the special circle
//    if(P[0]==0)
//        flag = 1;
//    else
//        flag = 0;
//
//    int tmp;
//    int NextIndex = FindNextIndex(P, 0, N);
//    int oldNextIndex;
//    while(NextIndex != -1)
//    {
//        while(1)
//        {
//            if(P[NextIndex]!=NextIndex)
//            {
//                oldNextIndex = NextIndex;
//                tmp = P[NextIndex];
//                P[NextIndex] = NextIndex;
//                NextIndex = tmp;
//            }
//            else
//                break;
//        }
//        CN++;
//        NextIndex = FindNextIndex(P, oldNextIndex, N);
//    }
//
//    if(CN==0)
//        CT = 0;
//    if(flag == 0)
//        CT = BasicN+(CN-1)*1-1;
//    else
//        CT = BasicN+CN;
//
//    printf("%d", CT);
//
//}
//
