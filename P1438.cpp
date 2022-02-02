#include<bits/stdc++.h>
using namespace std;
#define int long long
int sm[1000010];
int  a[1000010];
int ad[1000010];
void build(int x,int l,int r)
{
	if(r==l)
	{
		sm[x]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*x,l,mid);
	build(2*x+1,mid+1,r);
	sm[x]=sm[2*x]+sm[2*x+1]; 
	
}
void add(int x,int l,int r,int v)
{
	sm[x]+=(r-l+1)*v;
	ad[x]+=v;
}
void push(int x,int l,int r)
{
	int mid=(l+r)/2;
	add(2*x,l,mid,ad[x]);
	add(2*x+1,mid+1,r,ad[x]);
	ad[x]=0;
}
void change(int x,int l,int r,int L,int R,int v)
{
	if(L>r||l>R)
	{
		return;
	}
	if(l>=L&&r<=R)
	{
		add(x,l,r,v);
		return;
	}
	push(x,l,r);
	int mid=(l+r)/2;
	change(2*x,l,mid,L,R,v);
	change(2*x+1,mid+1,r,L,R,v);
	sm[x]=sm[2*x]+sm[2*x+1];
}
int query(int x,int l,int r,int L,int R)
{
	if(L>r||l>R)
	{
		return 0;
	}
	if(l>=L&&r<=R)
	{
		return sm[x];
	}
	push(x,l,r);
	int mid=(l+r)/2;
	return query(2*x,l,mid,L,R)+query(2*x+1,mid+1,r,L,R);
}
signed main()
{
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	//build(1,1,n+10);
	while(m--)
	{
		int o;
		scanf("%lld",&o);
		if(o==1)
		{
			int l,r,K,D;
			scanf("%lld %lld %lld %lld",&l,&r,&K,&D);
			change(1,1,n+10,l,l,K);
			change(1,1,n+10,l+1,r,D);
			change(1,1,n+10,r+1,r+1,-(K+(r-l)*D));
		}else
		{
			int p;
			scanf("%lld",&p);
			printf("%lld\n",query(1,1,n+10,1,p)+a[p]);
		}
	}
	
}
