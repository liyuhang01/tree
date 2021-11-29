#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct BitNode{
    ElemType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;

//����������
void CreateBiTree(BiTree &T){
    ElemType ch;
    cin>>ch;
    if(ch=='#'){
         T=NULL;
    }else{
        T=new BitNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }

}
//�������
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);

    }
}

//�������
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
//�������
void PostTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);

        InOrderTraverse(T->rchild);
        cout<<T->data;
    }
}
//������������
int Depth(BiTree T){
    int m,n;
    if(T==NULL){
        return 0;
    }else{
        m=Depth(T->lchild);
        n=Depth(T->rchild);
        if(m>n){
            return (m+1);
        }else{
            return (n+1);
        }
    }
}
//ͳ�ƶ������ڵ������
int NodeCount(BiTree T){
    if(T==NULL){
        return 0;
    }else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
//���ٶ�����
void DestroyBitree(BiTree T){
    if(T){
        DestroyBitree(T->lchild);
        DestroyBitree(T->rchild);
        free(T);
    }

}
int main(){
	int code;
	int flag=0;
	BiTree T=NULL;
	while(1){
	system("cls");
	printf("**********************************************************\n");
	printf("****                  ****ϵͳ�˵�****                ****\n");
	printf("****            *  1.����������                  *    ****\n");
	printf("****            *  2.�������������              *    ****\n");
	printf("****            *  3.�������������              *    ****\n");
	printf("****            *  4.�������������              *    ****\n");
	printf("****            *  5.������������              *    ****\n");
	printf("****            *  6.��������Ľڵ�����          *    ****\n");
	printf("****            *  7.���ٶ�����                  *    ****\n");
	printf("****            *  8.�˳�                        *    ****\n");
	printf("**********************************************************\n");
		printf("�������������:");
		scanf("%d",&code);
		getchar();
		switch(code)
		{
		case 1:
			{
			    printf("�����������Ԫ�أ���#����ʾΪ�գ�\n");
			    CreateBiTree(T);
                printf("�����������ɹ�\n");
                flag=1;
				break;
			}
		case 2:
			{
                if(flag==0){
                    printf("������δ����\n");
                }else{
                    printf("���������:\n");
                PreOrderTraverse(T);
                printf("\n");
		    }
				break;
			}
		case 3:
                if(flag==0){
                    printf("������δ����\n");
                }else{
                    printf("���������:\n");
                    InOrderTraverse(T);
                    printf("\n");
                }

		    break;
		case 4:
		    if(flag==0){
                    printf("������δ����\n");
                }else{
                    printf("���������:\n");
                PostTraverse(T);
                printf("\n");
		    }


		    break;
		case 5:
		    int deep;
            if(flag==0){
                printf("������δ����\n");
            }else{
                deep=Depth(T);
                printf("�����������Ϊ��%d\n",deep);
		    }
			break;
		case 6:
		    int num;
		    if(flag==0){
                printf("������δ����\n");
            }else{
                num=NodeCount(T);
                printf("�������Ľڵ�����Ϊ��%d\n",num);
		    }
		    break;
		case 7:
		    if(flag==0){
                printf("������δ����\n");
            }else{
                DestroyBitree(T);
                flag=0;
                printf("�������ѱ�����\n",num);
		    }
		    break;
		case 8:
			{
				printf("�������!\n");
				return 0;
				break;
			}
		default:printf("������Ч������������!");
		}
		system("pause");
	}
}
