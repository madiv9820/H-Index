## Counting-Based Approach

This solution computes the h-index by evaluating citation thresholds from **highest to lowest** and counting how many papers meet each threshold.

### 🧠 Idea Behind the Approach
The h-index is defined as the **largest number** `h` such that **at least** `h` **papers** have `h` or more citations.

To find this:
1. 🔍 Determine the **maximum citation count** to define the search space.
2. 📊 For each possible citation value `c` (starting from the maximum and moving downward), count how many papers have **at least** `c` **citations**.
3. 🏆 The first value where `number of papers ≥ c ≥ c` is the **h-index**.

This reverse scanning guarantees that the **largest valid h-index** is found first.

### ⚙️ Algorithm Steps
- 📈 Find the maximum citation count.
- 📊 Build a frequency/count array where each index represents a citation threshold.
- 🔁 For each threshold, count papers meeting or exceeding it.
- ✅ Return the first valid h-index encountered.

### ⏱️ Complexity Analysis
- Time Complexity: `O(n × maxCitation)`
- Space Complexity: `O(maxCitation)`

⚠️ This approach favors clarity and correctness over performance and is best suited for **learning, explanation, or small datasets**.

### ✨ Why This Approach?
- ✅ Easy to understand and implement
- 📘 Closely follows the formal definition of h-index
- 🧠 Great for educational and step-by-step reasoning
---