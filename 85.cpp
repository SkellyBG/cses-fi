#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 2505;

const ll INF = 1e15;

vector<pii> edges;

ll dist[N];

ll matrix[N][N];

int parent[N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(a, b)); 
        matrix[a][b] = min(matrix[a][b], (ll) c);
    }

    // relax edges v-1 time
    for (int i = 0; i < n - 1; i++) {
        // relax each edge
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            if (dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
                parent[v] = u;
            }
        }
    }
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i] + matrix[i][j] < dist[j]) {
                cout << "YES" << '\n';
                // cycle is between i and j

                return 0;
            }
        }
    }

    cout << "NO" << '\n';
}
