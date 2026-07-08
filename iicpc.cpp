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
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]==-1) cnt++;
    }
    if(cnt%2==0){
        cout<<"Alice"<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }
    if(cnt==1) {
        cout<<"Bob"<<endl;
        return;
    }
    cout<<"Alice"<<endl;
    int last,curr_cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            curr_cnt++;
        }
        if(curr_cnt==cnt-1){
            last = i;
            break;
        }
    }
    cout<<1<<" "<<last+1<<endl;
}  

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
