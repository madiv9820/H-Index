from typing import List

class pySolution(object):
    def py_hIndex(self, citations: List[int]) -> int:
        # 📄 Total number of research papers
        n: int = len(citations)

        # 🪣 Buckets to count papers by citation number
        # index i → number of papers with exactly i citations
        # bucket n also stores papers with ≥ n citations
        buckets: List[int] = [0] * (n + 1)

        # 🔢 Fill the buckets with citation counts
        for citation in citations:
            # ✂️ Cap citations at n (h-index can’t exceed number of papers)
            buckets[min(citation, n)] += 1

        # 📊 Tracks how many papers have at least the current number of citations
        total: int = 0

        # 🏆 Final h-index result
        hIndex: int = 0

        # 🔽 Iterate from highest possible h-index down to zero
        for index in range(n, -1, -1):
            # ➕ Accumulate papers with ≥ index citations
            total += buckets[index]

            # ✅ Check if h-index condition is satisfied
            if total >= index:
                hIndex = index
                break

        # 🧹 Optional cleanup (Python handles this automatically)
        del(buckets)

        # 🎯 Return the computed h-index
        return hIndex