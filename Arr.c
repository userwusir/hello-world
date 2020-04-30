#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
typedef struct bkbtnode
{
	int data;						/*���������*/
	struct babtnode *lchild;		/*���ӽ��*/
	struct babtnode *rchild;		/*�Һ��ӽ��*/
}Bnode,*BTnode;
typedef struct
{
	int data[100];				/*����������*/
	int front;					/*��ͷָ��*/ 
	int rear;					/*��βָ��*/ 
}BTree;
int CreateBiTree(BTnode *T)		/*������������*/ 
{
	ElemType ch;
	ElemType temp;
	scanf("%d",&ch);
	temp=getchar();
	if(ch==-1)
	{
		*T=NULL;
	}
	else
	{
		*T=(BTnode)malloc(sizeof(Bnode));
		if(!(*T))
		{
			exit(-1);
		}
		(*T)->data=ch;
		printf("����%d�����ӽ�㣺",ch);
		CreateBiTree(&(*T)->lchild);
		printf("����%d�����ӽ�㣺",ch);
		CreateBiTree(&(*T)->rchild);
	}
	return 1;
}
void TraversalLevel(BTnode bt)		/*Ѱ��x�������*/ 
{	
	int x;
	scanf("%d",&x); 
    if(bt!=NULL)
    {
		int last=1,level=1;		/*lastָ��������ҽ��λ�ã�level��¼����*/ 
		BTree *q;
		q->front=0;
		q->rear=1;
		q->data[1]=bt;			/*���ڵ����*/ 
		while(q->front<=last)
		{
			bt=q->data[++q->front]; 
			if(bt->data==x)
			{
				printf("%d\n",level);
				return level;
			}
			if(bt->lchild!=NULL)
			q->data[++q->rear]=bt->lchild;		/*���������*/ 
			if(bt->rchild!=NULL)
			q->data[++q->rear]=bt->rchild;		/*�Һ��������*/ 
			if(q->front==last)
			{
				last=q->rear;		/*�������һ����㴦�����*/ 
				level++;
			}
		}
	}	
   }
int main()
{
	BTnode T;
	printf("�������һ����㣬����-1����û��Ҷ�ӽ�㣺"); 
	CreateBiTree(&T);
	printf("��������Ҫ������ȵĽ�㣺"); 
	TraversalLevel(T);
	return 0;
}
  
