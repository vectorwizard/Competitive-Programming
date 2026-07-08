#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,s,x;
    cin>>n>>s>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(s==sum){
        cout<<"YES"<<endl;
        return;
    }
    if((s-sum)>=0 && ((s-sum)%x)==0){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}