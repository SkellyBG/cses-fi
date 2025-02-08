#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 100010;

vector<pii> adjList[N];

bool visited[N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(mp(b, c));
        adjList[b].push_back(mp(a, c));
    }

    auto cmp = [](pii a, pii b) {
        return a.second > b.second;
    };

    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

    ll res = 0;
    pq.push(mp(1, 0));
    
    while (!pq.empty()) {
        pii pair = pq.top();
        pq.pop();;
        if (visited[pair.first]) continue;

        visited[pair.first] = true;
        res += pair.second;
        for (auto edge : adjList[pair.first]) {
            if (!visited[edge.first]) {
                pq.push(edge);
            }
        } 
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    cout << res << '\n';
}
