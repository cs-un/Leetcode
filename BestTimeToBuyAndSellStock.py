class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minBuy = 9999999
        maxProfit = 0
        
        for p in prices:
            if p < minBuy:
                minBuy = p
            elif p > minBuy:
                maxProfit = max(maxProfit, p - minBuy)
                
        return maxProfit