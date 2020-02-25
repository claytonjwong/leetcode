/*
 * 1357. Apply Discount Every n Orders
 *
 * Q: https://leetcode.com/problems/apply-discount-every-n-orders/
 * A: https://leetcode.com/problems/apply-discount-every-n-orders/discuss/520418/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Cashier {
public:
    using VI = vector<int>;
    Cashier(int n_, int discount_, VI& products, VI& prices) : n{n_}, discount{discount_}, customer{0} {
        for (auto i = 0; i < products.size(); ++i)
            map[products[i]] = prices[i];
    }
    double getBill(VI product, VI amount, double bill = 0) {
        for (auto i = 0; i < product.size(); ++i)
            bill += map[product[i]] * amount[i];
        if (++customer % n == 0)
            bill -= bill * discount / 100.0;
        return bill;
    }
private:
    int n, discount, customer;
    unordered_map<int, int> map;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
