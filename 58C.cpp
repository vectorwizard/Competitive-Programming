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
    vector<vector<int>> vec(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        vec[i] = {l,r,i};
    }
    sort(vec.begin(),vec.end());
    int maxi = vec[0][1];
    vector<int> ans(n);
    ans[vec[0][2]] = 1;
    bool fl = true;
    for(int i=1;i<n;i++){
        if(vec[i][0]>maxi && fl==true){
            fl = false;
        }
        if(fl) ans[vec[i][2]] = 1;
        else ans[vec[i][2]] = 2;
        maxi = max(maxi,vec[i][1]);
    }
    if(fl){
        cout<<-1<<endl;
        return;
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
