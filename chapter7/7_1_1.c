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
//        QuickSortNum(P, N);
//        PrintByOrder(P, N);
//    }
//    if(C==2)
//    {
//        QuickSortName(P, N);
//        PrintByOrder(P, N);
//    }
//    if(C==3)
//    {
//        QuickSortScore(P, N);
//        PrintByOrder(P, N);
//    }
//}
//
//int median3Num(Student *P, int Left, int Right)
//{
//    int center = (Left + Right)/2;
//    if(strcmp(P[Left].Number, P[center].Number)>0)
//        Swap(P+Left, P+center);
//    if(strcmp(P[Left].Number, P[Right].Number)>0) //make sure the Left number is minimal
//        Swap(P+Left, P+Right);
//    if(strcmp(P[center].Number, P[Right].Number)>0)
//        Swap(P+center, P+Right);
//    Swap(P+center, P+Right-1);
//
//    return Right-1;
//}
//
//void QSortNum(Student *P, int Left, int Right)
//{
//    int Pivot, Cutoff, Low, High;
//    Cutoff = 3;
//
//    if(Cutoff<Right-Left)
//    {
//        Pivot = median3Num(P, Left, Right);  //find Pivot
//        Low = Left; High = Right-1;         //set two pointers,Low and High
//        while(1)
//        {
//            while(strcmp(P[Low].Number, P[Pivot].Number)<0)
//                Low++;
//            while(strcmp(P[High].Number, P[Pivot].Number)>0)
//                High--;
//            if(Low<High)
//                Swap(P+Low, P+High);
//            else
//                break;
//        }                               // find Pivot's Position
//        Swap(P+Low, P+Pivot);          // move the Pivot to Proper Position
//        QSortNum(P, Left, Low-1);       //Left Recursion
//        QSortNum(P, Low+1, Right);      //Right Recursion
//    }
//    else
//        SelectSortNum(P+Left, Right-Left+1);
//
//}
//
//void QuickSortNum(Student *P, int N)
//{
//    QSortNum(P, 0, N-1);
//}
//
//int median3Name(Student *P, int Left, int Right)
//{
//    int center = (Left + Right)/2;
//    if(strcmp(P[Left].Name, P[center].Name)>0)
//        Swap(P+Left, P+center);
//    if(strcmp(P[Left].Name, P[Right].Name)>0) //make sure the Left number is minimal
//        Swap(P+Left, P+Right);
//    if(strcmp(P[center].Name, P[Right].Name)>0)
//        Swap(P+center, P+Right);
//    Swap(P+center, P+Right-1);
//
//    return Right-1;
//}
//
//void QSortName(Student *P, int Left, int Right)
//{
//    int Pivot, Cutoff, Low, High;
//    Cutoff = 3;
//
//    if(Cutoff<Right-Left)
//    {
//        Pivot = median3Name(P, Left, Right);  //find Pivot
//        Low = Left; High = Right-1;         //set two pointers,Low and High
//        while(1)
//        {
//            while(strcmp(P[Low].Name, P[Pivot].Name)<0 || (strcmp(P[Low].Name, P[Pivot].Name)==0 && strcmp(P[Low].Number, P[Pivot].Number)<0) )
//                Low++;
//            while(strcmp(P[High].Name, P[Pivot].Name)>0  ||  (strcmp(P[Low].Name, P[Pivot].Name)==0 && strcmp(P[Low].Number, P[Pivot].Number)>0) )
//                High--;
//            if(Low<High)
//                Swap(P+Low, P+High);
//            else
//                break;
//        }                               // find Pivot's Position
//        Swap(P+Low, P+Pivot);          // move the Pivot to Proper Position
//        QSortNum(P, Left, Low-1);       //Left Recursion
//        QSortNum(P, Low+1, Right);      //Right Recursion
//    }
//    else
//        SelectSortName(P+Left, Right-Left+1);
//}
//
//void QuickSortName(Student *P, int N)
//{
//    QSortName(P, 0, N-1);
//}
//
//int median3Score(Student *P, int Left, int Right)
//{
//    int center = (Left + Right)/2;
//    if(strcmp(P[Left].Score, P[center].Score)>0)
//        Swap(P+Left, P+center);
//    if(strcmp(P[Left].Score, P[Right].Score)>0) //make sure the Left number is minimal
//        Swap(P+Left, P+Right);
//    if(strcmp(P[center].Score, P[Right].Score)>0)
//        Swap(P+center, P+Right);
//    Swap(P+center, P+Right-1);
//
//    return Right-1;
//}
//
//void QSortScore(Student *P, int Left, int Right)
//{
//    int Pivot, Cutoff, Low, High;
//    Cutoff = 3;
//
//    if(Cutoff<Right-Left)
//    {
//        Pivot = median3Name(P, Left, Right);  //find Pivot
//        Low = Left; High = Right-1;         //set two pointers,Low and High
//        while(1)
//        {
//            while(strcmp(P[Low].Score, P[Pivot].Score)<0 || (strcmp(P[Low].Score, P[Pivot].Score)==0 && strcmp(P[Low].Number, P[Pivot].Number)<0) )
//                Low++;
//            while(strcmp(P[High].Score, P[Pivot].Score)>0  ||  (strcmp(P[Low].Score, P[Pivot].Score)==0 && strcmp(P[Low].Number, P[Pivot].Number)>0) )
//                High--;
//            if(Low<High)
//                Swap(P+Low, P+High);
//            else
//                break;
//        }                               // find Pivot's Position
//        Swap(P+Low, P+Pivot);          // move the Pivot to Proper Position
//        QSortNum(P, Left, Low-1);       //Left Recursion
//        QSortNum(P, Low+1, Right);      //Right Recursion
//    }
//    else
//        SelectSortScore(P+Left, Right-Left+1);
//}
//
//void QuickSortScore(Student *P, int N)
//{
//    QSortScore(P, 0, N-1);
//}
//
//
//
//
//int main()
//{
//    //freopen("yhq.txt", "r", stdin);
//
//    int N,C;
//    scanf("%d %d", &N, &C);
//    Student *P = (Student *)malloc(MAXN*sizeof(Student));
//    Input(P, N);
//
//    Output(P, C, N);
//
//    free(P);
//    return 0;
//}
//
//
//
