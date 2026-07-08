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
    vector<int> ans;
    if(n%2==0){
        for(int i=1;i<=n;i+=2){
            int a = i;
            int b = a+1;
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(b);
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(a);
            ans.push_back(a);
            ans.push_back(b);
        }
    }
    else{
        ans = {1,1,2,1,2,3,1,3,2,2,3,3};
        for(int i=4;i<=n;i+=2){
            int a = i;
            int b = a+1;
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(b);
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(a);
            ans.push_back(a);
            ans.push_back(b);
        }
    }
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
