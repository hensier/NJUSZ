### A.Fetch Stone By Terms
给定数，只能取质数或者1，最后取的人赢，谁会赢
可以观察到1,2,3都是先手赢，而4无论先手取1或2或3，都是后手赢
归纳假设是四的倍数的是后手赢，其他情况先手赢
观察到如果不是四的倍数，可以取1或2或3变成四的倍数使得后手一定输
而如果是四的倍数，不能取四无论怎么取剩下的都不是4的倍数，后手赢
归纳成立
代码如下:
~~~
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,x;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x;
		if(x%4!=0) printf("xly wins!\n");
		else printf("cyh wins!\n");
	}
	return 0;
} 
~~~

### B.Fliptile
翻转格子使得全为0，翻转会使得上下左右同时翻转
如果对一个格子翻转两次与不翻转的效果是一样的
所以我们可以按照从上到下的顺序探索最小解而不用担心顺序影响答案大小
具体方式
* 先假定第一行哪些格子要翻转
  * 第一行不动之后，我们注意到要使第一行的格子全变成白的情况只有动第二行的（翻转第一行黑色格子下面的格子）
  * 所以第一行确定后，想要全白，第二行的翻转格子是确定的
  * 第二行定了，第三行同理确定
  * 翻转到最后，能否全白就看第n行和第n-1行是否一样
* 每次确定第一行，计算能全白情况下的步数，选择最小的步数的方法输出，没有则输出“IMPOSSIBLE”
* 可以用状态压缩的方法简化枚举翻转过程
~~~
#include<algorithm>
#include<math.h>
#include<iostream>
#include<cstdio>
int m,n,color[20][20],c[20],d[20],ans=1000000,a[20];
int change(int i,int *x){
	int step=0;
	for(int j=1;j<=n;j++)
			if((i>>(j-1))&1==1){
				*x^=(1<<(j-1));
				*(x+1)^=(1<<(j-1));
				if(j!=n) *x^=(1<<j);
				if(j!=1) *x^=(1<<(j-2));
				step++;
			}
	return step;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&color[i][j]);
			c[i]=c[i]|(color[i][j]<<(j-1));
		}
	for(int i=0;i<=(1<<n)-1;i++){
		int s=0,ss[20];
		for(int j=1;j<=m;j++) d[j]=c[j];
		d[0]=i;
		for(int j=1;j<=m;j++)
			s+=change(d[j-1],d+j),ss[j]=d[j-1];
		if(d[m]!=0) continue;
		if(s<ans){
			ans=s;
			for(int j=1;j<=m;j++) a[j]=ss[j];
		}
		if(s==ans){
			bool com=0;
			for(int j=1;j<=m;j++)
				if(a[j]>ss[j]){
					com=1;break; 
				}
				else if(a[j]<ss[j]) break;
			if(com)
				for(int j=1;j<=m;j++) a[j]=ss[j];
		}
	}
	if(ans>225){
		printf("IMPOSSIBLE");
		return 0;
	}
//	printf("%d\n",ans);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if((a[i]>>(j-1))&1==1) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
	return 0;
} 
~~~
 
### C.McDonald
求平方和
求平方和的公式是n*(n+1)*(2*n+1)/6
我们注意到这道题的n的范围很大
高精度
~~~
#include<bits/stdc++.h>

using namespace std;

const int maxn=10050;

int a[maxn];
int b[maxn];
int c[maxn];

inline void calc1() {
	int i;
	for (i=1;b[i]==9;i++) b[i]=0;
	b[i]++;
		
	for (i=1;i<5000;i++)
		for (int j=1;j<=5000;j++)
			c[i+j-1]+=a[i]*b[j];
			
	int g=0;
	for (int i=1;i<maxn;i++) {
		a[i]=(c[i]+g)%10;
		g=(c[i]+g)/10;
		c[i]=0;
	}
}

inline void calc2() {
	int i;
	int g=0;
	for (i=1;i<5000;i++) {
		b[i]=b[i]*2+g;
		g=b[i]/10;
		b[i]%=10;
	}
	for (i=1;b[i]==0;i++) b[i]=9;
	b[i]--;
		
	for (i=1;i<5000;i++)
		for (int j=1;j<5000;j++)
			c[i+j-1]+=a[i]*b[j];
			
	for (i=1;i<maxn;i++) {
		a[i]=(c[i]+g)%10;
		g=(c[i]+g)/10;
	}
	
	g=0;
	for (i=5000;i>=1;i--) {
		g=g*10+a[i];
		c[i]=g/6;
		g%=6;
	}
}

