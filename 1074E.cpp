#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m,k;
    string s;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    cin>>s;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<vector<int>> l_die(k+1);
    vector<vector<int>> r_die(k+1);
    for(int i=0;i<n;i++){
        auto it = lower_bound(b.begin(),b.end(),a[i]);
        if(it!=b.end()){
            ll dist = (long long)*it - a[i];
            if(dist<=k) r_die[dist].push_back(i);
        }
        if(it!=b.begin()){
            ll dist = (ll)a[i]-*prev(it);
            if(dist<=k) l_die[dist].push_back(i);
        }
    }
    int cur = 0;
    int mini = 0;
    int maxi = 0;
    int alive = n;
    vector<bool> isdead(n,false);
    for(int i=0;i<k;i++){
        char ch = s[i];
        if(ch=='L'){
            cur--;
        }
        else cur++;
        if(cur<mini){
            mini = cur;
            int dist = -mini;
            if(dist<=k){
                for(int x:l_die[dist]){
                    if(!isdead[x]){
                        isdead[x]=true;
                        alive--;
                    }
                }
            }
        }
        else if(cur>maxi){
            maxi = cur;
            int dist = maxi;
            if(dist<=k){
                for(int x:r_die[dist]){
                    if(!isdead[x]){
                        isdead[x]=true;
                        alive--;
                    }
                }
            }
        }
        cout<<alive<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}