#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_MAX 30000

/*function that implements the selection-sort algorithm*/
void selection_sort(int *a, int n) {
    int temp, min, j, i;
    for (i = 0; i < n - 1; i++) {
        min = i;
        /* find smallest item */
        for(j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        /* swap smallest with current index */
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;             
    }
}

/*Main method that calls the selection sort function and times it*/
int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    selection_sort(my_array, count);
    end = clock();

    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }

    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}

