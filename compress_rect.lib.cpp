std::vector<T> compress_rect(std::vector<T>& v1, std::vector<T>& v2)
{
        std::vector<T> result;
        for (size_t i = 0; i < v1.size(); ++i) {
                for (int d = 0; d < 2; ++d) {
                        result.emplace_back(v1[i] + d);
                        result.emplace_back(v2[i] + d);
                }
        }

        std::sort(result.begin(), result.end());
        result.erase(std::unique(result.begin(), result.end()), result.end());
        for (size_t i = 0; i < v1.size(); ++i) {
                v1[i] = std::lower_bound(result.begin(), result.end(), v1[i]) - result.begin();
                v2[i] = std::lower_bound(result.begin(), result.end(), v2[i]) - result.begin();                
        }

        return result;
}