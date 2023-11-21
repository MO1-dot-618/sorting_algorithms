#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countKnuthElements(int n) {
    int k = 0;

    while (pow(3, k) - 1 <= n) {
        k++;
    }

    return (int)(pow(3, k - 1) - 1) / 2;
}

void generateKnuthSequence(int n, int **gaps, int *numElements) {
    *numElements = countKnuthElements(n);
    *gaps = (int *)malloc((*numElements) * sizeof(int));

    int gap = 1;
    int index = 0;

    while (gap <= n) {
        (*gaps)[index++] = gap;
        gap = gap * 3 + 1;
    }
}

int main() {
    int n = 100;
    int *knuthSequence;
    int numElements;

    // Generate Knuth sequence and dynamically allocate memory
    generateKnuthSequence(n, &knuthSequence, &numElements);

    // Print the generated Knuth sequence
    printf("Knuth sequence up to %d: ", n);
    for (int i = 0; i < numElements; i++) {
        printf("%d ", knuthSequence[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(knuthSequence);

    return 0;
}

