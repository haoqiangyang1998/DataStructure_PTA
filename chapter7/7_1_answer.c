//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define IDLength 6
//#define NameLength 8
//#define MAXN 100000
//
//struct student
//{
//    char ID[IDLength+1];
//    char Name[NameLength+1];
//    int Score
//};
//typedef struct student Student;
//
//int CompareID(const void*a, const void*b)
//{
//    return(strcmp(((const Student *)a)->ID, ((const Student *)b)->ID));
//}
//
//int CompareName(const void*a, const void*b)
//{
//    int k = strcmp(((const Student *)a)->Name, ((const Student *)b)->Name);
//    if(!k)
//        k = strcmp(((const Student *)a)->ID, ((const Student *)b)->ID);
//    return k;
//}
//
//int CompareScore(const void*a, const void*b)
//{
//    int k = ((const Student *)a)->Score-((const Student *)b)->Score;
//    if(!k)
//        k = strcmp(((const Student *)a)->ID, ((const Student *)b)->ID);
//    return k;
//}
//
//void Input(Student *P, int N)
//{
//    for(int i = 0; i<N; i++)
//        scanf("%s %s %d", P[i].ID, P[i].Name, &P[i].Score);
//}
//
//void Output(Student *P, int C, int N)
//{
//    switch (C)
//    {
//        case 1: qsort(P, N, sizeof(Student), CompareID);
//        break;
//
//        case 2: qsort(P, N, sizeof(Student), CompareName);
//        break;
//
//        case 3: qsort(P, N, sizeof(Student), CompareScore);
//        break;
//    }
//    for(int i = 0; i<N; i++)
//        printf("%s %s %d\n", P[i].ID, P[i].Name, P[i].Score);
//}
//
//int main()
//{
//    int N,C;
//    scanf("%d %d", &N, &C);
//    Student *P = (Student *)malloc(MAXN*sizeof(Student));
//    Input(P, N);
//    Output(P, C, N);
//
//    return 0;
//}
