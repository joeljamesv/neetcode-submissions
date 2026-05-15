class Solution:
    def maxArea(self, heights: List[int]) -> int:
        ptr1 = 0
        ptr2 = len(heights) - 1

        maxSum = min(heights[ptr1], heights[ptr2]) * (len(heights) - 1)
        while ptr1 <= ptr2:
            sumx = min(heights[ptr1], heights[ptr2]) * (ptr2 - ptr1)
            if sumx > maxSum:
                maxSum = sumx
            if heights[ptr1] > heights[ptr2]:
                ptr2 = ptr2 - 1
            elif heights[ptr1] < heights[ptr2]:
                ptr1 = ptr1 + 1
            else:
                ptr2 = ptr2 - 1
                ptr1 = ptr1 + 1
        return maxSum
