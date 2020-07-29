//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//#define MAXCOUNT 10000
//#define NOWHERE -2
//#define MAXTABLESIZE 100000
//
//typedef enum{legitimate, empty, deleted} EntryType;
//typedef int EleType;
//
//typedef struct HashEntry Cell;
//struct HashEntry
//{
//    EleType Data;
//    EntryType Info;
//};
//
//typedef struct TblNode *HashTable;
//struct TblNode
//{
//    int TableSize;
//    Cell *Cells;
//};
//
//int NextPrimeNumber(int TableSize)
//{
//    int i;
//    int flag;
//    if(TableSize == 1)
//        TableSize++;
//    while(1)
//    {
//        flag = 1;
//        for(i=sqrt(TableSize); i>1; i--)
//        {
//            if(!(TableSize%i))
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if(flag == 1)
//            break;
//        else
//            TableSize++;
//    }
//    return TableSize;
//}
//
//int NextPrimeNumberBetter(int TableSize)
//{
//    int p,i;
//    p = (TableSize%2)? TableSize:TableSize+1;
//    if(p==1)
//        p++;
//    while(p<MAXTABLESIZE)
//    {
//        for(i=sqrt(p); i>2; i--)
//            if(!(p%i))  break;
//        if(i==2) break;
//        else
//            p += 2;
//    }
//    return p;
//}
//
//HashTable CreateTable(int TableSize)
//{
//    HashTable H = (HashTable)malloc(sizeof(struct TblNode));
//    H->TableSize = NextPrimeNumberBetter(TableSize);
//
//    H->Cells = (Cell*)malloc(H->TableSize*sizeof(struct HashEntry));
//    for(int i=0; i<H->TableSize; i++)
//    {
//        H->Cells[i].Info = empty;
//    }
//
//    return H;
//}
//
//
//int SqFind(HashTable H, EleType key)
//{
//    int CurPos, NewPos;
//    CurPos = NewPos = key % H->TableSize;
//
//    int count = 0;
//    while(H->Cells[NewPos].Info != empty && H->Cells[NewPos].Data != key)
//    {
//        count++;
//        if(count<MAXCOUNT)
//            NewPos = CurPos + count*count;
//        else
//        {
//            NewPos = NOWHERE;
//            break;
//        }
//        if(NewPos>=H->TableSize)
//            NewPos = NewPos % H->TableSize;
//    }
//
//    return NewPos;
//}
//
//void InsertAndOutput(HashTable H, EleType key)
//{
//    int Pos = SqFind(H, key);
//    if(Pos == NOWHERE)
//    {
//        printf("-");
//    }
//
//    else if(H->Cells[Pos].Info != legitimate)
//    {
//        H->Cells[Pos].Data = key;
//        H->Cells[Pos].Info = legitimate;
//        printf("%d", Pos);
//    }
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int M,N;
//    scanf("%d %d", &M, &N);
//
//    HashTable H = CreateTable(M);
//    EleType key;
//    for(int i=0; i<N; i++)
//    {
//        scanf("%d", &key);
//        if(i==N-1)
//            InsertAndOutput(H, key);
//        else
//        {
//
//            InsertAndOutput(H, key);
//            printf(" ");
//
//        }
//    }
//
//    return 0;
//}
