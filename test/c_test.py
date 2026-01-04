import unittest
from timeout_decorator import timeout
from source.c.solution import cSolution  # 🐍 Import the Cython C wrapper

# 🧪 Test class for the C implementation of h-index
class test_c_Solution(unittest.TestCase):
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

        # ⚡ Instantiate the C-based h-index solution
        self.__solution = cSolution()
        return super().setUp()

    # ⏱️ Run each test with a timeout to prevent infinite loops
    @timeout(0.5)
    def test(self):
        # 🔁 Loop through all test cases
        for nums, expected in self.__testcases:
            # 🔹 subTest allows individual test cases to fail without stopping the loop
            with self.subTest(nums):
                # 🧮 Call the C h-index function
                actual = self.__solution.c_hIndex(nums)
                  
                self.assertEqual(
                    actual,
                    expected,
                    # ❌ Error message if test fails
                    f"Failed for input {nums}: expected {expected}, got {actual}"  
                )

# 🏁 Run the tests when the script is executed
if __name__ == '__main__':  unittest.main()