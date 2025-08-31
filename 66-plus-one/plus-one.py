class Solution:
    def plusOne(self, d: List[int]) -> List[int]:
        n = len(d)
        i = n-1
        while i>=0 and d[i]==9:
            d[i] = 0
            i -= 1


        if i>=0:
            d[i] += 1
        else :
            d = [1] + d

        return d
            

        