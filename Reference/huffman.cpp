#include <stdio.h>
#include <queue>
#include <functional>
#include <stdlib.h>
#define MAX 100

using namespace std;

typedef struct Node
{
    char c; // 0이면 그룹
    int fre; // frequency
    Node* left;
    Node* right;

    bool operator >(const Node& A) const 
    {
        return fre > A.fre;
    }
}Node, *PNode;

int N;

priority_queue<Node, vector<Node>, greater<Node> > heap;

char code[MAX];

void print_code(PNode node, int size)
{
    if (node->c)
    {
        code[size] = 0;
        printf("%c : %s\n", node->c, code);
    }
    else
    {
        if (node->left)
        {
            code[size] = '0';
            print_code(node->left, size + 1);
        }
        if (node->right)
        {
            code[size] = '1';
            print_code(node->right, size + 1);
        }
    }
}

int main()
{
    int i, j;

    char c;
    int fre;

    Node node;
    PNode parent, left, right;

    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("\n%c %d", &node.c, &node.fre);
        heap.push(node);
    }

    for (i = 1; i < N; i++)
    {
        left = (PNode)malloc(sizeof(Node));
        right = (PNode)malloc(sizeof(Node));
        parent = (PNode)malloc(sizeof(Node));

        *left = heap.top(); heap.pop();
        *right = heap.top(); heap.pop();

        parent->left = left;
        parent->right = right;
        parent->fre = left->fre + right->fre;
        parent->c = 0;

        heap.push(*parent);
    }

    print_code((PNode)&heap.top(), 0);

    return 0;
}