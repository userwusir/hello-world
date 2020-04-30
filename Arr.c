#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
typedef struct bkbtnode
{
	int data;						/*结点数据域*/
	struct babtnode *lchild;		/*左孩子结点*/
	struct babtnode *rchild;		/*右孩子结点*/
}Bnode,*BTnode;
typedef struct
{
	int data[100];				/*队列数据域*/
	int front;					/*队头指针*/ 
	int rear;					/*队尾指针*/ 
}BTree;
int CreateBiTree(BTnode *T)		/*建立二叉链表*/ 
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
		printf("输入%d的左子结点：",ch);
		CreateBiTree(&(*T)->lchild);
		printf("输入%d的右子结点：",ch);
		CreateBiTree(&(*T)->rchild);
	}
	return 1;
}
void TraversalLevel(BTnode bt)		/*寻找x结点的深度*/ 
{	
	int x;
	scanf("%d",&x); 
    if(bt!=NULL)
    {
		int last=1,level=1;		/*last指向各层最右结点位置，level记录层数*/ 
		BTree *q;
		q->front=0;
		q->rear=1;
		q->data[1]=bt;			/*根节点入队*/ 
		while(q->front<=last)
		{
			bt=q->data[++q->front]; 
			if(bt->data==x)
			{
				printf("%d\n",level);
				return level;
			}
			if(bt->lchild!=NULL)
			q->data[++q->rear]=bt->lchild;		/*左孩子入队列*/ 
			if(bt->rchild!=NULL)
			q->data[++q->rear]=bt->rchild;		/*右孩子入队列*/ 
			if(q->front==last)
			{
				last=q->rear;		/*本层最后一个结点处理完毕*/ 
				level++;
			}
		}
	}	
   }
int main()
{
	BTnode T;
	printf("请输入第一个结点，输入-1代表没有叶子结点："); 
	CreateBiTree(&T);
	printf("请输入需要查找深度的结点："); 
	TraversalLevel(T);
	return 0;
}
  
