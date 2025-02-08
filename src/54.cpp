#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, x;

vector<int> c_s;

const int X = 1000050;
const int INF = 1000050;

int dp[X];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false); 

    cin >> n >> x;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c_s.push_back(c);
    }

    for (int i = 1; i <= 1000000; i++) {
        dp[i] = INF;
        for (int j = 0; j < n; j++) {
            int amt = i - c_s[j];
            if (amt < 0) continue;
            dp[i] = min(dp[i], dp[amt] + 1);
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}
