class Solution {
public:
	void maxProduct(vector<int>& products, int n) {
		if(n == 1) return;
		if(products[n] != 0) return;
		int l = 1, r = n-1;
		while(l <= r) {
			if(products[l] == 0) maxProduct(products, l);
			if(products[r] == 0) maxProduct(products, r);
			products[n] = max(products[n], max(products[l], l)*max(products[r], r));
			l ++;
			r --;
		}
	}
    int integerBreak(int n) {
        if(n == 1) return 1;
        vector<int> products(n+1, 0);
        products[0] = 1;
        products[1] = 1;
        maxProduct(products, n);
        return products[n];
    }
};