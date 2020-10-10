#include <iostream>
using namespace std;
typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} bst;
void insert_bst(bst *&tree, int x)
{
    if (!tree)
    {
        tree = new bst;
        tree->data = x;
        tree->lchild = nullptr;
        tree->rchild = nullptr;
    }
    else
    {
        if (x < tree->data)
            insert_bst(tree->lchild, x);
        else
            insert_bst(tree->rchild, x);
    }
}
void print_bst(bst *tree)
{
    if (tree)
    {
        print_bst(tree->lchild);
        cout << tree->data << ;
        print_bst(tree->rchild);
    }
}
int main()
{
    bst *tree = nullptr;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        insert_bst(tree, x);
    }
    print_bst(tree);
}
