#include<stdio.h>
#include<stdlib.h>

struct node
{
int length;
int flag;
int prev;
};
int ads[10][10],i,j;
int path[10],source,dest,n;

main()
{
void shortpath(void);
printf("Enter the node :");
scanf("%d",&n);
printf("Enter the adjascent matrix of {%d %d}(-1 for no edge):\n",n,n);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&ads[i][j]);
printf("Enter the Source and Destination : ");
scanf("%d%d",&source,&dest);

shortpath();
} 

void shortpath(void)
{
struct node a[10];
int k,min;
for(i=1;i<=n;i++)
{
a[i].length=999;
a[i].flag=0;
a[i].prev=0;
}
k=source;
a[k].flag=1;
a[k].length=0;
while(k!=dest)
{
	for(i=1;i<=n;i++)
	if((ads[k][i]>0)&&(a[i].flag==0))
	if((a[k].length+ads[k][i])<a[i].length)
	{
		a[i].prev=k;
		a[i].length=a[k].length+ads[k][i];
	}
	min=999;
	k=0;
	for(i=1;i<=n;i++)
	{
	if((a[i].flag==0) && (a[i].length<min))
	{
		min=a[i].length;
		k=i;
	}
}
a[k].flag=1;
}//wc


path[0]=dest;
k=dest;
i=1;
while(k!=0)
{
j=a[k].prev;
if(j>0)
path[i++]=j;
k=j;
}
printf("The shortest path is: ");
for(j=i-1;j>=0;j--)
printf("%d",path[j]);
printf("\nShortest path length is :%d",a[dest].length);
}

