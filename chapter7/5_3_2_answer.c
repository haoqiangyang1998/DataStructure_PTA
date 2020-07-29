//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MAXCHAR 140
//
//typedef enum{empty, exist} EntryType;
//typedef char EleType[MAXCHAR+1];
//typedef struct HashEntry Cell;
//struct HashEntry
//{
//    EleType Data;
//    int Number;
//    EntryType Info;
//    int Collected;
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
//    H->TableSize = 4*TableSize;
//    H->Cells = (Cell*)malloc(H->TableSize*sizeof(struct HashEntry));
//
//    for(int i=0; i<H->TableSize; i++)
//    {
//        H->Cells[i].Info = empty;
//        H->Cells[i].Number = 0;
//        H->Cells[i].Collected = 0;
//    }
//    return H;
//}
//
//int Hash(HashTable H, EleType key)
//{
//    int hkey,count,ans;
//    hkey = count = 0;
//    while(key[count]!='\0' && count < 5)
//    {
//        hkey = hkey*3 + key[count];
//        count++;
//    }
//    return hkey % H->TableSize;
//}
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
//int LinearFind(HashTable H, EleType key)
//{
//    int CurPos, NewPos;
//    int count = 0;
//    CurPos = NewPos = Hash(H, key);
//    while(H->Cells[NewPos].Info != empty && !CompareIgnoreCap(H->Cells[NewPos].Data, key))
//    {
//        count++;
//        NewPos = CurPos + count;
//        if(NewPos >= H->TableSize)
//            NewPos = NewPos%H->TableSize;
//    }
//    return NewPos;
//}
//
//void Insert(HashTable H, EleType key, int i)
//{
//    int Pos = LinearFind(H, key);
//    if(H->Cells[Pos].Info == empty)
//    {
//        strcpy(H->Cells[Pos].Data, key);
//        H->Cells[Pos].Number = 1;
//        H->Cells[Pos].Info = exist;
//        H->Cells[Pos].Collected = i;
//    }
//    else if(H->Cells[Pos].Collected != i)
//    {
//        H->Cells[Pos].Number++;
//        H->Cells[Pos].Collected = i;
//    }
//
//}
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
//    for(i=0; i<H->TableSize; i++)
//    {
//        if(H->Cells[i].Number > MaxNumber)
//        {
//            MaxNumber = H->Cells[i].Number;
//            MaxCount = 1;
//            strcpy(output, H->Cells[i].Data);
//        }
//        else if(H->Cells[i].Number == MaxNumber)
//        {
//            MaxCount++;
//            if(strcmp(output, H->Cells[i].Data)>0)
//                strcpy(output, H->Cells[i].Data);
//        }
//
//    }
//
//    printf("%s\n", output);
//    printf("%d\n", MaxNumber);
//    if(MaxCount-1>0)
//        printf("And %d more ...", MaxCount-1);
//}
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
//
//    return 0;
//}
