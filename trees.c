#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node* insert_node(struct Node* node, int data) {
    if (node == NULL) {
        return create_node(data);
    } else {
        if (data < node->data) {
            node->left = insert_node(node->left, data);
        } else {
            node->right = insert_node(node->right, data);
        }
        return node;
    }
}

void inorder_recursive(struct Node* node) {
    if (node != NULL) {
        inorder_recursive(node->left);
        printf("%d ", node->data);
        inorder_recursive(node->right);
    }
}

void inorder_non_recursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder_recursive(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }
}

void preorder_non_recursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    stack[++top] = current;
    while (top != -1) {
        current = stack[top--];
        printf("%d ", current->data);
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

void postorder_recursive(struct Node* node) {
    if (node != NULL) {
        postorder_recursive(node->left);
        postorder_recursive(node->right);
        printf("%d ", node->data);
    }
}

void postorder_non_recursive(struct Node* root) {
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    struct Node* current = root;
    stack1[++top1] = current;
    while (top1 != -1) {
        current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
    printf("\n1. Insert Node");
    printf("\n2. Inorder Traversal (Recursive)");
    printf("\n3. Inorder Traversal (Non-Recursive)");
    printf("\n4. Preorder Traversal (Recursive)");
    printf("\n5. Preorder Traversal (Non-Recursive)");
    printf("\n6. Postorder Traversal (Recursive)");
    printf("\n7. Postorder Traversal (Non-Recursive)");
    printf("\n8. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            root = insert_node(root, data);
            break;
        case 2:
            printf("\nInorder Traversal (Recursive): ");
            inorder_recursive(root);
            break;
        case 3:
            printf("\nInorder Traversal (Non-Recursive): ");
            inorder_non_recursive(root);
            break;
        case 4:
            printf("\nPreorder Traversal (Recursive): ");
            preorder_recursive(root);
            break;
        case 5:
            printf("\nPreorder Traversal (Non-Recursive): ");
            preorder_non_recursive(root);
            break;
        case 6:
            printf("\nPostorder Traversal (Recursive): ");
            postorder_recursive(root);
            break;
        case 7:
            printf("\nPostorder Traversal (Non-Recursive): ");
            postorder_non_recursive(root);
            break;
        case 8:
            printf("\nExiting...");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.");
    }
}

return 0;
}