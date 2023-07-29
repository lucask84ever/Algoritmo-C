#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* right;
    struct Node* left;
};


struct Node* createNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> value = value;
    node -> right = NULL;
    node -> left = NULL;
    return node;
}

void print1(struct Node *root) {
    if (root == NULL) {
        return;
    }
    print1(root->right);
    print1(root->left);
    printf("%d\n", root->value);
}
void print2(struct Node *root) {
    if (root == NULL) {
        return;
    }
    
    print2(root->right);
    printf("%d\n", root->value);
    print2(root->left);
    
}
void print3(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->value);
    print3(root->right);
    print3(root->left);
}

void print4(struct Node *root) {
    printf("TODO: NEED CALCULATE TREE HEIGHT");
}


int main()
{
    struct Node *root = createNode(1);
    root->right = createNode(2);
    root->left = createNode(3);
    root->right->right = createNode(4);
    root->right->left = createNode(5);
    root->left->right = createNode(6);
    root->left->left = createNode(7);
    printf("%s:\n", "Post-order Traversal");
    print1(root);
    printf("\n");
    printf("%s:\n", "In-order Traversal");
    print2(root);
    printf("\n");
    printf("%s:\n", "Pre-order Traversal");
    print3(root);
    printf("\n");
    printf("%s:\n", "Level-order Traversal");
    print4(root);
    printf("\n");
    return 0;
}
