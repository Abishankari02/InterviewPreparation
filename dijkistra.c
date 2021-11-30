#include<stdio.h>
#define inf 999
#define size 100
int main()
{
	int a[size][size],i,j,n,v1,v2,lcost;
	int dij(int[][j],int,int,int);

	printf("\n*********Implementation of OSPF(Open Shortest Path First)***********\n\n");
	printf("Enter the number of nodes : ");
	scanf("%d",&n);

	//To get Cost Matrix of Autonomous System
	printf("Enter the cost matrix values :\nNOTE : Give Cost as 999 for infinity\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	//To print the cost matrix
	printf("The cost matrix is:\n -------------------------- \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}

	//To display Shortest Path
	printf("\nThe shortest path for all neighbour nodes from the speaker node(N1)\n\n");
	for(j=0;j<n;j++)
	{
		if(j!=0)
		{
			v2=j;
			printf("\n\nFROM N%d TO N%d : \nPath :\t",1,(v2+1));
			lcost=dij(a,n,0,v2); //Use Dijkstras algorithm to find shortest path
			printf("cost :\t%d",lcost);
		}
	}
	printf("\n\n");
	return 0;
}

//Dijkstras algorithm
int dij(int a[size][size],int n,int v1,int v2)
{
	int length[size],set[size],path[size],i,j,s,z,tmp,temp[size],c=0,f=0;
	s=v1;
	z=v2;

	int srch_min(int[],int[],int);

	for(i=0;i<n;i++)
		set[i]=0;
	for(i=0;i<n;i++)
	{
		if(a[s][i]==0)
		{
			length[i]=inf;
			path[i]=0;
		}
		else
		{
			length[i]=a[s][i];
			path[i]=s;
		}
	}
	set[s]=1;
	length[s]=0;

	while(set[z]!=1)
	{
		j=srch_min(length,set,n); //To find Minimum cost path

		set[j]=1;
		for(i=0;i<n;i++)
		{
			if(set[i]!=1)
			{
				if(a[i][j]!=0)
				{
					if(length[j]+a[i][j]<length[i])
					{
						length[i]=length[j]+a[i][j];
						path[i]=j;
					}
				}
			}
		}
	}

	j=0;
	i=z;

	while(i!=s)
	{
		tmp=path[i];
		temp[j]=tmp;
		i=tmp;
		j++;
		c++;
	}

	for(j=c-1;j>=0;j--)
	{
		printf("N%d->",(temp[j]+1));
		if(temp[j]==z)
			f=1;
	}

	if(f!=1)
		printf("N%d",(z+1));
	printf("\n");

	return length[z];
}

//To find Minimum cost
int srch_min(int length[],int set[],int n)
{
	int min,i,min_index;
	min=99999;
	for(i=0;i<n;i++)
	{
		if(set[i]!=1)
		{
			if(length[i]<min)
			{
				min=length[i];
				min_index=i;
			}
		}
	}
return min_index;
}
