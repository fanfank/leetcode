class Solution {
public:
    int countPrimes(int n) {
        bool* anti_prime = new bool[n];
        memset(anti_prime, 0, sizeof(bool) * n);

        int prime_number = n > 2 ? 1 : 0;
        for (size_t i = 3; i < n; i += 2) {
            if (!anti_prime[i]) {
                prime_number += 1;
            }
            int j_limit = (n - 1) / i;
            for (size_t j = i; j <= j_limit; j += 2) {
                anti_prime[i*j] = true;
            }
        }
        delete anti_prime;
        return prime_number;
    }
};
