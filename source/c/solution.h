#include <stdlib.h>

// 🔢 Comparator for qsort to sort integers in descending order
int compare_integers(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    // 📈 Sort in descending order
    if(int_a < int_b) return 1;   // swap a and b
    if(int_a > int_b) return -1;
    return 0;
}

int hIndex(int *citations, int citationsSize) {
    // 📚 Sort the citations in descending order
    qsort(citations, citationsSize, sizeof(int), compare_integers);

    // 🎯 Variable to store the h-index
    int hIndex = 0;

    // 🔍 Iterate over the sorted citations
    // index = position of the paper (0-based)
    // citation = number of citations for this paper
    for(int index = 0; index < citationsSize; ++index) {
        // 🏆 Check if current paper satisfies the h-index condition
        // There are at least (index + 1) papers with ≥ (index + 1) citations
        if(citations[index] >= index + 1) hIndex = index + 1;  // ✅ Update h-index
        else break;  // ⛔ Further papers cannot satisfy the condition
        
    }

    // 🚀 Return the computed h-index
    return hIndex;
}