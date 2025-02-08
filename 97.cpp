#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 100010;

vector<int> adjList[N];

vector<int> invertedAdjList[N];

bool visited[N];

bool invertedVisited[N];

void dfs1(int v) {
    visited[v] = true;
    for (int neighbor : adjList[v]) {
        if (visited[neighbor]) continue;
        dfs1(neighbor);
    }
}

void dfs2(int v) {
    invertedVisited[v] = true;
    for (int neighbor : invertedAdjList[v]) {
        if (invertedVisited[neighbor]) continue;
        dfs2(neighbor);
    }
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false); 

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        invertedAdjList[b].push_back(a);
    }    

    dfs1(1);
    dfs2(1);

    for (int i = 2; i <= n; i++) {
        if (!visited[i] || !invertedVisited[i]) {
            cout << "NO" << '\n';
            if (!visited[i]) {
                cout << 1 << ' ' << i << '\n';
            } else {
                cout << i << ' ' << 1 << '\n';
            }
            return 0;
        }
    }
    cout << "YES" << '\n';
}
