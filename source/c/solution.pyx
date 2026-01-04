# 🚀 This Cython class wraps a C function for computing h-index
# Python list ➜ C array ➜ call C function ➜ result returned 🐍➡️⚡

from libc.stdlib cimport malloc, free  # 🧱 allocate & free memory

cdef extern from "solution.h":
    int hIndex(int *citations, int citationsSize)  # 📊 C function

cdef class cSolution:
    # 🧮 Compute h-index using the C implementation
    def c_hIndex(self, citations):
        cdef int size = len(citations)  # 📏 number of papers
        cdef int* cArray = <int*> malloc(sizeof(int) * size)  # 🧱 allocate C array
        cdef int i

        # ❗ Check if malloc failed
        if not cArray: raise MemoryError()

        # 🔁 Copy Python list into C array
        for i in range(size): cArray[i] = citations[i]

        # ⚡ Call the C hIndex function
        result = hIndex(cArray, size)

        # 🧹 Free allocated memory
        free(cArray)

        # 🎯 Return result to Python
        return result