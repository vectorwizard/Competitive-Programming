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
    vector<vector<int>> occ(n+1);
    for(int i=0;i<n;i++){
        occ[a[i]].push_back(i);
    }
    vector<int> gaps(n+1,-1);
    for(int i=0;i<=n;i++){
        sort(occ[i].begin(),occ[i].end());
    }
    for(int i=0;i<=n;i++){
        int prev = -1;
        for(int j=0;j<occ[i].size();j++){
            gaps[i] = max(gaps[i],(occ[i][j]-prev));
            prev = occ[i][j];
        }
        gaps[i] = max(gaps[i], n - prev);
    }
    map<int,int> mpp;
    set<int> st;
    for(int i=0;i<=n;i++){
        if(gaps[i]==-1) continue;
        if(mpp.find(gaps[i])!=mpp.end()) mpp[gaps[i]] = min(mpp[gaps[i]],i);
        else mpp[gaps[i]] = i;
        st.insert(gaps[i]);
    }
    vector<int> final(n+1,1e9);
    int mini = 1e9;
    for(int i=1;i<=n;i++){
        if(mpp.find(i)!=mpp.end()){
            mini = min(mini,mpp[i]);
        }
        final[i] = mini;
    }
    for(int i=1;i<=n;i++){
        if(final[i]==1e9) cout<<-1<<" ";
        else cout<<final[i]<<" ";
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