int main() {
	
	string n;cin>>n;
	
	for (int i=0;i<maxn;i++)
		a[i]=b[i]=c[i]=0;
	
	for (int i=0;i<n.length();i++)
		a[1+i]=b[1+i]=n[n.length()-i-1]-'0';
	for (int i=n.length()+1;i<maxn;i++)
		a[i]=b[i]=0;
	
	
	calc1();
	calc2();
	
	int k=maxn-1;
	for (;c[k]==0;k--);
	for (;k>=1;k--)
		printf("%d",c[k]);printf("\n"); 
	return 0;
}

~~~

### D.Jumpy Dumpy!
选最多物品使得物品差的绝对值的最大值< k
n<1000
先排序
枚举最小值，找到小于最小值+k的位置，之间的物品都选择
输出最多的物品的答案
~~~
#include<bits/stdc++.h>
#define writeln(i)cout<<i<<endl;
#define readln(i)cin>>i;
#define inc(i)i++;
#define longint int
#define integer short
#define int64 long long
#define FOR(i,n)for(int i=1;i<=n;i++);
#define array(a)int a[100010]
using namespace std;
longint a[10010];
int main(){
	longint m,n;
	readln(n);
	readln(m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	writeln(ans);
	return 0;
}
~~~

### E.Buy Tickets
每个人插入时是第posi个人 ，每个人都有一个value，
给定n个人插入时的posi，问最后的val序列是什么样的
* 如果我们是边插入边维护的化，当前每一个人的位置都受到后面进来的人的影响，麻烦。所以考虑一下能不能从后往前扫。
* 我们观察一个人的位置，如果他是一个序列的最后一个，那么他的位置就是固定的，考虑从后面往前一个个拿掉
* 后面的人对前面的人的影响怎么计算？
  * 后面的对前面的影响在于他们并没有计入前面的posi中，但是又占了位置。如果我们把位置看作全是1的序列的前缀和的化，后面的人就是里面的0，对前缀和不起作用，但是对下标产生了影响（使得下标后移）。
  * 所以维护一个有n个1的数组c，posn的人拿掉就将c[posn]=0
  * 从后拿到posi的时候，我们需要找到使得c的前缀和等于posi的位置x，这个x就是第i个人的最终位置
* 求前缀和可以用树状数组
  * 具体为二分查找使得query(rank)=posi
  * 然后add(rank,-1)
* 计算出每个人的位置后直接排序输出val即可
~~~
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200005
int n,c[N];
struct node{
	int val,p,rank;
}a[N];
void add(int x,int ad){
	for(;x<=n;x+=x&(-x)) c[x]+=ad;
}
int query(int x){
	int t=0;
	for(;x;x-=x&(-x)) t+=c[x];
	return t; 
}
bool com(node x,node y){return x.rank<y.rank;}
int get(int x){
	int l=1,r=n,res=n;
	while(l<=r){
		int mid=l+r>>1;
		if(query(mid)<x) l=mid+1;
		else r=mid-1,res=min(res,mid);
	}
	return res;
}
int main()
{
	while(cin>>n)
	{
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].p,&a[i].val),a[i].p+=1;
		for(int i=1;i<=n;i++) add(i,1);
		for(int i=n;i>=1;i--)
		{
			a[i].rank=get(a[i].p);
			add(a[i].rank,-1); 
		}//后面的不会被前面的影响，从后往前扫
		sort(a+1,a+1+n,com);
		for(int i=1;i<=n;i++) cout<<a[i].val<<" ";
		cout<<endl;
	}
	return 0;
} 
~~~

F.meeting
求可以同时到达目的地的最短时间
因为n很小，所以可以设置f[t][j][0],f[t][j][1]分别表示两个人能否在第t时间到第j个位置
最后枚举求最小的t满足f[t][j][0]和f[t][j][1]都为1即可
~~~
#include<bits/stdc++.h>
using namespace std;
int m,n,edge1[20][20],edge2[20][20],maxt;
int f[500000][20][2];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			edge1[i][j]=-1,edge2[i][j]=-1;
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a>b) swap(a,b);
		edge1[a][b]=c;
		edge2[a][b]=d;
		//maxt+=max(c,d);
	}
	f[0][1][0]=1;
	f[0][1][1]=1;
//	cout<<maxt<<"qwq"<<endl;
	maxt=16000;
	for(int t=0;t<=maxt;t++)
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				if(t-edge1[k][j]>=0)
					if(f[t-edge1[k][j]][k][0]==1&&edge1[k][j]!=-1)
						f[t][j][0]=1;
				if(t-edge2[k][j]>=0)
					if(f[t-edge2[k][j]][k][1]==1&&edge2[k][j]!=-1)
						f[t][j][1]=1;
			}
		}
	for(int t=0;t<=maxt;t++)
		if(f[t][n][0]==f[t][n][1]&&f[t][n][0]==1){
			printf("%d",t);
			return 0;
			
		}
	printf("IMPOSSIBLE");
	return 0;
}
~~~