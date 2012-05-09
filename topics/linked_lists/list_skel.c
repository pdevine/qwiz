
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head_node, *z;

void initialize_list(int data)
{
    head_node = (struct node *) malloc(sizeof *head_node);
    head_node->next = NULL;
    head_node->data = data;
}

void delete_next(struct node *current_node)
{
    current_node->next = current_node->next->next;
    // free(current_node);
}

struct node *insert_after(int data, struct node *current_node)
{
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof *new_node);
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return new_node;
}

void display_list(struct node *head_node)
{
    struct node *current_node;
    current_node = head_node;

    while(current_node != NULL)
    {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }

    printf("NULL\n");
}

struct node *nth_to_last_node(int nth, struct node *head_node)
{
    // O(1) space
    // O(n) time

    struct node *current_node = head_node;
    struct node *runner_node = head_node;

    while(current_node != NULL)
    {
        if(nth >= 0)
            nth--;
        else
            runner_node = runner_node->next;
        current_node = current_node->next;
    }

    if(nth == -1)
        return runner_node;

    return NULL;

}

void delete_duplicates(struct node *head_node)
{
    // O(1) space
    // O(n^2) time

    if(head_node == NULL)
        return;

    struct node *current_node;
    struct node *runner_node;

    current_node = head_node;

    while(current_node != NULL)
    {
        runner_node = current_node;

        while(runner_node->next != NULL)
        {
            if(runner_node->next->data == current_node->data)
            {
                runner_node->next = runner_node->next->next;
            }

            runner_node = runner_node->next;
        }

        current_node = current_node->next;
    }
}

int main()
{
    struct node *my_node;

    initialize_list(5);
    my_node = insert_after(5, head_node);
    my_node = insert_after(2, my_node);
    my_node = insert_after(7, my_node);
    my_node = insert_after(9, my_node);
    my_node = insert_after(7, my_node);
    my_node = insert_after(10, my_node);

    display_list(head_node);
    delete_duplicates(head_node);
    display_list(head_node);

    my_node = nth_to_last_node(2, head_node);
    printf("nth to last: %d\n", my_node->data);

    my_node = nth_to_last_node(1, head_node);
    printf("nth to last: %d\n", my_node->data);

}

