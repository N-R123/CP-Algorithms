#define FOR(i,a,b) for(int i=a;i<b;i++)
const int N =1000,M = 10;
int tab[M+1][M+1][N+1][N+1];
int L[N+1],a[N+1][N+1],s[N+1][N+1];
struct st2{
    int n,m;
    st2(int _n,int _m):n(_n),m(_m){
        for(int i=2;i<=N;i++) L[i]=L[i/2]+1;
    }
    int f(int x,int y,int z=0,int w=0){
        return max({x,y,z,w});
    }
    void build(){
        FOR(i,0,n)FOR(j,0,m)tab[0][0][i][j]=a[i][j];
        for(int y=1;y<=M;y++){
            FOR(i,0,n) FOR(j,0,m){
                    if(j+(1<<y)-1<m)
                        tab[0][y][i][j]=f(tab[0][y-1][i][j],tab[0][y-1][i][j+(1<<(y-1))]);
                }
        }
        for(int x=1;x<=M;x++){
            FOR(i,0,n) FOR(j,0,m){
                    if(i+(1<<x)-1<n)
                        tab[x][0][i][j]=f(tab[x-1][0][i][j],tab[x-1][0][i+(1<<(x-1))][j]);
                }
        }
        for(int x=1;x<=M;x++)
            for(int y=1;y<=M;y++)
                for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                        if(i+(1<<x)-1<n && j+(1<<y)-1<m)
                            tab[x][y][i][j]=f(
                                    tab[x-1][y-1][i][j],
                                    tab[x-1][y-1][i+(1<<(x-1))][j],
                                    tab[x-1][y-1][i][j+(1<<(y-1))],
                                    tab[x-1][y-1][i+(1<<(x-1))][j+(1<<(y-1))]
                            );
    }
    int qry_i(int x,int y,int _x,int _y){
        int lx=L[_x-x+1];
        int ly=L[_y-y+1];
        return f(
                tab[lx][ly][x][y],
                tab[lx][ly][_x-(1<<lx)+1][y],
                tab[lx][ly][x][_y-(1<<(ly))+1],
                tab[lx][ly][_x-(1<<lx)+1][_y-(1<<(ly))+1]
        );

    }
};
