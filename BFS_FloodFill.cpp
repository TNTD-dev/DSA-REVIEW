#include <bits/stdc++.h>
using namespace std;
using ll= long long;
const int maxN=300;

vector<int> slicks;
bool a[maxN][maxN], visit[maxN][maxN];
int n,m;
int moveX[]={0,0,1,-1};
int moveY[]={1,-1,0,0};

// Reset data
void Reset()
{
    slicks.clear();
    for(int i=1; i<=n; i++)
    {
        fill_n(visit[i], m+1, false);
    }
}

int BFS(int sx, int sy)
{
    int sizeSlicks=1;
    queue<pair<int,int>> q;
    visit[sx][sy]=true;
    q.push({sx,sy});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0 ;i<4; i++)
        {
            int u=x+moveX[i];
            int v=y+moveY[i];
            if(u>n || u<1) continue;
            if(v>m|| v<1) continue;

            if(a[u][v]==1 && !visit[u][v]){
                sizeSlicks++;
                visit[u][v]=true;
                q.push({u,v});
            }
        }
    }
    return sizeSlicks;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    while(cin>>n>>m)
    {
        if(!n && !m) return 0;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m ;j++) 
                cin>>a[i][j];

        for(int i=1 ; i<=n ;i++)
            for(int j=1 ; j<=m ; j++)
                if(a[i][j]==1 && !visit[i][j])
                    slicks.push_back(BFS(i,j));

        cout<<slicks.size()<<endl;

        sort(slicks.begin(), slicks.end());
        // Thêm một số 1e9 vào cuối danh sách để có thể đếm các giá trị giống nhau cuối cùng
        slicks.push_back(1e9);
        int num=0,pre=slicks[0];
        for(auto v: slicks)
        {
            if(v!=pre) {
                cout<<pre<<" "<<num<<endl;
                num=1;
                pre=v;
            }
            else num++;
        }
        Reset();
    }
   
}