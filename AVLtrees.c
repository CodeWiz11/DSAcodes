#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
    int ht;
};

typedef struct node * NODE;
NODE root = NULL;

NODE create(int);
NODE insert(NODE, int);
NODE delete(NODE, int);
NODE search(NODE, int);
NODE rotate_left(NODE);
NODE rotate_right(NODE);
int balance_factor(NODE);
int height(NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);

int main()
{
    int user_choice, data;
    NODE result = NULL;

    while (1)
    {
        printf("Enter your choice\n");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &user_choice);

        switch(user_choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL)
                {
                    printf("\nNode not found!");
                }
                else
                {
                    printf("\n Node found");
                }
                break;
            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;

            case 7:
                printf("\n\tProgram Terminated\n");
                return 1;

            default:
                printf("\n\tInvalid Choice\n");
        }


    }

    return 0;
}

NODE create(int data)
{
    NODE new_node = (NODE) malloc (sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

NODE rotate_left(NODE root)
{
    NODE right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;

    root->ht = height(root);
    right_child->ht = height(right_child);

    return right_child;
}

NODE rotate_right(NODE root)
{
    NODE left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;

    root->ht = height(root);
    left_child->ht = height(left_child);

    return left_child;
}

int balance_factor(NODE root)
{
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}

int height(NODE root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;

    if (lh > rh)
        return (lh);
    return (rh);
}

NODE insert(NODE root, int data)
{
    if (root == NULL)
    {
        NODE new_node = create(data);
        if (new_node == NULL)
        {
            return NULL;
        }
        root = new_node;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);

        if (balance_factor(root) == -2)
        {
            if (data > root->right->data)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        root->left = insert(root->left, data);

        if (balance_factor(root) == 2)
        {
            if (data < root->left->data)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    root->ht = height(root);
    return root;
}

struct node * delete(NODE root, int x)
{
    struct node * temp = NULL;

    if (root == NULL)
    {
        return NULL;
    }

    if (x > root->data)
    {
        root->right = delete(root->right, x);
        if (balance_factor(root) == 2)
        {
            if (balance_factor(root->left) >= 0)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    else if (x < root->data)
    {
        root->left = delete(root->left, x);
        if (balance_factor(root) == -2)
        {
            if (balance_factor(root->right) <= 0)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        {
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            if (balance_factor(root) == 2)
            {
                if (balance_factor(root->left) >= 0)
                {
                    root = rotate_right(root);
                }
                else
                {
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        }
        else
        {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}

NODE search(NODE root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }

    if(key > root->data)
    {
        search(root->right, key);
    }
    else
    {
        search(root->left, key);
    }
}

void inorder(NODE root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
