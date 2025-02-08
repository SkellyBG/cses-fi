#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, x;

vector<int> c_s;

const int X = 1000050;
const int INF = 1000050;
const int MOD = 1e9 + 7;

int dp[X];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false); 

    cin >> n >> x;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c_s.push_back(c);
    }

    for (int i = 1; i <= x; i++) {
        for (auto& c : c_s) {
            int amt = i - c;
            if (amt < 0) continue;
            dp[i] += dp[amt];
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << '\n';
}
