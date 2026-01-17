# H-Index
You are given an array of integers called `citations`, where each element represents the number of citations received by a researcher’s paper.

- `citations[i]` corresponds to the citation count of the researcher’s **i-th paper**
- The total number of papers is equal to the length of the array

### 🧠 What Is the H-Index?

The **h-index** is a metric used to measure a researcher’s productivity and impact.

According to its definition:
- A researcher has an h-index of `h` if they have published **at least `h` papers**, and **each of those papers has been cited at least `h` times**.

Your task is to **determine the maximum possible value of `h`** that satisfies this condition.

### 🔍 What You Need to Do
- Analyze the citation counts of all papers
- Determine how many papers meet various citation thresholds
- Identify the **largest value of `h`** for which the researcher has:
    - At least `h` papers
    - Each with **at least `h` citations**

### 📌 Examples
- 
    ```
    Input:  citations = [3, 0, 6, 1, 5]
    Output: 3
    ```
    Explanation:<br>
    The researcher has 5 papers total. Among them, 3 papers have received **at least 3 citations**, so the h-index is 3.

-
    ```
    Input:  citations = [1, 3, 1]
    Output: 1
    ```
    Explanation: <br>
    Only 1 paper has received **at least 1 citation**, so the h-index is 1.

### 📏 Constraints
- `1 ≤ citations.length ≤ 5000`
- `0 ≤ citations[i] ≤ 1000`

### 🎯 Goal
Return the h-index of the researcher based on the provided citation data ✅.

## ⚙️ Approaches
- ### 1️⃣ [Brute-Force Counting](https://github.com/madiv9820/H-Index/blob/Approach_01-Searching/)
    This approach computes the h-index by checking every possible citation value from the maximum down to zero. For each value, it counts how many papers have at least that many citations, then selects the largest value that satisfies the h-index condition.

    - Simple and intuitive 🧠
    - Directly follows the h-index definition 📚
    - Less efficient due to repeated counting 🐢

    **Time Complexity:** `O(n × maxCitation)` ⏱️ <br>
    **Space Complexity:** `O(maxCitation)` 💾

    Best suited for understanding the concept rather than performance-critical use.

- ### 2️⃣ [Counting + Suffix Sum](https://github.com/madiv9820/H-Index/blob/Approach_02-Sorting_and_Counting/)
    This approach computes the **h-index** by counting how many papers have each citation value and then converting that count into a **suffix sum**, which represents how many papers have *at least* a given number of citations.

    - First, citation frequencies are counted 🔢
    - Then, counts are accumulated from right to left ↩️
    - Finally, the largest citation value that satisfies the h-index condition is selected 🏆

    **Time Complexity:** `O(n + maxCitation)` ⏱️ <br>
    **Space Complexity:** `O(maxCitation)` 💾

    This method is more efficient than brute force while remaining easy to understand and closely aligned with the definition of the h-index.

- ### 3️⃣ [Sorting](https://github.com/madiv9820/H-Index/blob/Approach_03-Sorting)
    Sort the citations in **descending order** 🔝, then scan the list to find the largest `h` such that the first `h` papers have **at least `h` citations each** 📈

    **Time Complexity:** `O(n log n)` (due to sorting) ⏱️ <br>
    **Space Complexity:** `O(1)` 💡

    Simple, intuitive, and directly follows the h-index definition.

- ### 4️⃣ [Bucket Counting](https://github.com/madiv9820/H-Index/blob/Approach_04-Bucket_Counting/)
    This approach uses **buckets** 🪣 to count how many papers have each number of citations, then iterates from the highest possible h-index down to zero, accumulating counts to find the largest `h` such that at least `h` papers have ≥ `h` citations.

    **Time Complexity:** `O(n)` ⏱️ <br>
    **Space Complexity:** `O(n)` 💾

    Efficient, intuitive, and avoids sorting while directly implementing the h-index definition ✅

---