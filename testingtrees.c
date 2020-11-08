#include<stdio.h>
#include<stdlib.h>
#define int_min 0
struct node{
int data;
struct node* left;
struct node* right;
};

struct node *newnode(int b){
struct node *a=(struct node*)malloc(sizeof(struct node));
a->data=b;
a->left=NULL;
a->right=NULL;

return a;
};

int max(struct node *a){
if(a)
return max(a->left)+max(a->right)+1;
}

void print(struct node *a,int l){
if(l==0)
printf(" %d ",a->data);
else{
    print(a->left,l-1);
    print(a->right,l-1);
}
}

void pl(struct node*a){
int i,j;
for(i=0;i<3;i++){
    print(a,i);
    printf("\n");
}
}

void del(struct node* a){
if(a){
    del(a->left);
    del(a->right);
    free(a);
}
}

int height(struct node *a){
int l,r;
if(a){
    l=height(a->left);
    r=height(a->right);
    if(l>r)
            return l+1;
    else
        return r+1;
}

}

int leafs(struct node *a){

if(a){
            if(a->left==NULL && a->right==NULL)
                return 1;
            else
                return leafs(a->left)+leafs(a->right);
}

}

int hleafs(struct node *a){
if(a){
    if((a->left!=NULL &&a->right==NULL) || (a->left==NULL && a->right!=NULL))
        return 1;
    else
        return hleafs(a->left)+hleafs(a->right);
}
}

int sum(struct node *a){
if(a){
    return sum(a->left)+sum(a->right)+a->data;
}
}

struct node *mirror(struct node *a){
       struct node *temp;
if(a){
   mirror(a->left);
    mirror(a->right);
    temp = a->left;
    a->left=a->right;
    a->right=temp;
    }
     return a;
};

void main(void){
struct node *a = (struct a*)malloc(sizeof(struct node));
struct node *temp = (struct a*)malloc(sizeof(struct node));
int i,j;
a->data=0;
a->left=newnode(1);
a->right=newnode(2);
a->left->left=newnode(3);
a->left->right=newnode(4);
a->right->left=newnode(5);
a->right->right=newnode(6);

printf("Counting number of leaf nodes...\n The number of leaf nodes are %d\n",leafs(a));
printf("\nThe number of half leafs are %d\n",hleafs(a));

printf("The sum of all the elements is %d\n",sum(a));


printf("\n The height of the tree is %d\n\n",height(a));
printf("The number of elements in the tree are %d\n\n Below is the binary tree \n",max(a));
pl(a);
temp=mirror(a);
printf("\nThe mirrored tree is\n");
pl(temp);

printf("\nDeleting the tree\n");
del(a);

printf("\nSuccessfully deleted the tree\n");

printf("\n ********* DOne with all the code ********");
free(a);
}
