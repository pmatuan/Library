#include<stdio.h>
#include<stdlib.h>
int max(int a, int b){
    return (a>b)?a:b;
}
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *create(int x){
    node *p = malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
node *add(node *t, int x){
    if(t == NULL){
        node *p = create(x);
        t = p;
    }
    else{
        if(x >= t->data){
            t->right = add(t->right, x);
        }
        else{
            t->left = add(t->left, x);
        }
    }
    return t;
}

/*Duyệt cây nhị phân*/
void printTree_NLR(node *t){
	if (t != NULL){
        printf("%d ", t->data);
		printTree_NLR(t->left);
		printTree_NLR(t->right);
	}
}
void printTree_NRL(node *t){
	if (t != NULL){
        printf("%d ", t->data);
		printTree_NRL(t->right);
		printTree_NRL(t->left);
	}
}
void printTree_LNR(node *t){ // Tăng dần
	if (t != NULL){
		printTree_LNR(t->left);
		printf("%d ", t->data);
		printTree_LNR(t->right);
	}
}
void printTree_RNL(node *t){ // Giảm dần
	if (t != NULL){
		printTree_RNL(t->right);
		printf("%d ", t->data);
		printTree_RNL(t->left);
	}
}
void printTree_RLN(node *t){
	if (t != NULL){
		printTree_RLN(t->right);
		printTree_RLN(t->left);
        printf("%d ", t->data);
	}
}
void printTree_LRN(node *t){
	if (t != NULL){
		printTree_LRN(t->left);
        printTree_LRN(t->right);
        printf("%d ", t->data);
	}
}
/*----------------------------------------*/
node *search(node *t, int x){
    node *p = malloc(sizeof(node));
    if(t==NULL){
        p = NULL;
    }
    else{
        if(t->data > x){
            p = search(t->left,x);
        }
        else if(t->data < x){
            p = search(t->right,x);
        }
        else p = t;
    }
    return p;
}
/*Node 2 con, node 1 con, node lá*/
void node_2_con(node *t){
    if(t!=NULL){
        if(t->left!=NULL && t->right!=NULL){
            printf("%d ",t->data);
        }
        node_2_con(t->left);
        node_2_con(t->right);
    }
}
void node_1_con(node *t){
    if(t!=NULL){
        if(t->left == NULL && t->right != NULL || t->left != NULL && t->right == NULL){
            printf("%d ", t->data);
        }
        node_1_con(t->left);
        node_1_con(t->right);
    }
}
void nodeLeaf(node *t){
    if(t!=NULL){
        if(t->left == NULL && t->right == NULL){
            printf("%d ",t->data);
        }
        nodeLeaf(t->left);
        nodeLeaf(t->right);
    }
}
int isLeaf(node *t){
    return (t->left == NULL && t->right == NULL);
}
int countLeaf(node *t){
    if(t == NULL) return 0;
    if(isLeaf(t)) return 1;
    else return countLeaf(t->left) + countLeaf(t->right);
}
int treeLevel(node *t){
    if(t == NULL) return -1;
    else return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
node *minNode(node *p){
    node *tmp = p;
    while(p && tmp->left!=NULL) tmp = tmp->left;
    return tmp;
}
/*----------------------------------------*/