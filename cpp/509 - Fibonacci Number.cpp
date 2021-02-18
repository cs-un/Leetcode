class Solution {
public:
    int memo[31]{};
    int fib(int N) {
        if(N == 0)
        {
            return 0;
        }
        if(N == 1)
        {
            return 1;
        }
        if(memo[N])
        {
            return memo[N];
        }
        memo[N] = fib(N - 1) + fib(N - 2);
        return memo[N];
    }
};