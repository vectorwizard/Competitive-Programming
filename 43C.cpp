#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
static bool comp(vector<int> &a,vector<int> &b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else return a[1]>b[1];
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> vec(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec[i] = {u,v,i};
    }
    sort(vec.begin(),vec.end(),comp);
    ans = vec[0];
    for(int i=1;i<n;i++){
        if(ans[1]>=vec[i][1]){
            cout<<vec[i][2]+1<<" "<<ans[2]+1<<endl;
            return;
        }
        else{
            if(vec[i][1]>ans[1]){
                ans = vec[i];
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
