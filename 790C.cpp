#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cost = 0;
            for(int k=0;k<m;k++){
                int x = a[i][k] - '0';
                int y = a[j][k] - '0';
                cost += abs(x-y);
            }
            mini = min(mini,cost);
        }
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
