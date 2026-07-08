#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m,d;
    cin>>n>>m>>d;
    int wt = 0;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if((wt+m)>d){
            wt = 0;
            cnt++;
        }
        else wt+=m;
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