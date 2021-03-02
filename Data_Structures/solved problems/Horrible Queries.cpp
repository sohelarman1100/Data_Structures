
#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
struct info
{
    long long int prop,sum;
};

struct info tree[mx * 4];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].sum = 0ll;
        tree[node].prop=0ll;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop=0ll;
}
long long query(int node, int b, int e, int i, int j,long long carry)
{
    if (i > e || j < b)
        return 0ll;
    if (b >= i && e <= j)
        return tree[node].sum +(long long) carry * (e - b + 1);
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    long long int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    long long int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += (long long)((e - b + 1) * x);
        tree[node].prop +=(long long) x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum +(long long) (e - b + 1) * tree[node].prop;
}

int main()
{
    int z,t;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        int n,i,j,k,l,m,x,y,q,d,v;
        scanf("%d%d",&n,&q);
        init(1,0,n-1);
        printf("Case %d:\n",z);
        while(q--)
        {
            scanf("%d",&d);
            if(d==0)
            {
                scanf("%d%d%d",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                scanf("%d%d",&x,&y);
                long long int ans=query(1,0,n-1,x,y,0ll);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}

