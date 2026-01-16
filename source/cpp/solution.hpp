#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 📚 Sort citations in descending order
        // The most-cited papers come first
        sort(citations.begin(), citations.end(), greater<int>());
        
        // 🎯 Variable to store the final h-index
        int hIndex = 0;
        
        // 🔍 Iterate over sorted citations
        // index = 0-based position in the sorted array
        // citations[index] = number of citations for this paper
        for(int index = 0; index < citations.size(); ++index) {
            // 🏆 Check if current paper satisfies h-index condition
            // There are at least (index + 1) papers with >= (index + 1) citations
            if(citations[index] >= index + 1) hIndex = index + 1;  // ✅ Update h-index 
            else break;  // ⛔ No further papers can satisfy the condition   
        }

        // 🚀 Return the computed h-index
        return hIndex;
    }
};