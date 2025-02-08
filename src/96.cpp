#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii      pair<int,int>
#define mp(a, b) make_pair(a, b)

int n, m;

const int N = 100010;

int parent[N];

int size[N];

int root(int a) {
    if (parent[a] != a) {
        parent[a] = root(parent[a]);
    }
    return parent[a];
}

bool is_same_component(int a, int b) {
    return root(a) == root(b);
}

int union_join(int a, int b) { // return the new component size
    int r_a = root(a);
    int r_b = root(b);
    if (size[r_a] < size[r_b]) {
        parent[r_a] = r_b;
        size[r_b] += size[r_a];
        return size[r_b];
    } else {
        parent[r_b] = r_a;
        size[r_a] += size[r_b];
        return size[r_a];
    }
}



int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        size[i] = 1;
        parent[i] = i;
    }

    int component_count = n;
    int largest_component = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (!is_same_component(a, b)) {
            component_count--;
            int component_size = union_join(a, b);
            largest_component = max(largest_component, component_size);
        }

        cout << component_count << ' ' << largest_component << '\n';
    }
}
