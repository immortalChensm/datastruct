//
// Created by 1655664358@qq.com on 2019/8/13.
//
#include <stdio.h>
#include <stdlib.h>
#define HASHSIZE 8
#define NULLKEY -1

typedef struct {
    int *elem;
    int count;
}HashTable;

int Hash(int data)
{
    return data%HASHSIZE;
}
void Init(HashTable *hashTable)
{
   hashTable->elem = (int*)malloc(HASHSIZE* sizeof(int));
   hashTable->count = HASHSIZE;
   for(int i=0;i<HASHSIZE;i++){
       hashTable->elem[i] = NULLKEY;
   }


}
void Insert(HashTable *hashTable,int data)
{
    int hashAddress = Hash(data);

    while (hashTable->elem[hashAddress]!=NULLKEY){

        hashAddress = (++hashAddress)%HASHSIZE;
    }
    hashTable->elem[hashAddress] = data;
}
int search(HashTable *hashTable,int data)
{
    int hashAddress = Hash(data);
    while (hashTable->elem[hashAddress]!=data){
        hashAddress = (++hashAddress)%HASHSIZE;
        if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)){
            return -1;
        }
    }
    return hashAddress;
}
int main()
{

    int i,result;
    HashTable hashTable;
    int arr[HASHSIZE] = {13,29,27,28,26,30,38,99};
    Init(&hashTable);

    for (int j = 0; j < HASHSIZE; ++j) {
        printf("arr[%d]=%d\n",j,hashTable.elem[j]);
    }

    for (i = 0; i < HASHSIZE; ++i) {
        Insert(&hashTable,arr[i]);
    }

    for (int j = 0; j < HASHSIZE; ++j) {
        printf("arr[%d]=%d\n",j,hashTable.elem[j]);
    }

    result = search(&hashTable,99);
    if (result==-1){
        printf("find failure\n");
    }else{
        printf("29 location:%d\n",result);
    }

    printf("******************************************\n");
//    for (int k = 0; k < 30; ++k) {
//        printf("%d\n",k%7);
//    }
    return EXIT_SUCCESS;

}
