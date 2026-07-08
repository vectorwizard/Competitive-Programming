#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n; cin>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxpossible = k-1;
    int maxi = 0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]==maxi) maxi++;
    }
    cout<<min(maxi,maxpossible)<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
