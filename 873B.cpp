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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> vec;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            vec.push_back(abs(i-a[i]));
        }
    }
    int ans = vec[0];
    for(int i = 1;i<vec.size();i++){
        ans = __gcd(ans,vec[i]);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
