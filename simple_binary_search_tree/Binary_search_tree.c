//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct tnode{
    int value;
    struct tnode *left;
    struct tnode *right;
}tnode;
tnode* create_tnode(int value){
    tnode* new_node =malloc(sizeof(tnode));
    if (new_node!=NULL){
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->value=value;
    }
    return new_node;
}
void insert(tnode** rootptr,int value){
    tnode* root=*rootptr;
    if(root==NULL){
        (*rootptr)=create_tnode(value);
        return;
    }
    if(value==root->value){
        return;
    }
    if(value<root->value){
        insert(&(root->left),value);
        return;
    }
    else{
        insert(&(root->right),value);
    }
}
bool is_in_BST(tnode* root,int value){
    if(root==NULL){
        return false;
    }
    if (root->value==value){
        return true;
    }
    if (value<root->value){
        return is_in_BST(root->left,value);
    }
    else{
        return is_in_BST(root->right,value);
    }

}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void print_format(int num_of_char){
        delay(45);
        printf("%c",219);
    for(int i=0;i<num_of_char;i++){
        delay(90);
        printf("       %c",219);
    }
    printf("%c%c%c%c",254,254,254,254);

}
void print_tree(tnode* root,int level){
    if (root==NULL){
        print_format(level);
        printf("...\n");
        return;
    }
    print_format(level);
    printf("%d\n",root->value);
    print_format(level);
    printf("Left\n");
    print_tree(root->left,level+1);
    print_format(level);
    printf("Right\n");
    print_tree(root->right,level+1);
}
int main(){
   tnode* root=NULL;

   insert(&root,65);
   insert(&root,100);
   insert(&root,35);
   insert(&root,6);
   insert(&root,67);


    print_tree(root,0);

   printf("17 (%d)\n",is_in_BST(root,17));
   printf("65 (%d)\n",is_in_BST(root,65));
   printf("100 (%d)\n",is_in_BST(root,100));
   printf("6(%d)\n",is_in_BST(root,6));
   printf("15 (%d)\n",is_in_BST(root,15));
   printf("107 (%d)\n",is_in_BST(root,107));


return 0;
}
