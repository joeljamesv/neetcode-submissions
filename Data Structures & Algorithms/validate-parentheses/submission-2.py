class Solution:
    def isValid(self, s: str) -> bool:
        stack = [0] * len(s)

        m = -1
        for i in s:
            if i == "(":
                m = m + 1
                stack[m] = "("
            elif i == "{":
                m = m + 1
                stack[m] = "{"
            elif i == "[":
                m = m + 1
                stack[m] = "["
            elif i == "]":
                if stack[m] == "[":
                    stack[m] = 0
                    m = m - 1
                else:
                    return False
            elif i == "}":
                if stack[m] == "{":
                    stack[m] = 0
                    m = m - 1
                else:
                    return False
            elif i == ")":
                if stack[m] == "(":
                    stack[m] = 0
                    m = m - 1
                else:
                    return False

        try:
            if (sum(stack)) == 0:
                return True
        except:
            return False
        return True
