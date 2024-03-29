struct WeightedDSU{
    vi par,d,rank;
    #define PARITY 3
    void init(int n){
        par.resize(n+1);
        d.assign(n+1,0);
        rank.assign(n+1,1);
        rep(i,0,n)par[i]=i;
    }
    int find(int x){
        if(x==par[x])return x;
        int tmp=par[x];
        par[x]=find(par[x]);
        d[x]=d[tmp]+d[x]; // has to be updated according to question
        return par[x];
    }
    bool merge(int a,int b,int r){
        int aroot=find(a);
        int broot=find(b);
        if(aroot==broot){
            int tmp=d[a]-d[b];  // has to be updated according to question
            if(tmp!=r)return 1;
            else return 0;
        }else{
            if(rank[aroot]<rank[broot]){
                par[aroot]=broot;
                d[aroot]=d[b]+r-d[a];  // has to be updated according to question
                rank[broot]+=rank[aroot];
            }else{
                par[broot]=aroot;
                d[broot]=r+d[a]-d[b]; // has to be updated according to question
                rank[aroot]+=rank[broot];
            }
            return 0;
        }
    }
}uf;