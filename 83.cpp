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

int isOnPath[N];

vector<int> adjList[N];
vector<int> inverseAdjList[N];

void bfs(int s, bool inverse) {
    bool visited[N];
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        isOnPath[v]++;
        if (!inverse) {
            for (auto neighbor : adjList[v]) {
                if (visited[neighbor]) continue;
                q.push(neighbor);
                visited[neighbor] = true;
            }
        } else {
            for (auto neighbor : inverseAdjList[v]) {
                if (visited[neighbor]) continue;
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

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
        edges.push_back(make_pair(a, b)); // invert edge weights
        matrix[a][b] = min(matrix[a][b], (ll) -c);
    }

    // we only want to keep vertexes that lies between a path from 1-n, since cycles not on the path doesn't matter
    // to do so:
    // find all vertexes reachable from 1
    // flip graph, find all vertexes reachable from n
    // -> union of two set are the vertexes on the path 
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        inverseAdjList[edge.second].push_back(edge.first);
    }
    bfs(1, false);
    bfs(n, true);

    // relax edges v-1 time
    for (int i = 0; i < n - 1; i++) {
        // relax each edge
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            if (dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
    }
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (isOnPath[i] != 2 || isOnPath[j] != 2) continue;
            if (dist[i] + matrix[i][j] < dist[j]) {
                // negative cycle found
                // cout << i << ' ' << j << '\n';
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << -dist[n] << '\n';
}
