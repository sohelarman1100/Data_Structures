///reference youtube channel loveextends code;

#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx * 3];///array arr er element gula sob somoy tree er leaf node hisebe thakbe mane eder kono
///child thakbe na..
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left],tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 1000000;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1,p2);
}
int main()
{
    int t,z;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        int n,i,j,k,l,m,x,y,q;
        scanf("%d%d",&n,&q);
        for(i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        init(1,1,n);
        printf("Case %d:\n",z);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            k=query(1,1,n,x,y);
            printf("%d\n",k);
        }
    }
    return 0;
}

