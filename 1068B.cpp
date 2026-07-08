#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    ll k=0;
    cin>>n;
    vector<int> red(n);
    vector<int> blue(n);
    for(int i=0;i<n;i++){
        cin >> red[i];
    }
    for(int i=0;i<n;i++){
        cin >> blue[i];
    }
    ll mini =0;
    ll maxi =0;
    for(int i=0;i<n;i++){
        ll a1 = maxi-red[i];
        ll a2 = blue[i]-mini;
        ll a3 = mini-red[i];
        ll a4 = blue[i]-maxi;
        mini = min({a1,a2,a3,a4});
        maxi = max({a1,a2,a3,a4});
    }
    k = max(mini,maxi);
    cout << k << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}