#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int value;
};

struct LinkedList {
    struct Node* root;
    void (*print)(struct LinkedList*);
};

void print(struct LinkedList* ll);

int main(void)
{
    struct LinkedList* ll = malloc(sizeof(struct LinkedList));
    struct Node* rootNode = malloc(sizeof(struct Node));
    rootNode->value = 1;
    rootNode->next = NULL;
    ll->root = rootNode;
    ll->print = print;

    for (int i = 2; i <= 100; i++)
    {
        struct Node* currentNode = ll->root;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }

        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->value = i;
        currentNode->next = newNode;
    }

    ll->print(ll);
}

void print(struct LinkedList* ll)
{
    struct Node* currentNode = ll->root;

    while (1)
    {
        printf("%i\n",currentNode->value);
        if (currentNode->next == NULL)
            break;
        currentNode = currentNode->next;
    }
}

