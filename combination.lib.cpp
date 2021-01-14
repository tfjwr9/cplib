constexpr std::size_t MAX_COMB = 10'000'000;

std::vector<long long> inv, fact, factinv;

void init(std::size_t sz, long long mod) {
        sz++;
        inv.resize(sz), fact.resize(sz), factinv.resize(sz);

        inv[1] = fact[0] = fact[1] = factinv[0] = factinv[1] = 1;
        for (std::size_t i = 2; i < sz; i++) {
                inv[i] = mod - inv[mod % i] * (mod / i) % mod;
                fact[i] = fact[i - 1] * i % mod;
                factinv[i] = factinv[i - 1] * inv[i] % mod;
        }
}

long long combination(long long a, long long b, long long mod) {
        if (a < b || a < 0 || b < 0)
                return 0;
        return fact[a] * (factinv[b] * factinv[a - b] % mod) % mod;
}