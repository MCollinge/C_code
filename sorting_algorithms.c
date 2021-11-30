#include <stdio.h>
#include <stdlib.h>


void merge_sort(int * array, int length, int start, int end)
{
    int tempTop=0, leftTop=0, rightTop=mid;
    int tempArray[length];
    int mid = length/2;
    int i;

    if(length == 1){ /* If the input is only 1 integer then no sorting required so return */
        return;
    }

    merge_sort(array, mid, 0, mid); /* Sort first half of array */
    merge_sort(&array[mid], length-mid, 0, length-mid); /* Sort second half of array */

    for(i=0;i<length;i++){ /* search through the whole input array */
        if(rightTop==length){ /* we've finished sorting right of array, so just add the left values */
            tempArray[tempTop] = array[leftTop];
            tempTop++; leftTop++;
        }
        else if(leftTop == mid){ /* we've finished sorting left of array, so just add the right values */
            tempArray[tempTop] = array[rightTop];
            tempTop++; rightTop++;
        }
        else if(array[leftTop] <= array[rightTop]){ /* left val is smaller || equal, write to output array */
            tempArray[tempTop] = array[leftTop];
            tempTop++; leftTop++;
        }
        else{ /* right val is smaller || equal, write to output array */
            tempArray[tempTop] = array[rightTop];
            tempTop++; rightTop++;
        }
    }

    /* Write tempArray back into input array */
    for(i=0;i<length;i++){
        array[i] = tempArray[i];
    }
}

void bubble_sort(int * list, int length){ 
    int temp, i;
    bool swap=1;

    /* Loop until we've passed over the array without swapping any members */
    while(swap){
        swap=0; /* Reset the swap counter */
        for(i=0;i<length-1;i++){ /* search through the whole array */
            if(list[i] > list[i+1]){ /* Check if the current value is bigger then the next value */
                /* The value is bigger, so swap them round */
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                swap=1; /* Let the while loop know that we've made a swap */
            }
        }
    }
}

int main()
{
    /* Create an un-sorted list of integers and define it's length */
    int list[9] = { 5, 3, 8, 1, 2, 0, 9, 5, 7};
    int length=9;

    /* Print the contents of the un-sorted list */
    printf("input: [");
    for(int i=0;i<9;i++){
        printf("%d", list[i]);
    }
    printf("]\n");

    /* Bubble Sorting algorithm */
    /*printf("Calling bubble_sort\n");
    bubble_sort(list, length);*/

    /* Merge sorting algorithm */
    printf("Calling merge_sort\n");
    merge_sort(list, length, 0, length);

    /* Print the contents of the sorted list */
    printf("output: [");
    for(int i=0;i<9;i++){
        printf("%d", list[i]);
    }
    printf("]\n");

    return 0;
}
