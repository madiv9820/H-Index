## 📚 Sorting-Based Approach
This solution computes the **h-index** by sorting the citations in **descending order** and scanning them to find the largest number `h` such that **at least** `h` **papers** have `h` or **more citations**.

### 🧠 Concept
The h-index measures both the productivity and impact of a researcher:
1. 🔢 Sort citations in **descending order**.
2. 🔍 Iterate through the sorted list.
3. 🏆 For each paper at index `i`, check if `citations[i] >= i + 1`.
4. ✅ The largest `i + 1` that satisfies this condition is the **h-index**.

### ⚙️ Steps in Code
- Sort citations from high to low.
- Initialize h-index to 0.
- Scan papers in order:
    - If a paper’s citations ≥ (index + 1), update h-index.
    - Otherwise, stop scanning.
- Return the computed h-index.

### ⏱️ Complexity
- **Time Complexity:** `O(n log n)` due to sorting
- **Space Complexity:** `O(1)` extra space

### ✨ Why This Approach?
- ✅ Simple and easy to understand
- ✅ Efficient for small to medium datasets
- 📘 Closely follows the **formal h-index definition**
- 🏃‍♂️ Avoids extra memory usage compared to counting-based approaches