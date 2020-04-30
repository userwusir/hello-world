//��������
#include<stdio.h>
#define max 1000
#define maxsymbs 30		/*���30��Ҷ�ӽ��*/
#define maxbits 10		/*ÿ��Ҷ�ӽ��������10λ*/
#define maxnode 59		/*����2*n-1�����*/
typedef struct
{
	int weight;			/*Ҷ�ӽ��Ȩֵ*/
	int flag;			/*�ж�һ������Ƿ�������������1Ϊ���룬0Ϊδ����*/
	int parent;			/*�������˫����huff_node�е����*/
	int lchild;			/*���������Һ���������huff_node�е����*/
	int rchild;
	}huffnode;
typedef struct
{
	int bits[maxbits];
	int start;
	}huffcode;
int main() 
{
	huffnode huff_node[maxnode];
	huffcode huff_code[maxsymbs],cd;
	int i,j,m1,m2,x1,x2,n,c,p;
	char symbs[maxsymbs],symb;
	printf("�������������");
	scanf("%d",&n);
	for(i=0;i<2*n-1;i++)
	{
		huff_node[i].weight=0;
		huff_node[i].parent=-1;
		huff_node[i].flag=0;
		huff_node[i].lchild=-1;
		huff_node[i].rchild=-1;
	}
	printf("��������Ȩֵ��");
	for(i=0;i<n;i++)
		scanf("%d",&huff_node[i].weight);
	for(i=0;i<n-1;i++)
	{
		m1=m2=max;
		x1=x2=0;
		for(j=0;j<n+i;j++)
		{
			if(huff_node[j].weight<m1&&huff_node[j].flag==0)
			{
				m2=m1;
				x2=x1;
				m1=huff_node[j].weight;
				x1=j;
			}
			else
				if(huff_node[j].weight<m2&&huff_node[j].flag==0)
				{
					m2=huff_node[j].weight;
					x2=j;
				}
		}
		huff_node[x1].parent=n+i;
		huff_node[x2].parent=n+i;
		huff_node[x1].flag=1;
		huff_node[x2].flag=1;
		huff_node[n+i].weight=huff_node[x1].weight+huff_node[x2].weight;
		huff_node[n+i].lchild=x1;
		huff_node[n+i].rchild=x2;
	}
	for(i=0;i<n;i++)
	{
		cd.start=n;
		c=i;
		p=huff_node[c].parent;
		while(p!=-1)
		{
			if(huff_node[p].lchild==c)
				cd.bits[cd.start]=0;
			else
				cd.bits[cd.start]=1;
			cd.start=cd.start-1;
			c=p;
			p=huff_node[p].parent;
		}
		for(j=cd.start+1;j<=n;j++)
			huff_code[i].bits[j]=cd.bits[j];
		huff_code[i].start=cd.start;
	}
	for(i=0;i<n;i++)
		{
			printf("\t%d\t",huff_node[i].weight);
			for(j=huff_code[i].start+1;j<=n;j++)
				printf("%d,",huff_code[i].bits[j]);
				printf("\n");
		}
	return 0;
}	
