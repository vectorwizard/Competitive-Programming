#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool func(int range,int n,int m,int k){
    int l,r;
    for(int l=0;l<=range-1;l++){
        r= range-l-1;
        if((k+r)>n||(k-1-l)<0) continue;
        int x = l-1+max(l,r)+r;
        if(x<=m) return true;
    }
    return false;
}
void solve() {
    int n,m,k;
    cin>>n; cin>>m; cin>>k;
    int low = 1,high = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(func(mid,n,m,k)) low=mid+1;
        else high = mid-1;
    }
    cout<<high<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
