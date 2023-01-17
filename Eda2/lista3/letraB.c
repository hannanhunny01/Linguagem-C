#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char letter;
    int index;
} HashItem;

const HashItem NULL_ITEM = {' ', -1};

static int hashTableSize, elements;
static HashItem *hashTable;

int hashFunction(int index) {
    return index % hashTableSize;
}

void initHashTable(int maxSize) {
    elements = 0;
    hashTableSize = maxSize;
    hashTable = malloc(hashTableSize * sizeof(HashItem));
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = NULL_ITEM;
    }
}

void insertInHashTable(HashItem item) {
    int hashValue = hashFunction(item.index);
    if (hashTable[hashValue].letter != item.letter) {
        hashTable[hashValue] = item;
        elements++;
    }
}

int main() {
    initHashTable(1048583);
    HashItem item;
    int smallestIndex;

    while (scanf("%d %c", &item.index, &item.letter) != EOF) {
        if (elements == 0) {
            smallestIndex = item.index;
        } else {
            smallestIndex = (item.index < smallestIndex) ? item.index : smallestIndex;
        }
        insertInHashTable(item);
    }

    for (int i = smallestIndex; i < smallestIndex + elements; i++) {
        int hashValue = hashFunction(i);
        printf("%c", hashTable[hashValue].letter);
    }
    printf("\n");
    return 0;
}