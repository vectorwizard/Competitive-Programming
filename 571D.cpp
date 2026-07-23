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
    vector<double> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> vec(n);
    vector<int> change(n,1);
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x = (int)a[i];
        double y = (double)x;
        if(y==a[i]){
            vec[i] = x;
            change[i] = 0;
            cnt+=vec[i];
            continue;
        }
        if(a[i]>0){
            int x = (int)a[i];
            vec[i] = x;
            cnt+=x;
        }
        else{
            double x = abs(a[i]);
            int y = (int)x;
            vec[i] = (y+1)*(-1);
            cnt+=vec[i];
        }
    }
    if(cnt<0){
        cnt = abs(cnt);
        int rem = abs(cnt);
        int ind = 0;
        while(cnt>0 && ind<n){
            if(change[ind]){
                vec[ind]++;
                cnt--;
            }
            ind++;
        }
    }
    for(auto it:vec){
        cout<<it<<endl;
    }
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
