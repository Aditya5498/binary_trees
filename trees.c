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

void print(struct nt* a){
    int i;
for(i=1;i<=4;i++){
        p1(a,i);
        printf("\n");
      }
}

int find(struct nt* a,int b){
int c;
if(a == NULL)
    return 0;
else{
    if (a->data==b)
    return 1;
    else{
    c=find(a->left,b);
    if(c!=0)
        return c;
    else
    return find(a->right,b);
}
}
}

int main() {
int i,j,b;
    printf("***** Traversal of binary tree *****\n\n");
      struct nt *a=(struct nt*)malloc(sizeof(struct nt));


      a->data=1;
      a->left=newnode(2);
      a->right=newnode(3);
      a->left->right=newnode(5);
      a->left->left=newnode(4);
      a->right->left=newnode(6);
      a->right->right=newnode(7);


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

printf("Do you want to search for a number?\nIf yes then type 1 or else type any other number\n");
scanf("%d",&j);
if(j==1){
        printf("Enter the nummber\n");
scanf("%d",&j);
if(find(a,j)==1)
    printf("The number %d is found in the tree",j);
else
    printf("The number is not present");
}
 printf("\n Below is the given tree \n");
      print(a);



    return 0;
}
