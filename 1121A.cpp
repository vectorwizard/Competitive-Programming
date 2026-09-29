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
    vector<int> sorted = a;
    sort(sorted.begin(),sorted.end());
    vector<int> bad; 
    vector<int> good;
    for(int i=0;i<n;i++){
        if(a[i]!=sorted[i]){
            bad.push_back(a[i]);
            good.push_back(sorted[i]);
        }
    } 
    reverse(bad.begin(),bad.end());
    if(bad==good){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}