class ProductOfNumbers {
public:
    vector<int> products{};
    
    ProductOfNumbers() {
        products.push_back(1);
    }
    
    void add(int num) {
        if(num == 0)
        {
            products.clear();
            products.push_back(1);
        }
        else
        {
            products.push_back(num * products.back());
        }
    }
    
    int getProduct(int k) {
        if(products.size() <= k)
        {
            return 0;
        }
        
        auto prod = products.back();
        prod/= products[products.size() - k - 1];
        return prod;
    }
};