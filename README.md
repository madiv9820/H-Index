## Bucket Counting Approach
The **h-index** measures a researcher’s impact:

The maximum value `h` such that the researcher has at least `h` papers with `h` or more citations.

Instead of sorting the citations (which costs `O(nlogn)`), we use a **bucket counting strategy** to achieve **linear time**.

### 🪣 Why Buckets Work
- The h-index **cannot exceed the number of papers** `n`
- Any citation count greater than `n` can safely be grouped together
- Each bucket represents how many papers have *exactly* that many citations

### ⚙️ Algorithm
1. Create `n + 1` buckets
    - `buckets[i]` → number of papers with `i` citations
    - `buckets[n]` → papers with **≥ n** citations
2. Populate the buckets by capping citations at `n`
3. Traverse buckets **from right to left**
4. Keep a running total of papers with **at least** the current citation count
5. The first index where `total ≥ index` is the **h-index**

### 🚀 Complexity
- **Time Complexity:**	`O(n)`
- **Space Complexity:**	`O(n)`

### ✅ Advantages
- Faster than sorting-based solutions
- Simple and intuitive
- Ideal for large inputs
- Commonly used in **interviews & competitive programming**

### 🏁 Summary
This bucket-based solution efficiently computes the h-index in linear time by leveraging the fact that citation counts beyond `n` don’t affect the final result. It’s clean, fast, and optimal.

---