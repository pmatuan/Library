#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int max(int a, int b){
    return (a>b)?a:b;
}
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
void printTree_LNR(node *p){ // Tăng dần
	if (p != NULL){
		printTree_LNR(p->left);
		printf("%d ", p->data);
		printTree_LNR(p->right);
	}
}
node *create(int x){
    node *p = malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
}
node *insert(node *p, int x){
    if(p == NULL){
        p = create(x);
    }
    else{
        if(p->data <= x){
            p->right = insert(p->right,x);
        }
        else p->left = insert(p->left,x);
    }
    return p;
}
node *minNode(node *p){
    node *tmp = p;
    while(p && tmp->left!=NULL) tmp = tmp->left;
    return tmp;
}
node *delete(node *p, int x){
    if(p == NULL) return NULL;
    if(p->data > x) p->left = delete(p->left, x);
    else if (p->data < x) p->right = delete(p->right, x);
    else{
        if(p->left!= NULL && p->right!= NULL){
            node *tmp = minNode(p->right);
            p->data = tmp->data;
            p->right = delete(p->right, tmp->data);
        }
        else{
            node *tmp = p;
            if(p->left == NULL) p = p->right;
            else p = p->left;
            free(tmp);
        }
    }
    return p;
}
int treeLevel(node *p){
    if(p == NULL) return -1;
    else return 1 + max(treeLevel(p->left), treeLevel(p->right));
}
node *turnRight(node *p){
    node *b = p->left;
    node *c = b->right;
    b->right = p;
    p->left = c;
    return b;
}
node *turnLeft(node *p){
    node *b = p->right;
    node *c = b->left;
    p->right = c;
    b->left = p;
    return b;
}
int checkAVL(node *p){
    if(p == NULL) return 1;
    if(abs(treeLevel(p->left) - treeLevel(p->right)) > 1) return 0;
    return (checkAVL(p->right) && checkAVL(p->left));
}
node *AVLTree(node *p){
    if(abs(treeLevel(p->left) - treeLevel(p->right)) > 1){
        if(treeLevel(p->left) > treeLevel(p->right)){
            node *a = p->left;
            if(treeLevel(a->left) > treeLevel(a->right)) p = turnRight(p);
            else if(treeLevel(a->left) < treeLevel(a->right)){
                p->left = turnLeft(p->left);
                p = turnRight(p);
            }
        }
        else{
            node *a = p->right;
            if(treeLevel(a->right) > treeLevel(a->left)) p = turnLeft(p);
            else{
                p->right = turnRight(p->right);
                p = turnLeft(p);
            }
        }
    }
    if(p->left != NULL) p->left = AVLTree(p->left);
    if(p->right != NULL) p->right = AVLTree(p->right);
    return p;
}
int main(){
    int n,x;
    scanf("%d",&n);
    node *p = NULL;
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        p = insert(p,x);
    }
    while(!checkAVL(p)){
        p = AVLTree(p);
    }
    // BNS đã được chuyển thành AVL 
    // nếu thực hiện xóa, cứ xóa BNS trước rồi chuyển về AVL sau
}