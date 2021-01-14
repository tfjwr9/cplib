std::map<long long, long long> factorint(long long n) {
        std::map<long long, long long> res;
        for (long long i = 2; i * i <= n; i++) {
                long long counter = 0;
                while (n % i == 0) {
                        n /= i;
                        counter++;
                }
                if (counter != 0) {
                        res[i] = counter;
                }
        }
        if (n != 1) {
                res[n] = 1;
        }
        return res;
}