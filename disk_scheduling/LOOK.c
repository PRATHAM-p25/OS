#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMovement = 0, initial, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter the head movement direction: for high enter 1, for low enter 0\n");
    scanf("%d", &move);

    // Logic for sorting the request array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    // If movement is towards high value
    if (move == 1) {
        printf("Disk arm movement sequence:\n");
        for (i = index; i < n; i++) {
            printf("move to track %d = distance %d\n", RQ[i], abs(RQ[i] - initial));
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index - 1; i >= 0; i--) {
            printf("move to track %d = distance %d\n", RQ[i], abs(RQ[i] - initial));
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // If movement is towards low value
    else {
        printf("Disk arm movement sequence:\n");
        for (i = index - 1; i >= 0; i--) {
            printf("move to track %d = distance %d\n", RQ[i], abs(RQ[i] - initial));
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index; i < n; i++) {
            printf("move to track %d = distance %d\n", RQ[i], abs(RQ[i] - initial));
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}