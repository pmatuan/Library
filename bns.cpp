#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *top;
}node;
typedef struct tree{
    node *root;
}tree;
node *createNode(int x){
    node *p = new node;
    p->data = x;
    p->left = p->right = p->top = NULL;
    return p;
}
tree *createTree(){
    tree *t = new tree;
    t->root = NULL;
    return t;
}
tree *insert(tree *t, node *p){
    if(t->root == NULL){
        t->root = p;
    }
    else{
        node *x = t->root;
        node *y = NULL;
        while(x != NULL){
            y = x;
            if(p->data <= x->data){
                x = x->left;
            }
            else x = x->right;
        }
        if(p->data <= y->data){
            p->top = y;
            y->left = p;
        }
        else{
            p->top = y;
            y->right = p;
        }
    }
    return t;
}
void preOrder(node *root){ // NLR
    stack<node *> s;
    node *tmp = root;
    while(tmp != NULL || !s.empty()){
        while(tmp != NULL){
            cout << tmp->data << " ";
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        s.pop();
        tmp = tmp->right;
    }
}
void inOrder(node *root){ // LNR
    stack<node *> s;
    node *tmp = root;
    while(tmp != NULL || !s.empty()){
        while(tmp != NULL){
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        s.pop();
        cout << tmp->data << " ";
        tmp = tmp->right;
    }
}
void postOrder(node *root){ // LRN
    stack<node *> s;
    stack<int> out;
    s.push(root);
    while(!s.empty()){
        node *tmp = s.top();
        s.pop();
        out.push(tmp->data);
        if(tmp->left != NULL) s.push(tmp->left);
        if(tmp->right != NULL) s.push(tmp->right);
    }
    while(!out.empty()){
        cout << out.top() <<" ";
        out.pop();
    }
}
int main(){
    tree *t = createTree();
    int n,x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        node *p = createNode(x);
        t = insert(t,p);
    }
    postOrder(t->root);
}