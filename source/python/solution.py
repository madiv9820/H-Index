from typing import List

class pySolution(object):
    def py_hIndex(self, citations: List[int]) -> int:
        # 📚 Sort citations in descending order
        # This way, the most-cited papers come first
        citations.sort(reverse = True)
        
        # 🎯 Variable to store the final h-index
        hIndex: int = 0

        # 🔍 Iterate over the sorted citations
        # index = paper position (0-based)
        # citation = number of citations for this paper
        for index, citation in enumerate(citations):
            # 🏆 Check if this paper satisfies the h-index condition
            # There are at least (index + 1) papers with >= (index + 1) citations
            if citation >= index + 1: hIndex = index + 1  # ✅ Update h-index
            else: break  # ⛔ Further papers cannot satisfy the condition

        # 🚀 Return the computed h-index
        return hIndex