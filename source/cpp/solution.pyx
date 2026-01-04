# 🚀 What does this code do?
# This file acts as a bridge 🌉 between Python and C++.
# It allows Python 🐍 to call a fast C++ ⚡ implementation
# of the h-index algorithm.
# Flow: Python list ➜ C++ vector ➜ C++ computation ➜ Python result 🎯

from libcpp.vector cimport vector  # 📦 Import C++ std::vector

# 🔗 Declare the external C++ Solution class from solution.hpp
# This tells Cython what exists on the C++ side
cdef extern from 'solution.hpp':
    cdef cppclass Solution:
        Solution() except +                  # 🛠️ C++ constructor
        int hIndex(vector[int]& citations)   # 📊 h-index logic in C++

# 🐍➡️💠 Python-accessible wrapper around the C++ Solution class
cdef class cppSolution:
    cdef Solution *ptr   # 👉 Pointer holding the C++ object

    # 🧱 Allocate the C++ Solution object when Python object is created
    def __cinit__(self): self.ptr = new Solution()

    # 🧹 Free the C++ object when Python object is destroyed
    def __dealloc__(self): del self.ptr

    # 🧮 Compute the h-index from a Python list of citations
    def cpp_hIndex(self, citations):
        cdef vector[int] cppArray   # 📦 Temporary C++ vector
        cdef int citation

        # 🔁 Convert Python list → C++ vector
        for citation in citations:
            cppArray.push_back(citation)

        # ⚡ Call the C++ hIndex method
        result = self.ptr.hIndex(cppArray)

        # 🧹 No manual cleanup needed:
        # cppArray is automatically destroyed when the function ends
        return result