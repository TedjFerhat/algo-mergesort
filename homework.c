#include <stdio.h>

void mergeSort(int list[], int left, int right) {
    if (left < right) {
        int centre = left + (right-left) / 2;

        mergeSort(list, left, centre);
        mergeSort(list, centre + 1, right);

        int n = centre - left + 1;
        int m = right - centre;
        int arr1[n], arr2[m];

        for (int i = 0; i < n; i++) 
            arr1[i] = list[left + i];

        for (int i = 0; i < m; i++) 
            arr2[i] = list[centre + 1 + i];

        int i = 0, j = 0, k = left;

        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) 
                list[k++] = arr1[i++];
            else 
                list[k++] = arr2[j++];
        }

        while (i < n) 
            list[k++] = arr1[i++];

        while (j < m) 
            list[k++] = arr2[j++];
    }
}

int main() {
    int list[7] = { 1, 2, 12, 5, 1, 8, 2 };
    int size = 7;

    mergeSort(list,0,size - 1);
     printf("ur merge sorted list :");
    for (int i=0; i<size; i++) 
        printf(" %d ", list[i]);
    
    return 0;
}
