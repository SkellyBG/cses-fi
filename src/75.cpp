#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;
const int N = 1010;
const int M = 1010;

int s_x;
int s_y;

int e_x;
int e_y;

bool visited[N][M];
char matrix[N][M];
pii parent[N][M];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            parent[i][j] = mp(-1, -1);
            matrix[i][j] = c[j];
            if (c[j] == 'A') {
                s_x = i;
                s_y = j;
            } else if (c[j] == 'B') {
                e_x = i;
                e_y = j;
            }
        }
    }


    queue<pii> q;
    q.push(mp(s_x, s_y));
    visited[s_x][s_y] = true;
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
            parent[n_x][n_y] = v;
        }
    }

    string s = "";
    pii cur = mp(e_x, e_y);
    while (cur.first != s_x || cur.second != s_y) {
        pii p = parent[cur.first][cur.second];
        if (cur.first != p.first) {
            s += p.first - cur.first == -1 ? 'D' : 'U';
        }

        if (cur.second != p.second) {
            s += p.second - cur.second == -1 ? 'R' : 'L';
        }

        cur = p;
        if (cur.first == -1 && cur.second == -1) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    reverse(s.begin(), s.end());
    cout << "YES" << '\n';
    cout << s.length() << '\n';
    cout << s << '\n';
}

