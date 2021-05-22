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
	SqQueue q;								//��ʼ�� 
	q.front = 0;
	q.rear = 0;
	q.base[++q.rear]=T;						//���
	while(q.rear!=q.front){					// �ж��Ƿ�Ϊ�Կ�
		d = q.base[++q.front];				//���� 
		cout<<(char)d->data;
		if(d->lchild)						//�����к���ʱ��� 
			q.base[++q.rear]=d->lchild;
		if(d->rchild)							//�Һ����к���ʱ���
			q.base[++q.rear]=d->rchild;
	} 
}

int  main() {

	BiNode  *Tree;
	CreateBiTree(Tree);
	LevelOrder(Tree);
	return  0;
}
