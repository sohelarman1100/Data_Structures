//reference youtube channel loveextends code;

#include<bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int cnt=0;
struct info
{
    long long int prop,sum;
};

struct info tree[mx * 4];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        tree[node].prop=0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop=0;
}
int query(int node, int b, int e, int i, int j, int carry)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return cnt+=carry;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    cnt+=carry;
    int p1 = query(Left, b, mid, i, j, tree[Left].prop);
    int p2 = query(Right, mid + 1, e, i, j, tree[Right].prop);
    return p1+p2;
}
void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
}
int main()
{
    int t,z;
    scanf("%d",&t);
    for(z=1; z<=t; z++)
    {
        int n,i,j=0,k,l,m,x,y,p,q,r1,r2,ind,res;
        char c;
        //char s[100005];
        //scanf("%s",s);
        string s;
        cin>>s;
        for(i=0; i<s.size(); i++)
            arr[++j]=s[i]-48;
        n=j;
        init(1, 1, n);//init function array er element gulo use kore tree create korbe

        scanf("%d",&q);
        printf("Case %d:\n",z);
        while(q--)
        {
            //cin>>c;
            scanf(" %c",&c);
            if(c=='I')
            {
                scanf("%d%d",&r1,&r2);
                update(1, 1, n, r1, r2, 1);
            }
            else
            {
                cnt=0;
                scanf("%d",&ind);
                x=tree[1].prop;
                query(1, 1, n, ind, ind,x);
                res=cnt;
                if(res%2==0)
                    printf("%d\n",arr[ind]);
                else
                {
                    if(arr[ind]==1)
                        printf("0\n");
                    else
                        printf("1\n");
                }
            }
        }
    }
    return 0;
}

