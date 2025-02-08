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

int e_x = -1;
int e_y = -1;

vector<pii> monsters;

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
            } else if (c[j] == 'M') {
                monsters.push_back(mp(i, j));
                visited[i][j] = true;
            }
        }
    }

    if (s_x == 0 || s_x == n - 1 || s_y == 0 || s_y == m - 1) {
        cout << "YES" << '\n';
        cout << 0 << '\n';
        return 0;
    }


    queue<pii> q;
    q.push(mp(s_x, s_y));
    visited[s_x][s_y] = true;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<pii> q_m; // the monster queue
    for (auto monster : monsters) {
        q_m.push(monster);
    }

    bool found = false;

    while (!q.empty() && !found) {
        int size_m = q_m.size();
        for (int i = 0; i < size_m; i++) {
            pii v = q_m.front();
            q_m.pop();
            for (auto dir : dirs) {
                int n_x = v.first + dir[0];
                int n_y = v.second + dir[1];
                if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m || visited[n_x][n_y] || matrix[n_x][n_y] == '#') continue;
                q_m.push(mp(n_x, n_y));
                visited[n_x][n_y] = true;
            }
        }

        int size = q.size();
        for (int i = 0; i < size; i++) {
            pii v = q.front();
            q.pop();
            for (auto dir : dirs) {
                int n_x = v.first + dir[0];
                int n_y = v.second + dir[1];
                if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m || visited[n_x][n_y] || matrix[n_x][n_y] == '#') continue;
                q.push(mp(n_x, n_y));
                visited[n_x][n_y] = true;
                parent[n_x][n_y] = v;

                if (n_x == 0 || n_x == n - 1 || n_y == 0 || n_y == m - 1) { // is an edge
                    e_x = n_x;
                    e_y = n_y;
                    found = true;
                }
            }
        }
    }

    if (e_x == -1 && e_y == -1) {
        cout << "NO" << '\n';
        return 0;
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
    }

    reverse(s.begin(), s.end());
    cout << "YES" << '\n';
    cout << s.length() << '\n';
    cout << s << '\n';
}

