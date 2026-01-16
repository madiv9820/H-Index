from typing import List

class pySolution(object):
    def py_hIndex(self, citations: List[int]) -> int:
        # 🎯 This variable will store the final h-index result
        hIndex: int = 0
        
        # 📈 Find the maximum citation count among all papers
        # This helps define the upper bound for possible h-index values
        maxCitation: int = max(citations)
        
        # 📊 Create an array where:
        # index = citation count
        # value = number of papers with at least that many citations
        researchPaperCount: int = [0] * (maxCitation + 1)

        # 🔁 Iterate from the highest possible citation count down to 0
        for currentCitation in range(maxCitation, -1, -1):
            
            # 📚 Count how many papers have citations >= currentCitation
            for citation in citations:
                researchPaperCount[currentCitation] += 1 if citation >= currentCitation else 0
        
        # 🔍 Now determine the h-index:
        # The h-index is the largest value such that
        # there are at least 'citation' papers with >= 'citation' citations
        for citation in range(maxCitation, -1, -1):
            if researchPaperCount[citation] >= citation:
                hIndex = citation  # ✅ Found the highest valid h-index
                break
        
        # 🧹 Clean up memory (not strictly necessary in Python, but explicit)
        del(researchPaperCount)
        
        # 🚀 Return the computed h-index
        return hIndex