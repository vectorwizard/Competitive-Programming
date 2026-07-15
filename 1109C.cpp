#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int gcdd = __gcd(x,y);
    for(int i=1;i<=n;i++){
        int d = abs(a[i]-i);
        if(d%gcdd!=0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
