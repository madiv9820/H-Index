#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 📚 Sort citations in ascending order
        // This helps easily determine the maximum citation count
        sort(citations.begin(), citations.end());
        
        // 🎯 Variable to store the final h-index
        int hIndex = 0;
        
        // 📈 Maximum citation count among all papers
        int maxCitation = citations[citations.size() - 1];
        
        // 📊 Vector to store the number of papers for each citation count
        // Initially, researchPaperCount[i] = number of papers with exactly i citations
        vector<int> researchPaperCount(maxCitation + 1, 0);

        // 🔢 Count how many papers have each exact citation count
        for(const int& citation : citations)
            researchPaperCount[citation] += 1;

        // 🔁 Convert to a suffix sum array
        // After this loop:
        // researchPaperCount[i] = number of papers with at least i citations
        for(int index = maxCitation - 1; index >= 0; --index)
            researchPaperCount[index] += researchPaperCount[index + 1];
        
        // 🏆 Determine the h-index
        // Largest h such that at least h papers have h or more citations
        for(int citation = maxCitation; citation >= 0; --citation) {
            if(researchPaperCount[citation] >= citation) {
                hIndex = citation;  // ✅ Found valid h-index
                break;
            }
        }

        // 🧹 Explicitly free memory (optional, forces vector to release its buffer)
        vector<int>().swap(researchPaperCount);

        // 🚀 Return the computed h-index
        return hIndex;
    }
};