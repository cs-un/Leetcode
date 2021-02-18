class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1;
        }
        
        auto factor = n > 0 ? x : 1/x;
        
        double sum{pow(factor, n)};
        
        return sum;
    }
    
    
    double pow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        
        auto p{pow(x, n/2)};
        
        return n%2 == 0 ? (p * p) : (p * p * x);
    }
};