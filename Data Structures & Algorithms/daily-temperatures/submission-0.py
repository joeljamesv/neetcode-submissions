class Solution:
    def dailyTemperatures(self, temp: List[int]) -> List[int]:
        retVal = [0] * len(temp)
        stack = []
        for i in range(len(temp)):
            while len(stack) != 0 and temp[stack[-1]] < temp[i]:
                popped_index = stack.pop()
                retVal[popped_index] = i - popped_index
            stack.append(i)
        return retVal
