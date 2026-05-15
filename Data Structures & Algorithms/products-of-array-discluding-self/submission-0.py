class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        n = len(nums)
        pref = [1] * n
        sufx = [1] * n

        p = 1
        s = 1
        for i in range(1, n):
            pref[i] = p * nums[i - 1]
            p = pref[i]

            sufx[n - i - 1] = s * nums[n - i]
            s = sufx[n - i - 1]

        for i in range(n):
            pref[i] = pref[i] * sufx[i]
        return pref
