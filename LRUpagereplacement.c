#include <stdio.h>

#define MAX_FRAMES 10

void lru(int pages[], int n, int frames) {
    int pageFrames[MAX_FRAMES];
    int pageOrder[MAX_FRAMES];
    int pageHits = 0, pageMisses = 0;

    for (int i = 0; i < frames; i++) {
        pageFrames[i] = -1;  // Initialize page frames to -1
        pageOrder[i] = 0;    // Initialize page order to 0
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageFound = 0;

        // Check if page is already in frames
        for (int j = 0; j < frames; j++) {
            if (pageFrames[j] == page) {
                printf("Page hit:\t");
                pageHits++;
                pageOrder[j] = i + 1; // Update page order to current reference
                pageFound = 1;
                break;
            }
        }

        // If page is not in frames, find the least recently used page and replace it
        if (!pageFound) {
            int minIndex = 0;
            for (int j = 1; j < frames; j++) {
                if (pageOrder[j] < pageOrder[minIndex]) {
                    minIndex = j;
                }
            }

            pageFrames[minIndex] = page;
            pageOrder[minIndex] = i + 1; // Update page order to current reference
            printf("Page miss\t");
            pageMisses++;
        }

        // Print current state of page frames
        printf("Page %d: ", page);
        for (int j = 0; j < frames; j++) {
            if (pageFrames[j] == -1) {
                printf(" - ");
            } else {
                printf("%2d ", pageFrames[j]);
            }
        }
        printf("\n");
    }

    // Print final results
    printf("\nPage Hits: %d\n", pageHits);
    printf("Page Misses: %d\n", pageMisses);
}

int main() {
    int frames, n;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    if (frames <= 0 || frames > MAX_FRAMES) {
        printf("Invalid number of frames. Please enter a value between 1 and %d.\n", MAX_FRAMES);
        return 1;
    }

    printf("Enter the number of page requests: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the sequence of page requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    lru(pages, n, frames);

    return 0;
}