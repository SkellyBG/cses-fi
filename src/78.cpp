#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 100010;
const int M = 200010;

vector<int> adjList[N];
int colour[N];

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
    for (int i = 1; i <= n; i++) {
        if (!colour[i]) {
            q.push(i);
            int curColour = 1;
            colour[i] = curColour;

            while (!q.empty()) {
                int size = q.size();
                int nextColour = 3 - curColour;
                for (int i = 0; i < size; i++) {
                    int v = q.front();
                    q.pop();
                    for (int neighbor : adjList[v]) {
                        if (!colour[neighbor]) {
                            q.push(neighbor);
                            colour[neighbor] = nextColour;
                        } else if (colour[neighbor] == curColour) {
                            cout << "IMPOSSIBLE" << '\n';
                            return 0;
                        }
                    }
                }
                curColour = nextColour;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        cout << colour[i] << ' ';
    }
    cout << '\n';
}
