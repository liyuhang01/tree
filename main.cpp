#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct BitNode{
    ElemType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;

//创建二叉树
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
//先序遍历
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);

    }
}

//中序遍历
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
//后序遍历
void PostTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);

        InOrderTraverse(T->rchild);
        cout<<T->data;
    }
}
//求二叉树的深度
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
//统计二叉树节点的数量
int NodeCount(BiTree T){
    if(T==NULL){
        return 0;
    }else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
//销毁二叉树
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
	printf("****                  ****系统菜单****                ****\n");
	printf("****            *  1.创建二叉树                  *    ****\n");
	printf("****            *  2.先序遍历二叉树              *    ****\n");
	printf("****            *  3.中序遍历二叉树              *    ****\n");
	printf("****            *  4.后序遍历二叉树              *    ****\n");
	printf("****            *  5.求二叉树的深度              *    ****\n");
	printf("****            *  6.求二叉树的节点数量          *    ****\n");
	printf("****            *  7.销毁二叉树                  *    ****\n");
	printf("****            *  8.退出                        *    ****\n");
	printf("**********************************************************\n");
		printf("请输入操作代码:");
		scanf("%d",&code);
		getchar();
		switch(code)
		{
		case 1:
			{
			    printf("请输入二叉树元素（‘#’表示为空）\n");
			    CreateBiTree(T);
                printf("二叉树创建成功\n");
                flag=1;
				break;
			}
		case 2:
			{
                if(flag==0){
                    printf("二叉树未创建\n");
                }else{
                    printf("先序遍历后:\n");
                PreOrderTraverse(T);
                printf("\n");
		    }
				break;
			}
		case 3:
                if(flag==0){
                    printf("二叉树未创建\n");
                }else{
                    printf("中序遍历后:\n");
                    InOrderTraverse(T);
                    printf("\n");
                }

		    break;
		case 4:
		    if(flag==0){
                    printf("二叉树未创建\n");
                }else{
                    printf("先序遍历后:\n");
                PostTraverse(T);
                printf("\n");
		    }


		    break;
		case 5:
		    int deep;
            if(flag==0){
                printf("二叉树未创建\n");
            }else{
                deep=Depth(T);
                printf("二叉树的深度为：%d\n",deep);
		    }
			break;
		case 6:
		    int num;
		    if(flag==0){
                printf("二叉树未创建\n");
            }else{
                num=NodeCount(T);
                printf("二叉树的节点数量为：%d\n",num);
		    }
		    break;
		case 7:
		    if(flag==0){
                printf("二叉树未创建\n");
            }else{
                DestroyBitree(T);
                flag=0;
                printf("二叉树已被销毁\n",num);
		    }
		    break;
		case 8:
			{
				printf("程序结束!\n");
				return 0;
				break;
			}
		default:printf("数据无效，请重新输入!");
		}
		system("pause");
	}
}
