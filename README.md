## 📚 Counting + Suffix Sum Approach
This solution calculates the **h-index** by counting how many papers have each citation count and then accumulating these counts in reverse (suffix sum) to efficiently find the h-index.

### 🧠 Concept

The **h-index** is the largest number `h` such that **at least** `h` **papers** have `h` **or more citations**.

This approach works in three steps:

1. **🔢 Count citations** – Build an array/vector where each index `i` stores the number of papers with exactly `i` citations.
2. **🔁 Accumulate counts** – Convert the array into a **suffix sum**, so each index `i` tells you how many papers have at least `i` citations.
3. **🏆 Determine h-index** – Scan from the maximum citation downward and pick the first `i` where the number of papers ≥ `i`.

### ⚙️ Steps in Code
- **Sort citations** (optional, for convenience to find max value).
- **Create a counting array/vector** of size (`maxCitation + 1`).
- **Fill the array** with the number of papers having each citation count.
- **Compute suffix sums** to get cumulative counts of papers with ≥ `i` citations.
- **Scan from high to low** to find the largest `i` satisfying `researchPaperCount[i] ≥ i`.

### ⏱️ Complexity
- **Time Complexity:** `O(nlogn + maxCitation)`
- **Space Complexity:** `O(maxCitation)`

    ⚠️ Note: This approach is clear and educational, ideal for learning or small datasets, but for large max citation values, a more optimal O(n log n) or O(n) approach may be preferred.

### ✨ Why Use This Approach?
- ✅ Directly follows the **formal h-index definition**
- 📘 Easy to understand and implement
- 🧠 Great for **educational purposes** or step-by-step reasoning