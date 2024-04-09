#include <stdio.h> 
#include <stdlib.h> 
#define MAX_REQUESTS 100 

void scan(int requests[], int n, int head, char direction) { 
    int totalSeekOperations = 0; 
    int distance, currentTrack; 
    int sortedRequests[MAX_REQUESTS]; 
    
    // Copy the requests array to a new array for sorting 
    for (int i = 0; i < n; i++) { 
        sortedRequests[i] = requests[i]; 
    } 
    
    // Sort the requests in ascending order 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (sortedRequests[j] > sortedRequests[j + 1]) { 
                // Swap 
                int temp = sortedRequests[j]; 
                sortedRequests[j] = sortedRequests[j + 1]; 
                sortedRequests[j + 1] = temp; 
            } 
        } 
    } 
    
    // Find the position of the head in the sorted requests 
    int headPosition = 0; 
    while (headPosition < n && sortedRequests[headPosition] < head) { 
        headPosition++; 
    } 
    
    // Simulate disk arm movement 
    printf("Sequence of disk arm movement:\n"); 
    if (direction == 'l') { 
        // Move left 
        for (int i = headPosition - 1; i >= 0; i--) { 
            currentTrack = sortedRequests[i]; 
            distance = abs(head - currentTrack); 
            printf("Move to track %d\tDistance = %d\n", currentTrack, distance); 
            totalSeekOperations += distance; 
            head = currentTrack; 
        } 
        // Move to the left end 
        printf("Move to left end\tDistance = %d\n", head); 
        totalSeekOperations += head; 
        // Move right 
        for (int i = headPosition; i < n; i++) { 
            currentTrack = sortedRequests[i]; 
            distance = abs(head - currentTrack); 
            printf("Move to track %d\tDistance = %d\n", currentTrack, distance); 
            totalSeekOperations += distance; 
            head = currentTrack; 
        } 
    } 
    
    else if (direction == 'r') { 
        // Move right 
        for (int i = headPosition; i < n; i++) { 
            currentTrack = sortedRequests[i]; 
            distance = abs(head - currentTrack); 
            printf("Move to track %d\tDistance = %d\n", currentTrack, distance); 
            totalSeekOperations += distance; 
            head = currentTrack; 
        } 
        // Move to the right end 
        printf("Move to right end\tDistance = %d\n", 199 - head); 
        totalSeekOperations += 199 - head; 
        // Move left 
        for (int i = headPosition - 1; i >= 0; i--) { 
            currentTrack = sortedRequests[i]; 
            distance = abs(head - currentTrack); 
            printf("Move to track %d\tDistance = %d\n", currentTrack, distance); 
            totalSeekOperations += distance; 
            head = currentTrack; 
        } 
    } 
    printf("\nTotal seek operations: %d\n", totalSeekOperations); 
} 

int main() { 
    int requests[MAX_REQUESTS]; 
    int n, head; 
    char direction; 
    printf("Enter the number of requests: "); 
    scanf("%d", &n); 
    printf("Enter the request queue:\n"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &requests[i]); 
    } 
    printf("Enter the initial position of the disk head: "); 
    scanf("%d", &head); 
    printf("Enter the direction (l for left, r for right): "); 
    scanf(" %c", &direction); 

    scan(requests, n, head, direction); 
    return 0; 

}
