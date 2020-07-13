//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAXN 100000
//
//struct student
//{
//    char Number[7];
//    char Name[9];
//    int Score;
//};
//typedef struct student Student;
//
//
//
//
//void Input(Student *P, int N)
//{
//    for(int i = 0; i<N; i++)
//        scanf("%s %s %d", P[i].Number, P[i].Name, &P[i].Score);
//}
//
//void PrintByOrder(Student *P, int N)
//{
//    for(int i = 0; i<N; i++)
//        printf("%s %s %d\n", P[i].Number, P[i].Name, P[i].Score);
//}
//
//void Swap(Student *A, Student *B)
//{
//    Student tmp = *A; *A = *B; *B = tmp;
//}
//
//void SelectSortNum(Student *P, int N)
//{
//    int minIndex;
//    for(int i=0; i<N; i++)
//    {
//        minIndex = i;
//        for(int j=i+1; j<N; j++)
//        {
//            if(strcmp(P[minIndex].Number, P[j].Number)>0)
//                minIndex = j;
//        }
//        Swap(P+i, P+minIndex);
//    }
//}
//
//void SelectSortName(Student *P, int N)
//{
//    int minIndex;
//    for(int i=0; i<N; i++)
//    {
//        minIndex = i;
//        for(int j=i+1; j<N; j++)
//        {
//            if(strcmp(P[minIndex].Name, P[j].Name)>0)
//                minIndex = j;
//            if(strcmp(P[minIndex].Name, P[j].Name)==0 && strcmp(P[minIndex].Number, P[j].Number)>0)
//                minIndex = j;
//        }
//        Swap(P+i, P+minIndex);
//    }
//}
//
//void SelectSortScore(Student *P, int N)
//{
//    int minIndex;
//    for(int i=0; i<N; i++)
//    {
//        minIndex = i;
//        for(int j=i+1; j<N; j++)
//        {
//            if(P[minIndex].Score-P[j].Score>0)
//                minIndex = j;
//            if(P[minIndex].Score-P[j].Score==0 && strcmp(P[minIndex].Number, P[j].Number)>0)
//                minIndex = j;
//        }
//        Swap(P+i, P+minIndex);
//    }
//}
//
//void Output(Student *P, int C, int N)
//{
//    if(C==1)
//    {
//        SelectSortNum(P, N);
//        PrintByOrder(P, N);
//    }
//    if(C==2)
//    {
//        SelectSortName(P, N);
//        PrintByOrder(P, N);
//    }
//    if(C==3)
//    {
//        SelectSortScore(P, N);
//        PrintByOrder(P, N);
//    }
//}
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//
//    int N,C;
//    scanf("%d %d", &N, &C);
//    Student *P = (Student *)malloc(MAXN*sizeof(Student));
//    Input(P, N);
//
//    Output(P, C, N);
//
//    return 0;
//}
//
//
