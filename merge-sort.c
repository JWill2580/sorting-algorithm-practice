#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100000




void merge(int *a, int *w, int n){ 
    int i = 0;
    int mid = n/2;
    int j = 0;
    
    while(i < (n/2) && mid < n){
        if(a[i] < a[mid]){
            w[j] = a[i];
            i++;
        } else {
            w[j] = a[mid];
            mid++;
        }
        j++;
    }
    while(i < (n/2)){
        w[j] = a[i];
        i++;
        j++;
    }
    while(j < n){
        w[j] = a[mid];
        mid++;
        j++;
    }
}

/*Merge sorting function that implemented insertion sort algorithm*/
void merge_sort(int *a, int *w, int n){
    
    int i;
    
    if(n < 2){
        return;
    }
    
   
    merge_sort(a, w, (n/2));
    merge_sort((a + (n/2)), w, (n - (n/2)));    
    merge(a, w, n);
    
    for(i = 0; i < n; i++){
        a[i] = w[i];
    }
         
}

/*main method that calls the merge sort function*/
int main(void) {
    int my_array[ARRAY_MAX];
    int workspace[ARRAY_MAX];
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d ", &my_array[count])) {
        count++;
    }
  
    merge_sort(my_array, workspace, count);

    for (i = 0; i < count; i++) {
        printf("%d ", my_array[i]);
    }
    return EXIT_SUCCESS;
}
