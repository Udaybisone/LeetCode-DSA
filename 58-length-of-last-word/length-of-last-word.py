class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)
        ss = ""
        j = n-1
        while j>=0 and s[j]==" ":
            j -= 1

        for i in range(j,-1,-1):
            if(s[i]==' '):
                break
            ss += s[i]
        
        return len(ss)



        