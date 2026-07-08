#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int xorr = 0;
    vector<int> xorrs(n);
    xorrs[0] = a[0];
    for(int i=1;i<n;i++){
        xorrs[i] = xorrs[i-1] ^ a[i];
    }
    int b = xorrs[n-1];
    if(p==n){
        int mini = INT_MAX;
        for(int i=0;i<n-1;i++){
            mini = min(mini,xorrs[i]^b);
        }
        cout<<mini<<endl;
        return;
    }
    else if(p==1){
        sort(xorrs.begin(),xorrs.end()-1);
        cout<<xorrs[0]<<endl;
        return;
    }
    else{
        sort(xorrs.begin(),xorrs.end()-1);
        int mini = INT_MAX;
        for(int i=1;i<n-1;i++){
            mini = min(mini,xorrs[i]^xorrs[i-1]);
        }
        cout<<mini<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

