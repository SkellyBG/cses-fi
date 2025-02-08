#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m, q;

const int N = 505;

ll matrix[N][N];

vector<pii> queries;

const ll INF = 1e15;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a][b] = min(matrix[a][b], (ll) c);
        matrix[b][a] = min(matrix[a][b], (ll) c);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back(mp(a, b));
    }

    // floyd-warshall
    // shortest distance from a to b using the first v vertex
    // recurrence: for new vertex v considered, dp[a][b][1] = min(dp[a][v][0] + dp[v][b][0], dp[a][b][1])
    ll dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = matrix[i][j];    
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[j][k] = min(dp[j][i] + dp[i][k], dp[j][k]);
            }
        }
    }

    for (auto query : queries) {
        ll res = dp[query.first][query.second];
        cout << (res == INF ? -1 : res) << '\n';
    }
}
