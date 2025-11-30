#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j;
    char temp[100];

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();  

    char **arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        char buffer[100];

        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        arr[i] = (char *)malloc(strlen(buffer) + 1);

        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        strcpy(arr[i], buffer);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                // swap pointers
                char *tempPtr = arr[i];
                arr[i] = arr[j];
                arr[j] = tempPtr;
            }
        }
    }

    printf("\nSorted Strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    for (i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
