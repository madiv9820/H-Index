#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 🎯 This variable will store the final h-index result
        int hIndex = 0;
        
        // 📈 Find the maximum citation count
        // This determines the upper bound for possible h-index values
        int maxCitation = numeric_limits<int>::min();
        for(const int& citation : citations)
            maxCitation = max(maxCitation, citation);

        // 📊 researchPaperCount[i] will store
        // the number of papers with at least i citations
        vector<int> researchPaperCount(maxCitation + 1, 0);

        // 🔁 Count how many papers have citations >= currentCitation
        // Iterate from the highest citation value down to 0
        for(int currentCitation = maxCitation; currentCitation >= 0; --currentCitation) {
            for(const int& citation : citations) {
                researchPaperCount[currentCitation] += 
                    ((citation >= currentCitation) ? 1 : 0);
            }
        }

        // 🏆 Determine the h-index
        // The h-index is the largest value h such that
        // at least h papers have h or more citations
        for(int citation = maxCitation; citation >= 0; --citation) {
            if(citation <= researchPaperCount[citation]) {
                hIndex = citation;  // ✅ Found the highest valid h-index
                break;
            }
        }

        // 🧹 Explicitly release memory held by the vector
        vector<int>().swap(researchPaperCount);

        // 🚀 Return the computed h-index
        return hIndex;
    }
};