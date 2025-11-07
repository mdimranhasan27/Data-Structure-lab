//C Program
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int customHash(int key) {
   return key % SIZE;
}

int probe(int H[], int key) {
   int index = customHash(key);
   int i = 0;
   while (H[(index + i) % SIZE] != 0)
      i++;
   return (index + i) % SIZE;
}

void insert(int H[], int key) {
   int index = customHash(key);
   if (H[index] != 0)
      index = probe(H, key);
   H[index] = key;
}

int search(int H[], int key) {
   int index = customHash(key);
   int i = 0;
   while (H[(index + i) % SIZE] != key)
      i++;
   return (index + i) % SIZE;
}

int main() {
   int HT[10] = {0};
   insert(HT, 12);
   insert(HT, 25);
   insert(HT, 35);
   insert(HT, 26);
   insert(HT, 45);
   insert(HT, 55);
   insert(HT, 65);
   insert(HT, 75);
   insert(HT, 85);
   insert(HT, 95);
   int result = search(HT, 26);
   if(result == -1)
      printf("Key not found\n");
   else
      printf("Key found at index: %d\n", result);
   return 0;
}