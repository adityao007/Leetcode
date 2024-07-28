class Solution {
public:


std::vector<int> sieve(int n) {
    std::vector<bool> is_prime(n + 1, true);
    std::vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

    int nonSpecialCount(int l, int r) {
        int sqrtR = static_cast<int>(std::sqrt(r));
    std::vector<int> primes = sieve(sqrtR);

    std::vector<int> specialNumbers;
    for (int prime : primes) {
        int square = prime * prime;
        if (square >= l && square <= r) {
            specialNumbers.push_back(square);
        }
    }

    int totalNumbers = r - l + 1;
    int specialCount = specialNumbers.size();
    return totalNumbers - specialCount;
    }
};