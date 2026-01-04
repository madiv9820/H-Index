import unittest
from timeout_decorator import timeout
from source.python.solution import pySolution  # 🐍 Import the Python implementation

# 🧪 Test class for the pure Python implementation of h-index
class test_py_Solution(unittest.TestCase):
    # 🔧 Setup before each test
    def setUp(self):
        # ✅ List of test cases: (input citations list, expected h-index)
        self.__testcases = (
            ([3,0,6,1,5], 3),
            ([1,3,1], 1),
            ([0,0,0,0], 0),
            ([5,5,5,5], 4),
            ([0,1,2,3,4,5], 3),
            ([6,5,4,3,2,1], 3),
            ([10], 1),
            ([10,8,5,4,3], 4),
            ([0,1,3,5,6], 3),
            ([1,1,1,1,1], 1)
        )

        # ⚡ Instantiate the Python-based h-index solution
        self.__solution = pySolution()
        return super().setUp()

    # ⏱️ Run each test with a timeout to prevent infinite loops
    @timeout(0.5)
    def test(self):
        # 🔁 Loop through all test cases
        for nums, expected in self.__testcases:
            # 🔹 subTest allows individual test failures without stopping the loop
            with self.subTest(nums):
                # 🧮 Call the Python h-index function
                actual = self.__solution.py_hIndex(nums)  
                
                self.assertEqual(
                    actual,
                    expected,
                    # ❌ Error message if test fails
                    f"Failed for input {nums}: expected {expected}, got {actual}" 
                )

# 🏁 Run the tests when the script is executed
if __name__ == '__main__': unittest.main()