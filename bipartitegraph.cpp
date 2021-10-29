#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln "\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) cerr << "[ ]" << endl
#endif
#define pi  pair<int,int>

//bipartite graph:graph can be coloured with exactly 2 colors with no adjacent node with same colour

// A graph can be bipartite if the length of the cycle is even and if length is odd,then we have adjacent nodes with same colour,so every bipartite graph has even cycle,
//if there is no cycle then such type of graphs are always bipartite


bool bipartiteBfs(int i,vector<vector<ll>>&adj,vector<int>&color)
{
    queue<int>q;
    q.push(i);
    color[i]=1;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
       for(auto x:adj[k])
       {
           if(color[x]==-1) 
           {
               color[x]=1-color[k];
               q.push(x);
           }
           else if(color[x]==color[k]) return false;
       }
    }
    return true;
}

bool checkBipartite(vector<vector<ll>>&adj,int n)
{
    vector<int>color(n);
    for(int i=0;i<n;i++) color[i]=-1;
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartiteBfs(i,adj,color))return false;
            
        }
    }
    return true;
}
void solve(){   
  int n,m;
  cin>>n>>m;
  vector<vector<ll>>adj;
adj.resize(n);
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if(checkBipartite(adj,n)) cout<<"YES"<<ln;
    else cout<<"NO"<<ln;
}
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}




