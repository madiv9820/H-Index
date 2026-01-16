#include <algorithm>

// 🔢 Comparator function used by qsort to sort integers in ascending order
int compare_integers(const void *a, const void * b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    // 📈 Standard comparison logic for qsort
    if(int_a < int_b) return -1;
    if(int_a > int_b) return 1;
    return 0;
}

int hIndex(int *citations, int citationsSize) {
    // 📚 Sort the citation array in ascending order
    qsort(citations, citationsSize, sizeof(int), compare_integers);

    // 🎯 This variable will store the final h-index
    int hIndex = 0;
    
    // 📈 Maximum citation count after sorting
    int maxCitation = citations[citationsSize - 1];
    
    // 📊 Dynamic array where:
    // index = citation count
    // value = number of papers with exactly that many citations (initially)
    int *researchPaperCount;
    
    // 🔁 Loop control variables
    int index, citation;

    // 🧠 Allocate and initialize the counting array
    researchPaperCount = (int*) calloc((maxCitation + 1), sizeof(int));
    
    // 🔢 Count how many papers have each exact citation count
    for(index = 0; index < citationsSize; ++index) {
        researchPaperCount[citations[index]] += 1;
    }

    // 🔁 Convert the array into a suffix sum array
    // After this loop:
    // researchPaperCount[i] = number of papers with at least i citations
    for(index = maxCitation - 1; index >= 0; --index) {
        researchPaperCount[index] += researchPaperCount[index + 1];
    }

    // 🏆 Determine the h-index
    // Find the largest value h such that
    // at least h papers have h or more citations
    for(citation = maxCitation; citation >= 0; --citation) {
        if(researchPaperCount[citation] >= citation) {
            hIndex = citation;  // ✅ Found the valid h-index
            break;
        }
    }

    // 🧹 Free dynamically allocated memory
    free(researchPaperCount);

    // 🚀 Return the computed h-index
    return hIndex;
}