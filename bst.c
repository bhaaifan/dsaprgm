#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *lchild, *rchild;
} node;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node* search(node *, int);
node* get_node();

int main() {
    int choice, n, i;
    int key;
    node *new_node, *root = NULL, *tmp;

    printf("\nProgram For Binary Search Tree");
    do {
        printf("\n1. Create");
        printf("\n2. Recursive Traversals");
        printf("\n3. Search");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHow many nodes you want to enter: ");
                scanf("%d", &n);
                printf("\nEnter The %d Elements: ", n);
                for (i = 0; i < n; i++) {
                    new_node = get_node();
                    scanf("%d", &new_node->data);
                    if (root == NULL)
                        root = new_node;
                    else
                        insert(root, new_node);
                }
                break;

            case 2:
                if (root == NULL)
                    printf("Tree Is Not Created");
                else {
                    printf("\nThe Inorder display: ");
                    inorder(root);
                    printf("\nThe Preorder display: ");
                    preorder(root);
                    printf("\nThe Postorder display: ");
                    postorder(root);
                }
                break;

            case 3:
                printf("\nEnter Element to be searched: ");
                scanf("%d", &key);
                tmp = search(root, key);
                if (tmp)
                    printf("\nThe %d Element is Present", tmp->data);
                else
                    printf("\nThe Key %d is not present in the BST", key);
                break;

            default:
                printf("\nTerminating");
                exit(0);
        }
    } while (choice != 4);
}

node* get_node() {
    node *temp = (node *)malloc(sizeof(node));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(node *root, node *new_node) {
    if (new_node->data < root->data) {
        if (root->lchild == NULL)
            root->lchild = new_node;
        else
            insert(root->lchild, new_node);
    }
    if (new_node->data > root->data) {
        if (root->rchild == NULL)
            root->rchild = new_node;
        else
            insert(root->rchild, new_node);
    }
}

node* search(node *root, int key) {
    node *temp = root;
    if (root == NULL) {
        printf("\nBST is Empty");
        return root;
    }
    while (temp != NULL) {
        if (temp->data == key)
            return temp;
        if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    return NULL;
}

void inorder(node *temp) {
    if (temp != NULL) {
        inorder(temp->lchild);
        printf("%d , ", temp->data);
        inorder(temp->rchild);
    }
}

void preorder(node *temp) {
    if (temp != NULL) {
        printf("%d , ", temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}

void postorder(node *temp) {
    if (temp != NULL) {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d , ", temp->data);
    }
}
