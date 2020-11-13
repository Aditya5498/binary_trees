#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *left;
struct node *right;
};

struct node* newnode(int data){
struct node * new1 = (struct node*)malloc(sizeof(struct node));
new1->data = data;
new1->left=NULL;
new1->right=NULL;
return new1;
};

void smallest(struct node *a){
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp = a;
while(temp->left!=NULL)
    temp=temp->left;
printf("%d",temp->data);
}

void largest(struct node *a){
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp = a;
while(temp->right!=NULL)
    temp=temp->right;
printf("%d",temp->data);
}

int find(struct node *a,int b){
if(a){
    if(a->data==b)
        return 1;
    else if(a->data>b)
        return find(a->left,b);
    else if(a->data<b)
        return find(a->right,b);
}
else
    return 2;
}

struct node* insert(struct node *a,int i){
struct node *b=(struct node*)malloc(sizeof(struct node));
b=newnode(i);
if(a){
    if(a->left==NULL && a->right==NULL){
        if(a->data>i)
            a->left=b;
        else a->right=b;
        return a;
    }
    else if(a->data>i)
        return insert(a->left,i);
    else if(a->data<i)
        return insert(a->right,i);
}
}

void p1(struct node* a,int l){

if(l==1)
    printf("%d ",a->data);
else{
    p1(a->left,l-1);
    p1(a->right,l-1);
}
}

void print(struct node* a){
    int i;
for(i=1;i<=4;i++){
        p1(a,i);
        printf("\n");
      }
}

int del(struct node *a,int b){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
if (a->left->data==b){
    temp = a->left;
    a->left=a->left->left;
    free(temp);
    return 1;
    }
else if (a->right->data==b){
    temp = a->right;
    a->right=a->right->right;
    free(temp);
    return 1;
    }
else if (a->left->data!=b){
   del(a->left,b);
   del(a->right,b);
    }
    else if (a->right->data!=b){
   del(a->left,b);
   del(a->right,b);
    }
    else if (!a->left || !a->right){
   return 0;
    }
}

void main(){
    int i,c;
struct node *a=(struct node*)malloc(sizeof(struct node));
a->data=5;
a->left=newnode(3);
a->left->right=newnode(4);
a->left->left=newnode(2);
a->right=newnode(7);
a->right->left=newnode(6);
a->right->right=newnode(8);

printf("The smallest number in the BST is ");
smallest(a);
printf("\nThe largest number in the BST is ");
largest(a);

//printf("\n Which number would you like to insert?\n");
//scanf("%d",&i);
//a=insert(a,i);

printf("\nEnter the number you would like to delete: \n");
scanf("%d",&i);
c=del(a,i);
if(c==1)
    printf("The number is deleted\n");
else printf("\n The number was not found\n");

printf("\nEnter the number you would like to search: \n");
scanf("%d",&i);
c=find(a,i);
if(c==1)
    printf("The number is found\n");
else printf("\n The number was not found\n");

print(a);

}
