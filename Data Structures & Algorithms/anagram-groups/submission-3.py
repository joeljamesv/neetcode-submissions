class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        tempList = strs.copy()

        for i in range(len(tempList)):
            tempList[i] = "".join(sorted(tempList[i]))

        diction={}

        for i in range(len(tempList)):
            if tempList[i] in diction:
                diction[tempList[i]] = str(diction[tempList[i]]) + "+" + str(i)
            else:
                diction[tempList[i]] = str(i)

        
        tempList=[]
        finalList=[]
        for [i,j] in diction.items():
            for k in j.split("+"):
                tempList.append(strs[int(k)])
            finalList.append(tempList)
            tempList = []

        
        return finalList