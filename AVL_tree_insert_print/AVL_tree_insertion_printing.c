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

//functions to print a tree (AVL tree)
//this delay function will helps to view the output data properly
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
// post-order traversal
void post_order_print_tree(tnode* root,int level){
    if (root==NULL){
        print_format(level);
        printf("...\n");
        return;
    }
    print_format(level);
    printf("%d(L-%d)\n",root->value,level);
    print_format(level);
    printf("Right\n");
    post_order_print_tree(root->right,level+1);
    print_format(level);
    printf(" Left\n");
    post_order_print_tree(root->left,level+1);

}

int main(){
    int choice=1,value;
   tnode* root=NULL;
   while (1){
        if (choice==1){
            printf("\nEnter the value : ");
            scanf("%d",&value);
            root=insert(root,value);
            printf("\n PreOrder view \n");
            pre_order_print_tree(root,0);
        }
        else if (choice==2){
            system("cls");
            printf("\n PostOrder view \n");
            post_order_print_tree(root,0);
        }
        else{
            return 0;
        }
    printf("\n 1 :Insert another node ");
    printf("\n 2 :PostOrder view of tree\n   Enter your choice : ");
    scanf("%d",&choice);
}

return 0;
}
