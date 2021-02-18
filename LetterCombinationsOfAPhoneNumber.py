class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = {
            '2':'abc', '3':'def', '4': 'ghi', '5':'jkl',
            '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'
        }
        
        if len(digits) == 0:
            return []
        elif len(digits) == 1:
            return mapping[digits]
        
        ret = mapping[digits[0]]
        for c in digits[1:]:
            temp = []
            for i in ret:
                for j in mapping[c]:
                    temp.append(i + j)
            ret = temp
        return ret