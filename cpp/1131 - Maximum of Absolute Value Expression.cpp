class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int min1{INT_MAX};
        int min2{INT_MAX};
        int min3{INT_MAX};
        int min4{INT_MAX};
        int max1{INT_MIN};
        int max2{INT_MIN};
        int max3{INT_MIN};
        int max4{INT_MIN};
        
        int sum1, sum2, sum3, sum4;
        for(auto i{0}; i < arr1.size(); ++i)
        {
            sum1 = arr1[i] + arr2[i] + i;
            sum2 = arr1[i] + arr2[i] - i; 
            sum3 = arr1[i] - arr2[i] - i;
            sum4 = arr1[i] - arr2[i] + i;
            max1 = max(max1, sum1);
            min1 = min(min1, sum1);
            
            max2 = max(max2, sum2);
            min2 = min(min2, sum2);
            
            max3 = max(max3, sum3);
            min3 = min(min3, sum3);
            
            max4 = max(max4, sum4);
            min4 = min(min4, sum4);
        }
        
        auto diff1 = max1 - min1;
        auto diff2 = max2 - min2;
        auto diff3 = max3 - min3;
        auto diff4 = max4 - min4;
        
        return max(max(diff1, diff2), max(diff3, diff4));
    }
};