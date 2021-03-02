//reference youtube channel loveextends code;

#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx * 4];//array arr er element gula sob somoy tree er leaf node hisebe thakbe mane eder kono
//child thakbe na..
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
int update(int node, int b, int e, int i, int newvalue)///i num index newvalue diye update hobe mane
/// i num index e newvalue rakha hobe||
{
    //int p;
    if (i > e || i < b)
        return 0;
    if (b >= i && e <= i)
    {
        int p=tree[node];
        tree[node] = newvalue;
        return p;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1=update(Left, b, mid, i, newvalue);
    int p2=update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
    return p1+p2;
}
void update1(int node, int b, int e, int i, int newvalue)//i num index newvalue diye update hobe mane
// i num index e newvalue rakha hobe||
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node]+=newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update1(Left, b, mid, i, newvalue);
    update1(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    int z,t;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        int n,i,j,k,l,m,x,y,q,res1,res2;
        scanf("%d%d",&n,&q);
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        init(1,0,n-1);
        printf("Case %d:\n",z);
        while(q--)
        {
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&x);
                res1=update(1,0,n-1,x,0);
                printf("%d\n",res1);
            }
            else if(k==2)
            {
                scanf("%d%d",&x,&y);
                update1(1,0,n-1,x,y);
            }
            else
            {
                scanf("%d%d",&x,&y);
                res2=query(1,0,n-1,x,y);
                printf("%d\n",res2);
            }
        }
    }
    return 0;
}

