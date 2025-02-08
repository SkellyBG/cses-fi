#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

typedef struct project {
    int a;
    int b;
    int p;
} Project;

vector<Project> pjs;
int n;

const int N = 200010;

const ll mem[N];

// let mem[k] be the maximum money you can make from pjs[k:]
// recursive relation:
// at mem[k], if don't take, = mem[k + 1]
// if take
void dp(int k) {

} 

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        Project pj;
        cin >> pj.a >> pj.b >> pj.p;
        pjs.push_back(pj);
    }

    sort(pjs.begin(), pjs.end(), [](Project a, Project b) {
        return a.a < b.a;
    });

    dp(0);
}
