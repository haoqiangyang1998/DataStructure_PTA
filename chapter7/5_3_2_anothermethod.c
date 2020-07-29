//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAXCHAR 140
////#define NULL -1
//
//typedef char EleType[MAXCHAR+1];
//
//typedef struct LNode *PtrToLNode;
//struct LNode
//{
//    EleType Data;
//    int WBL;
//    int WBN;
//    PtrToLNode Next;
//};
//typedef PtrToLNode Position;
//typedef PtrToLNode List;
//
//typedef struct TblNode *HashTable;
//struct TblNode
//{
//    int TableSize;
//    List Heads;
//};
//
//HashTable CreateTable(int TableSize)
//{
//    HashTable H = (HashTable)malloc(sizeof(struct TblNode));
//    H->TableSize = 2*TableSize;
//    H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
//
//    for(int i=0; i<H->TableSize; i++)
//    {
//        H->Heads[i].Data[0] = '\0';
//        H->Heads[i].Next = NULL;
//        H->Heads[i].WBN = 0;
//        H->Heads[i].WBL = 0;
//    }
//
//    return H;
//}
//
//int Hash(HashTable H, EleType key)
//{
//    int hkey=0;
//    int count=0;
//    while(key[count]!='\0' && count < 5)
//    {
//        hkey = hkey*3 + key[count];
//        count++;
//    }
//    return hkey%H->TableSize;
//}
//
//Position Find(HashTable H, EleType key)
//{
//    int Pos = Hash(H, key);
//    Position P = H->Heads[Pos].Next;
//    while(P && strcmp(P->Data, key))
//        P = P->Next;
//
//    return P;
//}
//
//void Insert(HashTable H, EleType key, int i)
//{
//    Position P, NewCell;
//    int Pos;
//
//    P = Find(H, key);
//    if(P == NULL)
//    {
//        NewCell = (Position)malloc(sizeof(struct LNode));
//        strcpy(NewCell->Data, key);
//        NewCell->WBN = 1;
//        NewCell->WBL = i;
//
//        Pos = Hash(H, key);
//        NewCell->Next = H->Heads[Pos].Next;
//        H->Heads[Pos].Next = NewCell;
//    }
//    else if(P->WBL != i)
//    {
//        P->WBN++;
//        P->WBL = i;
//    }
//
//}
//
//
//int CompareIgnoreCap(EleType a, EleType b)
//{
//    int count = 0;
//    int flag = 1;
//    while(a[count] != '\0' && b[count] != '\0')
//    {
//        if( (a[count]-b[count]) != 0  &&  (a[count]-b[count]) != 'A'-'a' &&  (a[count]-b[count]) != 'a'-'A')
//        {
//            flag = 0;
//            break;
//        }
//        count++;
//    }
//    if(a[count] != '\0' || b[count] != '\0')
//        flag = 0;
//    return flag;
//
//}
//
//
//int IsALetter(char tmp)
//{
//    int flag = 0;
//    if(tmp>='A' && tmp<='Z')
//        flag = 1;
//    if(tmp>='a' && tmp<='z')
//        flag = 2;
//    if(tmp == ' ')
//        flag = 3;
//    if(tmp>='0' && tmp<='9')
//        flag = 4;
//    if(tmp == '@')
//        flag = 5;
//    return flag;
//}
//
//char BToS(char X)
//{
//    return X-'A'+'a';
//}
//
//char SToB(char X)
//{
//    return X-'a'+'A';
//}
//
//void ReadTopics(HashTable H, int N)
//{
//    int i, Pos,countT;
//    char tmp = 'k'; //select randomly
//    EleType key;
//    int count,tag;
//    for(i=0; i<N+1; i++)
//    {
//        scanf("%c", &tmp);
//        countT = 0;
//        while(tmp != '\n' && countT<1000)
//        {
//            if(tmp == '#')
//            {
//                count = 0;
//                scanf("%c", &tmp);
//                while(tmp != '#')
//                {
//                    tag = IsALetter(tmp);
//                    if(tag)
//                    {
//                        if(count == 0 && tag == 2)
//                            tmp = SToB(tmp);
//                        if(count > 0 && tag == 1)
//                            tmp = BToS(tmp);
//                        if(count > 0 && tag == 5)
//                            tmp = ' ';
//                        key[count++] = tmp;
//                    }
//
//                    scanf("%c", &tmp);
//                }
//                key[count] = '\0';
//                //Insert key
//
//                Insert(H, key, i);
//            }
//            scanf("%c", &tmp);
//            countT++;
//        }
//    }
//
//}
//
//void PrintResult(HashTable H)
//{
//    int i,MaxNumber, MaxCount;
//    EleType output;
//    MaxCount = MaxNumber = 0;
//
//    Position P;
//
//    for(i=0; i<H->TableSize; i++)
//    {
//        if(H->Heads[i].Next != NULL)
//        {
//            P = H->Heads[i].Next;
//            while(P)
//            {
//                if(P->WBN > MaxNumber)
//                {
//                    MaxNumber = P->WBN;
//                    MaxCount = 1;
//                    strcpy(output, P->Data);
//                }
//                else if(P->WBN == MaxNumber)
//                {
//                    MaxCount++;
//                    if(strcmp(output, P->Data)>0)
//                        strcpy(output, P->Data);
//                }
//                P = P->Next;
//            }
//        }
//    }
//
//    printf("%s\n", output);
//    printf("%d\n", MaxNumber);
//    if(MaxCount-1>0)
//        printf("And %d more ...", MaxCount-1);
//}
//
//
//int main()
//{
//    freopen("yhq.txt", "r", stdin);
//    int N;
//    scanf("%d", &N);
//    HashTable H = CreateTable(N);
//
//    ReadTopics(H, N);
//    PrintResult(H);
//    return 0;
//}
