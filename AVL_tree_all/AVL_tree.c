//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>
typedef struct tnode{
    int value,height;
    struct tnode *left;
    struct tnode *right;
}tnode;


tnode* create_tnode(int value){
    tnode* new_node =malloc(sizeof(tnode));
    if (new_node!=NULL){
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->value=value;
        new_node->height=1;
    }
    return new_node;
}


int height(tnode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}


int int_max(int a, int b)
{
    return (a > b)? a : b;
}


tnode *rightRotate(tnode *y)
{
    tnode *x = y->left;
    tnode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = int_max(height(y->left), height(y->right))+1;
    x->height = int_max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}


tnode *leftRotate(tnode *x)
{
    tnode *y = x->right;
    tnode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = int_max(height(x->left), height(x->right))+1;
    y->height = int_max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}


int getBalance(tnode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


tnode* insert(tnode* node, int value)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(create_tnode(value));

    if (value < node->value)
        node->left  = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else // Equal values are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + int_max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}


bool is_in_AVL_tree(tnode* root,int value){
    if(root==NULL){
        return false;
    }
    if (root->value==value){
        return true;
    }
    if (value<root->value){
        return is_in_AVL_tree(root->left,value);
    }
    else{
        return is_in_AVL_tree(root->right,value);
    }

}


int count_leaf_node(tnode* root){

    if (root==NULL)
        return 0;
    else if (root->left==NULL&&root->right==NULL)
        return 1;
    return (count_leaf_node(root->left)+count_leaf_node(root->right));

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
    int choice=1,value;
   tnode* root=NULL;
   while (1){

        system("cls");
        if (choice==1){
            printf("\nEnter the value");
            scanf("%d",&value);
            root=insert(root,value);
            print_tree(root,0);
        }
        else if (choice==2){
        printf("\nEnter the value");
        scanf("%d",&value);
        value=is_in_AVL_tree(root,value);
            if (value==1){
                printf("\n YES it's in this AVL tree");
            }
            else{
                printf("\n NO it's not in this AVL tree");
            }
        }
        else if (choice==3){
            printf("\n Number of leaf node in this AVL tree is %d",count_leaf_node(root));
        }
        else if (choice == 4){
            printf("\n hight of AVL tree is : %d ",root->height);
        }
        else{
            return 0;
        }
    printf("\nEnter 1 to insert another node");
    printf("\nEnter 2 to check key in AVL tree ");
    printf("\nEnter 3 to count number of leaf in AVL tree ");
    printf("\nEnter 4 to print hight of  AVL tree");
    printf("\nEnter the choice: ");
    scanf("%d",&choice);
   }

return 0;
}
