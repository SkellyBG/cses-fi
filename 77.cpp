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

    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : adjList[v]) {
            if (visited[i]) continue;
            q.push(i);
            visited[i] = true;
            parent[i] = v;
        }
    }

    vector<int> ans;
    int cur = n;
    while (cur != -1) {
        ans.push_back(cur);
        cur = parent[cur];
        if (cur == 0) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i > -1; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}
