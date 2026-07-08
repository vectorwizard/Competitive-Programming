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
    bool sorted = true;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            sorted=false;
        }
    }
    if(sorted==true){
        cout<<"YES"<<endl;
    }
    else{
        if(k==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
