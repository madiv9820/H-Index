#include <stdlib.h>

int hIndex(int *citations, int citationsSize) {
    // 🪣 Allocate buckets to count papers by citation number
    // buckets[i] = number of papers with exactly i citations
    // buckets[citationsSize] also includes all papers with ≥ citationsSize citations
    int* buckets = (int*) calloc(citationsSize + 1, sizeof(int));

    // 🏆 Variable to store the final h-index
    int hIndex = 0;

    // 📊 Tracks how many papers have at least the current number of citations
    int total = 0;

    int index;

    // 🔢 Fill the buckets based on citation counts
    for(index = 0; index < citationsSize; ++index) {
        // ✂️ Cap citations at citationsSize
        // (h-index cannot exceed total number of papers)
        buckets[(citations[index] < citationsSize)
                ? citations[index]
                : citationsSize] += 1;
    }

    // 🔽 Traverse from highest possible h-index down to 0
    for(index = citationsSize; index >= 0; --index) {
        // ➕ Accumulate papers with ≥ index citations
        total += buckets[index];

        // ✅ Check if h-index condition is satisfied
        if(total >= index) {
            hIndex = index;
            break;
        }
    }

    // 🧹 Free dynamically allocated memory
    free(buckets);

    // 🎯 Return the computed h-index
    return hIndex;
}