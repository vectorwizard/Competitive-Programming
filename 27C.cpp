#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // p[i] stores the prefix sum modulo k up to index i
    // p has size n + 1, with p[0] = 0
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = (p[i] + a[i]) % k;
    }

    // cnt[rem] stores the count of valid indices j <= r - (k + 1) where p[j] == rem
    vector<int> cnt(k, 0);
    long long total_k_balanced = 0;

    for (int r = 1; r <= n; ++r) {
        // When r >= k + 1, index j = r - (k + 1) satisfies r - j >= k + 1
        if (r >= k + 1) {
            int j = r - (k + 1);
            cnt[p[j]]++;
        }
        total_k_balanced += cnt[p[r]];
    }

    cout << total_k_balanced << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}