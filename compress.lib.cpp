template <typename T>
std::vector<T> compress(std::vector<T>& v)
{
        std::vector<T> result = v;
        std::sort(result.begin(), result.end());

        result.erase(unique(result.begin(), result.end()), result.end());

        for (size_t i = 0; i < v.size(); ++i) {
                v[i] = std::lower_bound(result.begin(), result.end(), v[i]) - result.begin();
        }

        return result;
}