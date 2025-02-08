#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 100010;
const int M = 200010;

vector<int> adjList[N];
int parent[N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // dfs 
    for (int i = 1; i <= n; i++) {
        if (parent[i] != 0) continue;

        stack<pii> s;
        s.push(mp(i, i));

        while (!s.empty()) {
            pii p = s.top();
            int v = p.first;
            int par = p.second;
            s.pop();
            parent[v] = par;

            for (auto neighbor : adjList[v]) {
                if (neighbor == parent[v]) continue;

                if (parent[neighbor] != 0 ) { 
                    // cerr << "here" << '\n';
                    // cerr << neighbor << '\n';
                    int cur = v;
                    vector<int> res;
                    while (cur != neighbor) {
                        res.push_back(cur);
                        cur = parent[cur];
                    }
                    res.push_back(neighbor);
                    res.push_back(v);

                    cout << res.size() << '\n';
                    for (auto r : res) {
                        cout << r << ' ';
                    }
                    cout << '\n';
                    return 0;
                }

                s.push(mp(neighbor, v));
            }
        }
    }


    cout << "IMPOSSIBLE" << '\n';
}
