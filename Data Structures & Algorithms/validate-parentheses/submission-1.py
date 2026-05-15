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
                print(stack)
            elif i == "]":
                print(stack)
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

        print(stack)
        try:
            if(sum(stack)) == 0:
                return True
        except:
            return False
        return True
