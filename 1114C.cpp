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
    string a,b;
    cin>>a>>b;
    int odda = 0;
    int evena = 0;
    int oddb = 0;
    int evenb = 0;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            if(i%2==0) evena++;
            else odda++;
        }
        if(b[i]=='1'){
            if(i%2==0) evenb++;
            else oddb++;
        }
    }
    if((odda+evena)!=(oddb+evenb)){
        cout<<"NO"<<endl;
        return;
    }
    if((odda==oddb) && (evena==evenb)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
