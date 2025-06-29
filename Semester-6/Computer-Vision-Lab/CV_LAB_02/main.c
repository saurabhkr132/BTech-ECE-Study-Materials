#include <stdio.h>

int main() {
    int arr[10];

    for(int i = 0; i<10; i++) {
        arr[i] = 2 * i;
    }

    int sum = 0;
    for(int i = 0; i<10; i++) {
        sum += arr[i];
    }

    printf("Sum of the array is: %d.\n", sum);
    
    return 0;
}
