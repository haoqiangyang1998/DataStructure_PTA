//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//
//
//#define MAXCHAR 16
//typedef enum{empty, exist} EntryType;
//typedef long long int EleType;
//typedef char PWType[MAXCHAR+1];
//typedef struct HashEntry Cell;
//struct HashEntry
//{
//    EleType Data;
//    PWType PassWord;
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
//HashTable CreateTable(int N)
//{
//    HashTable H = (HashTable)malloc(sizeof(struct TblNode));
//    H->TableSize = 2*N;
//    H->Cells = (Cell*)malloc(H->TableSize*sizeof(struct HashEntry));
//
//    for(int i=0; i<H->TableSize; i++)
//    {
//        strcpy(H->Cells[i].PassWord,"\0");
//        H->Cells[i].Info = empty;
//    }
//
//    return H;
//}
//
//int Hash(HashTable H, EleType key)
//{
//    return key%H->TableSize;
//}
//
//int LinearFind(HashTable H, EleType key)
//{
//    int CurPos, NewPos;
//    CurPos = NewPos = Hash(H, key);
//
//    int count = 0;
//    while(H->Cells[NewPos].Info != empty && H->Cells[NewPos].Data != key)
//    {
//        count++;
//        NewPos = CurPos + count;
//        if(NewPos>=H->TableSize)
//            NewPos = NewPos%H->TableSize;
//    }
//    return NewPos;
//}
//
//void Insert(HashTable H, EleType key, PWType UserPW)
//{
//    int Pos = LinearFind(H, key);
//    if(H->Cells[Pos].Info == empty)
//    {
//        H->Cells[Pos].Data = key;
//        strcpy(H->Cells[Pos].PassWord,UserPW);
//        H->Cells[Pos].Info = exist;
//        printf("New: OK\n");
//    }
//    else
//    {
//        printf("ERROR: Exist\n");
//    }
//}
//
//void LogIn(HashTable H, EleType key, PWType UserPW)
//{
//    int Pos = LinearFind(H, key);
//    if(H->Cells[Pos].Info == empty)
//        printf("ERROR: Not Exist\n");
//    else
//    {
//        if(!strcmp(H->Cells[Pos].PassWord, UserPW))
//            printf("Login: OK\n");
//        else
//            printf("ERROR: Wrong PW\n");
//    }
//}
//
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//
//    int N,i;
//    EleType key;
//    scanf("%d", &N);
//    HashTable H = CreateTable(N);
//    char sym;
//    PWType UserPW;
//    for(i=0; i<N; i++)
//    {
//        scanf("%c", &sym);      //read the [enter]
//        scanf("%c", &sym);
//        scanf("%lld", &key);
//        scanf("%s", UserPW);
//
//        switch(sym)
//        {
//        case 'L':
//            LogIn(H, key, UserPW);
//            break;
//        case 'N':
//            Insert(H, key, UserPW);
//            break;
//        }
//
//    }
//
//    return 0;
//}
//
