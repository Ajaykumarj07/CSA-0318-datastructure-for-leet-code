#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int height(struct node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct node* rotate_left(struct node* y) {
    struct node* x = y->left;
    struct node* temp = x->right;
    x->right = y;
    y->left = temp;
    return x;
}

struct node* rotate_right(struct node* y) {
    struct node* x = y->right;
    struct node* temp = x->left;
    x->left = y;
    y->right = temp;
    return x;
}

int get_balance(struct node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node* delete(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        struct node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

struct node* search(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    int choice, data;
    struct node* root = NULL;

    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            root = delete(root, data);
            break;
        case 3:
            printf("Enter the data to search: ");
            scanf("%d", &data);
            struct node* result = search(root, data);
            if (result != NULL) {
                printf("Data found in the tree.\n");
            } else {
                printf("Data not found in the tree.\n");
            }
            break;
        case 4:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
