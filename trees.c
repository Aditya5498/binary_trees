#define int_min 0
#include <stdio.h>
#include<stdlib.h>

struct nt{
    struct nt *left;
    int data;
    struct nt *right;
};

void preorder(struct nt *a){
    if(a){
    printf("%d ",a->data);
    preorder(a->left);
    preorder(a->right);
}
}
void inorder(struct nt *a){
if(a){
    inorder(a->left);
    printf("%d ",a->data);
    inorder(a->right);
}
}

postorder(struct nt *a){
if(a){
    postorder(a->left);
    postorder(a->right);
     printf("%d ",a->data);
}
}

int fmax(struct nt *a){
int val,left,right,max=int_min;
if(a!=NULL){
    val=a->data;
    left=fmax(a->left);
    right=fmax(a->right);
    if(left>right) max=left;
    else max=right;
    if(val>max)
        max=val;
}
return max;
}

struct nt* newnode(int a){
struct nt *n=(struct nt*)malloc(sizeof(struct nt));
n->data=a;
n->right=NULL;
n->left=NULL;
return(n);
};

void p1(struct nt* a,int l){

if(l==1)
    printf("%d ",a->data);
else{
    p1(a->left,l-1);
    p1(a->right,l-1);
}
}

int main() {
int i,j,b;
    printf("***** Traversal of binary tree *****\n");
      struct nt *a=(struct nt*)malloc(sizeof(struct nt));


      a->data=1;
      a->left=newnode(2);
      a->right=newnode(3);
      a->left->right=newnode(5);
      a->left->left=newnode(4);
      a->right->left=newnode(6);
      a->right->right=newnode(7);

      printf("\n Below is the given tree \n");
      for(i=1;i<=4;i++){
        p1(a,i);
        printf("\n");
      }

printf("PreOrder is\t");
      preorder(a);
      printf("\n");
      printf("InOrder is\t");
     inorder(a);
      printf("\n");
      printf("PostOrder is\t");
      postorder(a);
      printf("\n");
printf("The largest value of the binary tree is %d\n",fmax(a));



    return 0;
}
