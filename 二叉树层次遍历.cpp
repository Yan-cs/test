#include<iostream>
#include<stdio.h>
#include<math.h>
#define  MAXQSIZE  100
using  namespace  std;

struct BiNode {
	int  data;
	BiNode  *lchild,*rchild;
};
struct SqQueue {
	BiNode* base[100];
	int front,rear;
};
void CreateBiTree(BiNode  *&T) {
	char  ch;
	cin>>ch;
	if(ch=='#')T=NULL;
	else {
		T=new  BiNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void LevelOrder(BiNode *&T){
	BiNode *d;
	SqQueue q;								//初始化 
	q.front = 0;
	q.rear = 0;
	q.base[++q.rear]=T;						//入队
	while(q.rear!=q.front){					// 判断是否为对空
		d = q.base[++q.front];				//出队 
		cout<<(char)d->data;
		if(d->lchild)						//左孩子有孩子时入队 
			q.base[++q.rear]=d->lchild;
		if(d->rchild)							//右孩子有孩子时入队
			q.base[++q.rear]=d->rchild;
	} 
}

int  main() {

	BiNode  *Tree;
	CreateBiTree(Tree);
	LevelOrder(Tree);
	return  0;
}
