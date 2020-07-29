//#include<stdio.h>
//#include<stdlib.h>
//
//typedef enum{legitimate, empty, deleted} EntryType;
//
//typedef struct HashEntry Cell;
//struct HashEntry
//{
//    int Data;
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
//HashTable CreateTable(int TableSize)
//{
//    HashTable H = (HashTable)malloc(sizeof(struct TblNode));
//    H->TableSize = TableSize;
//    H->Cells = (Cell*)malloc(H->TableSize*sizeof(Cell));
//
//    for(int i=0; i<H->TableSize; i++)
//    {
//        H->Cells[i].Info = empty;
//    }
//
//    return H;
//}
//
//int LinearFind(HashTable H, int key)
//{
//    int CurPos, NewPos;
//    CurPos = NewPos = key % H->TableSize;
//
//    int count = 0;
//    while(H->Cells[NewPos].Info != empty && H->Cells[NewPos].Data != key)
//    {
//        count++;
//        NewPos = CurPos + count;
//        if(NewPos>=H->TableSize)
//            NewPos = NewPos % H->TableSize;
//    }
//
//    return NewPos;
//}
//
//void Insert(HashTable H, int key)
//{
//    int Pos = LinearFind(H, key);
//    if(H->Cells[Pos].Info != legitimate)
//    {
//        H->Cells[Pos].Data = key;
//        H->Cells[Pos].Info = legitimate;
//    }
//
//}
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,P;
//    scanf("%d %d", &N, &P);
//
//    int i,tmp,flag,Pos;
//    flag = 0;
//    HashTable H = CreateTable(P);
//    for(i=0; i<N; i++)
//    {
//        scanf("%d", &tmp);
//        Insert(H, tmp);
//        Pos = LinearFind(H, tmp);
//        if(flag == 0)
//        {
//            printf("%d", Pos);
//            flag = 1;
//        }
//        else
//        {
//            printf(" %d", Pos);
//        }
//    }
//
//}
