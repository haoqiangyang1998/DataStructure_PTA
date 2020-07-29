//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAXL 8
//
//typedef char EleType[MAXL+1];
//typedef enum{legitimate, empty, deleted} EntryType;
//
//typedef struct HashEntry Cell;
//struct HashEntry
//{
//    EleType Data;
//    EntryType Info;
//    int Length;
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
//
//    H->Cells = (Cell *)malloc(H->TableSize*sizeof(Cell));
//    int i;
//    for(i=0; i<H->TableSize; i++)
//    {
//        H->Cells[i].Data[0] = '\0';
//        H->Cells[i].Info = empty;
//        H->Cells[i].Length = 0;
//    }
//    return H;
//}
//
//int HashFunction(EleType key, int*Length, int TableSize)
//{
//    int i,tmpLength;
//    unsigned int Pos = 0;
//    tmpLength = 0;
//    while(key[tmpLength] != '\0')
//        tmpLength++;
//    *Length = tmpLength;
//    if(tmpLength>2)
//    {
//        for(i=tmpLength-3; i<tmpLength; i++)
//            Pos = (Pos<<5) + (key[i]-'A');
//        Pos = Pos % TableSize;
//    }
//    return Pos;
//}
//
//int SqFind(HashTable H, EleType key, int *Length)
//{
//    int CurPos, NewPos;
//    Length = 0;     //Length is necessary?
//    CurPos = NewPos = HashFunction(key, &Length, H->TableSize);
//
//    int count = 0;
//    while(H->Cells[NewPos].Info!=empty && strcmp(H->Cells[NewPos].Data, key))
//    {
//        if(++count %2)
//        {
//            NewPos = CurPos + (count+1)*(count+1)/4;
//            if(NewPos >= H->TableSize)
//                NewPos = NewPos % H->TableSize;
//
//        }
//        else
//        {
//            NewPos = CurPos - (count)*(count)/4;
//            while(NewPos < 0)
//                NewPos = NewPos + H->TableSize;
//        }
//    }
//
//    return NewPos;
//}
//
//void Insert(HashTable H, EleType key)
//{
//    int StrLen = 0;
//    int Pos = SqFind(H, key, &StrLen);
//    if(H->Cells[Pos].Info != legitimate)
//    {
//        strcpy(H->Cells[Pos].Data, key);
//        H->Cells[Pos].Info = legitimate;
//        H->Cells[Pos].Length = StrLen;
//    }
//
//}
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N,P;
//    scanf("%d %d", &N, &P);
//    HashTable H = CreateTable(P);
//
//    EleType key;
//    int i,Pos,len,flag;
//    flag = 0;
//    for(i=0; i<N; i++)
//    {
//        scanf("%s", key);
//        Insert(H, key);
//        Pos = SqFind(H, key, &len);
//        if(flag == 0)
//        {
//            printf("%d", Pos);
//            flag = 1;
//        }
//        else
//            printf(" %d", Pos);
//    }
//
//
//    return 0;
//}
