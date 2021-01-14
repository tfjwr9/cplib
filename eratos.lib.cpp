std::vector<long long> eratos(long long n) {
        std::vector<bool> nums(n + 1, true);
        nums[0] = nums[1] = false;
        for (long long i = 2; i * i <= n; i++) {
                if (nums[i]) {
                        long long j = i * 2;
                        while (j <= n) {
                                nums[j] = false;
                                j += i;
                        }
                }
        }
        std::vector<long long> primenums;
        for (long long i = 0; i <= n; i++) {
                if (nums[i])
                        primenums.push_back(i);
        }
        return primenums;
}