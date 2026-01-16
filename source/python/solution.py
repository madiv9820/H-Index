from typing import List

class pySolution(object):
    def py_hIndex(self, citations: List[int]) -> int:
        # 📚 Sort citations to easily identify the maximum citation count
        citations.sort()
        
        # 🎯 This variable will store the final h-index
        hIndex: int = 0
        
        # 📈 Maximum number of citations any paper has
        maxCitation: int = citations[-1]
        
        # 📊 researchPaperCount[i] will represent
        # the number of papers with exactly i citations (initially)
        researchPaperCount: int = [0] * (maxCitation + 1)
        
        # 🔢 Count how many papers have each exact citation count
        for citation in citations: 
            researchPaperCount[citation] += 1
        
        # 🔁 Convert the array into a suffix sum array
        # After this loop:
        # researchPaperCount[i] = number of papers with at least i citations
        for citation in range(maxCitation - 1, -1, -1): 
            researchPaperCount[citation] += researchPaperCount[citation + 1]
        
        # 🏆 Determine the h-index
        # Find the largest value h such that
        # at least h papers have h or more citations
        for citation in range(maxCitation, -1, -1):
            if researchPaperCount[citation] >= citation:
                hIndex = citation  # ✅ Found the highest valid h-index
                break
        
        # 🧹 Explicitly free memory (optional in Python, but intentional)
        del(researchPaperCount)
        
        # 🚀 Return the computed h-index
        return hIndex