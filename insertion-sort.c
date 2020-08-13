#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000

/*Insertion sorting function that implemented insertion sort algorithm*/
void insertion_sort(int *a, int n) {
    int key, i, j=0;
    for(i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        /* max hole to insert into */
        for(j = i - 1; j >= 0; j--){
            if(a[j] < key){
                break;
            } else{
                a[j + 1] = a[j];
            }    
        }      
        a[j + 1] = key;
    }
}

/*main method that calls the insertion sort function and times it*/
int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d ", &my_array[count])) {
        count++;
    }

    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
