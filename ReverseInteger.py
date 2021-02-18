class Solution:
    def reverse(self, x: int) -> int:
        rev = int(str(x)[::-1]) if x >= 0 else int(str(x)[-1:0:-1]) * -1
        if(abs(rev) > 2**31-1):
            return 0
        return rev