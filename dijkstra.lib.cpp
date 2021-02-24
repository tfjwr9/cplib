/**
 * Dijkstra
 */
template <typename T>
struct dijkstra_graph
{
public:
        using Vertex = std::pair<T, long long>;
        using Edge = std::pair<T, long long>;
        long long N;
        std::vector<std::vector<Edge>> G;
        std::vector<T> d;
        std::vector<long long> p;
        const long long _inf = 1LL << 60;

        dijkstra_graph(long long n)
        : N(n + 1),
        G(n + 1),
        d(n + 1),
        p(n + 1)
        {}

        void add_edge(long long from, long long to, T cost)
        {
                G[from].emplace_back(Edge(to, cost));
        }
        
        std::vector<T> search(long long s)
        {
                std::fill(d.begin(), d.end(), _inf);
                std::fill(p.begin(), p.end(), -1);
                d[s] = 0;
                std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> pq;
                pq.push(Vertex(s, 0));

                while (pq.size()) {
                        long long v = pq.top().first;
                        long long dd = pq.top().second;
                        pq.pop();

                        if (d[v] < dd) continue;
                        for (auto e : G[v]) {
                                long long nv = e.first;
                                long long c = e.second;
                                if (d[nv] > d[v] + c) {
                                        d[nv] = d[v] + c;
                                        p[nv] = v;
                                        pq.push(Vertex(nv, d[nv]));
                                }
                        }
                }

                return d;
        }

        T dist(long long i) const
        {
                return d.at(i);
        }

        std::vector<long long> shortest_path(long long t)
        {
                std::vector<long long> res;
                long long cur = t;
                while (cur != -1) {
                        res.emplace_back(cur);
                        cur = p[cur];
                }
                std::reverse(res.begin(), res.end());
                return res;
        }
};
/**
 * End
 */