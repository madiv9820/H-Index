#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 📄 Total number of papers
        int n = citations.size();

        // 🏆 Variable to store the final h-index
        int hIndex = 0;

        // 📊 Counts how many papers have at least the current number of citations
        int total = 0;

        // 🪣 Buckets where index i = number of papers with exactly i citations
        // bucket n also stores papers with ≥ n citations
        vector<int> buckets(n + 1, 0);

        // 🔢 Populate the buckets
        for (const int& citation : citations) {
            // ✂️ Cap citation count at n (h-index cannot exceed number of papers)
            buckets[min(citation, n)] += 1;
        }

        // 🔽 Traverse from highest possible h-index down to 0
        for (int index = n; index >= 0; --index) {
            // ➕ Accumulate papers with ≥ index citations
            total += buckets[index];

            // ✅ Check if the h-index condition is met
            if (total >= index) {
                hIndex = index;
                break;
            }
        }

        // 🧹 Explicitly release bucket memory (optional)
        vector<int>().swap(buckets);

        // 🎯 Return the computed h-index
        return hIndex;
    }
};