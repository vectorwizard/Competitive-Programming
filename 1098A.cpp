#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    for(int i=0;i<n;i++){
        if(a[i]==0) zeros++;
        else if(a[i]==1) ones++;
        else twos++;
    }
    int mini = min(ones,twos);
    int maxi = max(ones,twos);
    int rem = (maxi-mini);
    cout<<((mini+zeros)+(rem/3))<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
