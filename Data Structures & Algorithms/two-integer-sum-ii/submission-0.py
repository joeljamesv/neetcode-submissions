class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        arr = [0] * 2
        ptr1 = 0
        ptr2 = n - 1

        while 1:
            print(ptr1, ptr2)
            if numbers[ptr1] + numbers[ptr2] == target:
                arr[0] = ptr1 + 1
                arr[1] = ptr2 + 1
                return arr
            elif numbers[ptr1] + numbers[ptr2] > target:
                print("gt")
                ptr2 = ptr2 - 1
            else:
                print("lt")
                ptr1 = ptr1 + 1
