#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_REF_STRING 100

int main() {
    int frames[MAX_FRAMES];
    int refString[MAX_REF_STRING];
    int frameSize, refSize, i, j, k, pageFaults = 0, victimIndex, maxFutureIndex;

    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);

    printf("Enter the length of the reference string: ");
    scanf("%d", &refSize);

    printf("Enter the reference string: ");
    for (i = 0; i < refSize; i++) {
        scanf("%d", &refString[i]);
    }

    for (i = 0; i < frameSize; i++) {
        frames[i] = -1; // Initialize frames with invalid page numbers
    }

    for (i = 0; i < refSize; i++) {
        int page = refString[i];

        int isPageFault = 1;
        for (j = 0; j < frameSize; j++) {
            if (frames[j] == page) {
                isPageFault = 0;
                break;
            }
        }

        if (isPageFault) {
            pageFaults++;

            // Initialize the future indexes to -1, indicating that the page is not found in the future
            int future[MAX_FRAMES];
            for (j = 0; j < frameSize; j++) {
                future[j] = -1;
            }

            // Search for the future occurrence of each page in the frame
            for (j = 0; j < frameSize; j++) {
                for (k = i + 1; k < refSize; k++) {
                    if (frames[j] == refString[k]) {
                        future[j] = k;
                        break;
                    }
                }
            }

            // Find the page with the maximum future index
            maxFutureIndex = -1;
            victimIndex = -1;
            for (j = 0; j < frameSize; j++) {
                if (future[j] == -1) {
                    victimIndex = j;
                    break;
                }
                if (future[j] > maxFutureIndex) {
                    maxFutureIndex = future[j];
                    victimIndex = j;
                }
            }

            // Replace the page in the frame with the highest future index
            frames[victimIndex] = page;
        }
    }

    printf("Page Faults: %d\n", pageFaults);

    return 0;
}
