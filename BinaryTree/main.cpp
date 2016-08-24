#include <iostream>
using namespace std;

static const int SIZE = 100;

typedef char datatype;
typedef struct BinNode{
    datatype data;
    BinNode *lchild;
    BinNode *rchild;
}BinNode;

typedef BinNode* bintree;

typedef struct seqstack{
    bintree data[SIZE];
    int tag[SIZE];
    int top;
}seqstack;

void push(seqstack *s, bintree t)
{
    if(s->top == SIZE)
        cout << "the stack is full" << endl;
    else{
        s->top++;
        s->data[s->top] = t;
    }
}

bintree pop(seqstack *s)
{
    if(s->top == -1)
    {
        cout << "the stack is empty" << endl;
        return NULL;
    }
    else
    {
        s->top--;
        return s->data[s->top];
    }
}

void preorder(bintree t)
{
    if(t)
    {
        cout << t->data << endl;
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void preorder_dev(bintree t)
{
    seqstack s;
    s.top = -1;
    if(!t)
        cout << "the tree is empty" << endl;
        
    while(t || s.top != -1)
    {
        while(t)
        {
            cout << t->data << endl;
            push(&s, t);
            t = t->lchild;
        }
        t = pop(&s);
        t = t->rchild;
    }
}

int main()
{
   cout << "Hello World" << endl; 
   
   return 0;
}

