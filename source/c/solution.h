#include <limits.h>
#include <stdlib.h>

int hIndex(int *citations, int citationsSize) {
    // 🎯 This variable will store the final h-index result
    int hIndex = 0;
    
    // 📈 Will hold the maximum citation value found in the array
    int maxCitation = INT_MIN;
    
    // 📊 Dynamic array to store the count of papers
    // index = citation count
    // value = number of papers with at least that many citations
    int *researchPaperCount;
    
    // 🔁 Loop control variables
    int currentCitation, index, citation;
    
    // 🔍 Step 1: Find the maximum citation count
    // This defines the upper bound for possible h-index values
    for(index = 0; index < citationsSize; ++index) {
        maxCitation = ((maxCitation < citations[index]) ? citations[index] : maxCitation);
    }

    // 🧠 Allocate memory for the counting array
    // Initialized to zero using calloc
    researchPaperCount = (int*) calloc((maxCitation + 1), sizeof(int));

    // 🔁 Step 2: Count how many papers have citations >= currentCitation
    // Iterate from the highest citation count down to 0
    for(currentCitation = maxCitation; currentCitation >= 0; --currentCitation) {
        for(index = 0; index < citationsSize; ++index) {
            researchPaperCount[currentCitation] += 
                ((citations[index] >= currentCitation) ? 1 : 0);
        }
    }

    // 🏆 Step 3: Determine the h-index
    // The h-index is the largest value such that:
    // number of papers with >= h citations is at least h
    for(citation = maxCitation; citation >= 0; --citation) {
        if(citation <= researchPaperCount[citation]) {
            hIndex = citation;  // ✅ Found the valid h-index
            break;
        }
    }

    // 🧹 Free dynamically allocated memory
    free(researchPaperCount);
    
    // 🚀 Return the computed h-index
    return hIndex;
}