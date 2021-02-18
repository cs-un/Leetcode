class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        first = True
        ret = ''
        for c in str:
            if c >= '0' and c <= '9':
                first = False
                ret = ret + c
            elif c in ['-', '+'] and first:
                ret = c
                first = False
            else:
                break
        if ret == '' or ret == '+' or ret == '-':
            ret = '0'
        elif int(ret) > 2**31-1:
            ret = 2**31-1
        elif int(ret) < -2**31:
            ret = -2**31
        return int(ret)