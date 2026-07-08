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
    int last_s=1e9,last_t=1e9;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(last_s>last_t) swap(last_s,last_t);
        if(a[i]<=last_s){
            last_s = a[i];
        }
        else if(a[i]<=last_t){
            last_t = a[i];
        }
        else{
            cnt++;
            last_s = a[i];
        }
    }
    cout<<cnt<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
