#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
        int x,y;
        cin>>x>>y;
        int n = x+y;
        if(n%2==0 && x==0){
            cout<<"NO"<<endl;
            return;
        }
        else if(n%2==1 && y==0){
            cout<<"NO"<<endl;
            return;
        }
        else if(x>y){
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        int node = 1;
        int mini = x;
        int p = max(0,2* x - 1);
        for(int i=1;i<=p;i++){
            cout<<node<<" "<<node+1<<endl;;
            node++;
        }
        for(int odds = 1;odds<=n-p-1;odds++){
            cout<<node<<" "<<node+odds<<endl;;
        }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}