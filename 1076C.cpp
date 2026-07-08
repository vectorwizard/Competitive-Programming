#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<pair<int,int>> queries(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries[i]={l-1,r-1};
    }
    int maxi = max(a[n-1],b[n-1]);
    a[n-1] = maxi;
    for(int i=n-2;i>=0;i--){
        a[i] = max(b[i],max(a[i],a[i+1]));
    }
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+a[i];
    }
    for(auto it:queries){
        int l = it.first;
        int r = it.second;
        if(l==0){
            cout<<prefix[r]<<" ";
        }
        else{
            cout<<prefix[r]-prefix[l-1]<<" ";
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}