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
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            cout<<0<<endl;
            return;
        }
    }
    int mini = 1e9;
    for(int i=1;i<n;i++){
        mini = min(mini,abs(a[i]-a[i-1]));
    }
    mini++;
    cout<<(mini+1)/2<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
