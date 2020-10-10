#include <iostream>
using namespace std;
typedef struct node
{
    struct node *lchild;
    char data;
    struct node *rchild;
} bt;
void insert_bt(bt *&tree)
{
    char c;

    tree->lchild = new bt;
    //	cout	<<	"enter	the	left	child	value	for	the	node: "	<<	tree->data	<<	"	";
    cin >> c;
    tree->lchild->data = c;
    if (c != '.')
        insert_bt(tree->lchild);

    tree->rchild = new bt;
    //	cout	<<	"enter	the	right	child	value	for	the	node: "	<<	tree->data	<<	"	";
    cin >> c;
    tree->rchild->data = c;
    if (c != '.')
        insert_bt(tree->rchild);
}
void print_bt(bt *tree)
{
    cout << tree->data << "	";
    if (tree->data != '.')
    {
        print_bt(tree->lchild);
        print_bt(tree->rchild);
    }
}
int main()
{
    bt *tree = new bt;
    char c;
    //	cout	<<	"enter	the	root	node	value	: ";
    cin >> c;
    tree->data = c;

    insert_bt(tree);
    print_bt(tree);
}
