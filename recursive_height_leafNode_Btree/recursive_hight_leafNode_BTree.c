//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
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

int int_max(int a, int b)
{
    return (a > b)? a : b;
}
//calculating the height of tree in a recursive function
int height(tnode *N){
    if (N == NULL)
        return 0;
    return 1 + int_max(height(N->left),height(N->right));// recursive call
}
//counting the number of leaf nodes in a recursive function
int count_leaf_node(tnode* root){

    if (root==NULL)
        return 0;
    else if (root->left==NULL&&root->right==NULL)
        return 1;
    return (count_leaf_node(root->left)+count_leaf_node(root->right));//recursive call

}

tnode* insert(tnode* node, int value){
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(create_tnode(value));

    if (value < node->value)
        node->left  = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else // Equal values are not allowed in BST
        return node;


}

//functions to print a tree (AVL tree)
//this delay function will helps to view the output data properly
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void print_format(int num_of_char){
        delay(45);
        printf("%c",219);
    for(int i=0;i<num_of_char;i++){
        delay(90);
        printf("        %c",219);
    }
    printf("%c%c%c%c",254,254,254,254);
}

// pre-order traversal
void pre_order_print_tree(tnode* root,int level){
    if (root==NULL){
        print_format(level);
        printf("...\n");
        return;
    }
    print_format(level);
    printf("%d(L:%d)\n",root->value,level);
    print_format(level);
    printf(" Left\n");
    pre_order_print_tree(root->left,level+1);
    print_format(level);
    printf("Right\n");
    pre_order_print_tree(root->right,level+1);
}


int main(){
    int choice=1,value;
   tnode* root=NULL;
   while (1){
        if (choice==1){
            system("cls");
            printf("\nEnter the value : ");
            scanf("%d",&value);
            root=insert(root,value);
            //calling height function and count leaf node function
            printf("\nHEIGHT : %d \nNUMBER OF LEAF NODES : %d\n",height(root),count_leaf_node(root));
            printf("\n\n\n PreOrder view \n");
            pre_order_print_tree(root,0);
        }
        else{
            return 0;
        }
    printf("\n Enter 1 to insert another node :");
    scanf("%d",&choice);
}

return 0;
}
