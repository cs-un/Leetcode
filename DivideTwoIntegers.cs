public class Solution {
    public int Divide(int dividend, int divisor) {
        if(dividend == Int32.MinValue && divisor == -1)
        {
            return Int32.MaxValue;
        }
        bool shifted = false;
        var quotient = 0;
        if(dividend > 0)
        {
            dividend *=-1;
            shifted = !shifted;
        }
        if(divisor > 0)
        {
            divisor *= -1;
            shifted = !shifted;
        }

        while(dividend <= divisor)
        {
            int tempDivisor = divisor;
            var multiplier = 1;
            while(dividend < tempDivisor + tempDivisor && tempDivisor > Int32.MinValue/2)
            {
                tempDivisor += tempDivisor;
                multiplier += multiplier;
            }
            dividend -= tempDivisor;
            quotient += multiplier;
        }
        
        return quotient * (shifted ? -1 : 1);
    }
}
