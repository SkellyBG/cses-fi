#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define pil      pair<int, long>
#define mp(a, b) make_pair(a, b)

int n, m;
const int N = 100100;

vector<pii> adjList[N * 2];

ll dist[N * 2];

const ll INF = 1e15;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(mp(b, c));
        // graph explosion
        adjList[a].push_back(mp(b + n, c / 2));
        adjList[a + n].push_back(mp(b + n, c));
    }

    for (int i = 1; i <= 2 * n; i++) {
        dist[i] = INF;
    }

    auto cmp = [](pil a, pil b) {
        return a.second > b.second;
    };

    priority_queue<pil, vector<pil>, decltype(cmp)> pq(cmp);
    pq.push(mp(1, 0));

    while (!pq.empty()) {
        pil p = pq.top();
        pq.pop();
        int v = p.first;
        ll d = p.second;
        if (d < dist[v]) {
            dist[v] = d;
            for (auto neighbor : adjList[v]) {
                pq.push(mp(neighbor.first, d + neighbor.second));
            }
        }
    }

    cout << dist[2 * n] << '\n';

}
