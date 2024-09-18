#include <stdio.h>

int jump(int* num, int ns) {
    if (ns <= 1) return 0; 
    if (num[0] == 0) return -1; 

    int jumps = 0; 
    int currentEnd = 0; 
    int farthest = 0; 

    for (int i = 0; i < ns - 1; i++) {
        farthest = (farthest > i + num[i]) ? farthest : i + num[i]; // Update the farthest point

        if (i == currentEnd) {
            jumps++; 
            currentEnd = farthest;
            
            if (currentEnd >= ns - 1) {
                break;
            }
        }
    }

    return (currentEnd >= ns - 1) ? jumps : -1;
}

int main() {
    int num[] = {2, 3, 1, 1, 4};
    int size = sizeof(num) / sizeof(num[0]);
    int result = jump(num, size);
    printf("Minimum number of jumps: %d\n", result);
    return 0;
}
