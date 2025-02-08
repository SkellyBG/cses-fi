#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 100010;
const int M = 200010;

vector<int> adjList[N];
bool visited[N];

void bfs(int i) {
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (auto v : adjList[i]) {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
    }


}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    // count CC

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<pii> roads;
    bfs(1);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            roads.push_back(mp(1, i));
            bfs(i);
        }
    }
    cout << roads.size() << '\n';
    for (auto p : roads) {
        cout << p.first << ' ' << p.second << '\n';
    }
}
