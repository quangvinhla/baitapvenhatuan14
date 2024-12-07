#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct Node {
    char value;           
    struct Node *left;   
    struct Node *right;   
} Node;

// Khởi tạo một Node mới
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm kiểm tra nếu cây rỗng
int isEmpty(Node* root) {
    return root == NULL;
}

// Hàm thêm phần tử vào cây 
Node* insertNode(Node* root, char value) {
    if (isEmpty(root)) {
        root = createNode(value);
    } else {
    }
    return root;
}

// Duyệt cây theo Trung Tố
void infix(Node* root) {
    if (root != NULL) {
        if (root->left != NULL) printf("(");
        infix(root->left);
        printf("%c", root->value);
        infix(root->right);
        if (root->right != NULL) printf(")");
    }
}

// Duyệt cây theo Tiền Tố 
void prefix(Node* root) {
    if (root != NULL) {
        printf("%c", root->value);
        prefix(root->left);
        prefix(root->right);
    }
}

// Duyệt cây theo Hậu Tố
void postfix(Node* root) {
    if (root != NULL) {
        postfix(root->left);
        postfix(root->right);
        printf("%c", root->value);
    }
}
// Hàm in 
void printTree(Node* root) {
    printf("Infix: ");
    infix(root);
    printf("\n");

    printf("Prefix: ");
    prefix(root);
    printf("\n");

    printf("Postfix: ");
    postfix(root);
    printf("\n");
}
Node* constructExpressionTree() {
    // (a * 5 - b * c^6 / d) + (h - f) * e^1 / 2
    Node* root = createNode('+');
        // Tạo cây con phía bên trái của root (a*5 - b*c^6/d)
    root->left = createNode('-');
    root->left->left = createNode('*');
    root->left->left->left = createNode('a');
    root->left->left->right = createNode('5');
    root->left->right = createNode('/');
    root->left->right->left = createNode('*');
    root->left->right->left->left = createNode('b');
    root->left->right->left->right = createNode('c');
    root->left->right->left->right->right = createNode('6');
    root->left->right->right = createNode('d');
        // Tạo cây con phía bên phải của root (h - f) * e^1 / 2
    root->right = createNode('*');
    root->right->left = createNode('-');
    root->right->left->left = createNode('h');
    root->right->left->right = createNode('f');
    root->right->right = createNode('/');
    root->right->right->left = createNode('e');
    root->right->right->right = createNode('2');

    return root;
}
int main() {
    Node* root = constructExpressionTree();
    // In cây theo ba kiểu
    printTree(root);
    return 0;
}