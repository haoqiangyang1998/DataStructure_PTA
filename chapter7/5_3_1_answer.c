//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//
//#define MAXCHAR 18
//
//typedef enum{empty, exist} EntryType;
//
//typedef char EleType[MAXCHAR+1];
//typedef struct HashEntry Cell;
//struct HashEntry
//{
//    EleType Data;
//    int Distance;
//    EntryType Info;
//};
//
//typedef struct TblNode *HashTable;
//struct TblNode
//{
//    int K;
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
//        strcpy(H->Cells[i].Data,"\0");
//        H->Cells[i].Info = empty;
//        H->Cells[i].Distance = 0;
//    }
//
//    return H;
//}
//
//int Hash(HashTable H, EleType key)
//{
//    //6,10,14,16,17,18
//    int hkey;
//    int hkey1 = (key[5]-'0')*pow(10,4) + (key[9]-'0')*pow(10,3) + (key[13]-'0')*pow(10,2) + (key[15]-'0')*pow(10,1) + (key[16]-'0');
//    if(key[17] == 'x')
//        hkey = hkey1*10+10;
//    else
//        hkey = hkey1*10 + key[17]-'0';
//    return hkey%H->TableSize;
//}
//
//int LinearFind(HashTable H, EleType key)
//{
//    int CurPos, NewPos;
//    CurPos = NewPos = Hash(H, key);
//
//    int count = 0;
//    while(H->Cells[NewPos].Info != empty && strcmp(H->Cells[NewPos].Data, key))
//    {
//        count++;
//        NewPos = CurPos + count;
//        if(NewPos>=H->TableSize)
//            NewPos = NewPos%H->TableSize;
//    }
//    return NewPos;
//}
//
//void Insert(HashTable H, EleType key, int D)
//{
//    int Pos = LinearFind(H, key);
//    if(H->Cells[Pos].Info == empty)
//    {
//        strcpy(H->Cells[Pos].Data, key);
//        H->Cells[Pos].Info = exist;
//        if(D<H->K)
//            H->Cells[Pos].Distance = H->K;
//        else
//            H->Cells[Pos].Distance = D;
//    }
//    else
//    {
//        if(D<H->K)
//            H->Cells[Pos].Distance += H->K;
//        else
//            H->Cells[Pos].Distance += D;
//    }
//}
//
//void PrintResults(HashTable H, EleType key)
//{
//    int Pos = LinearFind(H, key);
//    if(H->Cells[Pos].Info == empty)
//        printf("No Info\n");
//    else
//    {
//        printf("%d\n", H->Cells[Pos].Distance);
//    }
//}
//
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//
//    int N,K,Dist,i;
//    EleType key;
//    scanf("%d %d", &N, &K);
//    HashTable H = CreateTable(N);
//    H->K = K;
//
//    EleType UserID;
//    for(i=0; i<N; i++)
//    {
//        scanf("%s", UserID);
//        scanf("%d", &Dist);
//        Insert(H, UserID, Dist);
//    }
//
//    int M;
//    scanf("%d", &M);
//    for(i=0; i<M; i++)
//    {
//        scanf("%s", UserID);
//        PrintResults(H, UserID);
//    }
//
//    return 0;
//}
//
//
