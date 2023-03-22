#include <stdio.h>
#include <stdbool.h>

void swap_function(int *ptr1, int *ptr2, int *count1, int *count2){
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
    (*count1)++;
    (*count2)++;
}

void bubbleSort(int s[], int n){
   int i, j;
   bool swap;
   int count[n]; 
   for (i = 0; i < n; ++i){
       count[i] = 0; 
   }
   for (i = 0; i < n - 1; ++i){
     swap = false;
     for (j = 0; j < n - i - 1; ++j){
        if (s[j] > s[j+1]){
           swap_function(&s[j], &s[j+1], &count[j], &count[j+1]);
           swap = true;
        }
     }
     if (swap == false)
        break;
   }
   printf("Swaps for each index: \n");
   for (i = 0; i < n; ++i){
       printf("Index %d: %d\n", i, count[i]);
   }
}

int main(){
    int s[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(s)/sizeof(s[0]);
    bubbleSort(s, n);
    return 0;
}
