#include <stdio.h>

#define TABLE_SIZE 10

int hash(int key) {
    return key % TABLE_SIZE;
}

int main() {

    int table[TABLE_SIZE] = {0},i;


    int keys[] = {3, 6, 11, 12, 14, 16};
    for ( i = 0; i < 6; i++) {
        int key = keys[i];
        int index = hash(key);
        table[index] = key;
    }


    int key_to_find;
    printf("Enter The Key To Search:");
    scanf("%d",&key_to_find);
    int index = hash(key_to_find);
    if (table[index] == key_to_find) {
        printf("Found %d at index %d\n", key_to_find, index);
    } else {
        printf("%d not found in the hash table\n", key_to_find);
    }

    return 0;
}
