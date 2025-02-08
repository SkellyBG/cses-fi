#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 1010;
const int M = 1010;

char matrix[N][M];
bool visited[N][M];

void bfs(int x, int y) {
    queue<pii> q;
    q.push(mp(x, y));
    visited[x][y] = true;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        for (auto dir : dirs) {
            int n_x = v.first + dir[0];
            int n_y = v.second + dir[1];
            if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m || visited[n_x][n_y] || matrix[n_x][n_y] == '#') continue;
            q.push(mp(n_x, n_y));
            visited[n_x][n_y] = true;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            matrix[i][j] = c[j];
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && matrix[i][j] == '.') {
                res++;
                bfs(i, j);
            }
        }
    }

    cout << res << '\n';
}
