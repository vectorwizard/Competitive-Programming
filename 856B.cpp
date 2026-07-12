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
    vector<int> ans(n);
    for(int i=0;i<n-1;i++){
        if(a[i]==1) a[i]++;
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]%a[i]==0){
            a[i+1]++;
            ans[i] = a[i];
        }
        else{
            ans[i] = a[i];
        }
    }
    ans[n-1] = a[n-1];
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
