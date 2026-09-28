#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,s;
    cin>>n>>s;
    if(n*2>s){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int sum = 0;
    for(int i=0;i<n-1;i++){
        cout<<1<<" ";
        sum+=1;
    }
    cout<<(s-sum)<<endl;
    cout<<(sum+1)<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}