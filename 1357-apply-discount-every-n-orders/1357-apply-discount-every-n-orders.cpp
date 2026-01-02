class Cashier {
public:
    int m, disc;
    unordered_map<int, int> rates;
    int cnt = 1;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        m = n;
        disc = discount;
        for (int i = 0; i < prices.size(); i++) {
            rates[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;
        for (int j = 0; j < product.size(); j++) {
            int product_id = product[j];
            int rate = rates[product_id];
            double bill = rate * amount[j];
            if (cnt % m == 0) {
                bill = bill * ((100.0 - disc) / 100.0);
            }
            total += bill;
        }
        cnt++;
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */