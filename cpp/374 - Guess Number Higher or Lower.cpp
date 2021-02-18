int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        int g = ceil((double)n/2);
        int res = 1;
        while(lo < hi)
        {
            res = guess(g);
            if(res == -1)
            {
                hi = g - 1;
            }
            else if(res == 1)
            {
                lo = g + 1;
            }
            else
            {
                return g;
            }
            g = lo + (hi - lo)/2;
        }
        return lo;
    }
};