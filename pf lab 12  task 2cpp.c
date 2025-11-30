#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *temp;
    int n1, n2, i;
    printf("Enter the initial number of elements: ");
    scanf("%d", &n1);

    ptr = (int *)malloc(n1 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Enter the new size of the array: ");
    scanf("%d", &n2);

    temp = (int *)realloc(ptr, n2 * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(ptr);
        return 1;
    }
    ptr = temp; 

    // Add new elements if size increased
    if (n2 > n1) {
        printf("Enter %d more integers:\n", n2 - n1);
        for (i = n1; i < n2; i++) {
            scanf("%d", &ptr[i]);
        }
    }

    printf("\nUpdated array:\n");
    for (i = 0; i < n2; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
