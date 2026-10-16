#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud.h"

void add_record(struct student **head)
{
    int rollno;
    float percentage;
    char name[NAME_SIZE];

    if (!read_int("Enter roll number: ", &rollno))
    {
        printf("Invalid roll number.\n");
        return;
    }

    if (rollno <= 0)
    {
        printf("Roll number must be positive.\n");
        return;
    }

    if (find_by_roll(*head, rollno) != NULL)
    {
        printf("Roll number already exists.\n");
        return;
    }

    if (!read_nonempty_name("Enter student name: ", name, NAME_SIZE))
    {
        printf("Invalid name.\n");
        return;
    }

    if (!read_float("Enter percentage: ", &percentage))
    {
        printf("Invalid percentage.\n");
        return;
    }

    if (percentage < 0 || percentage > 100)
    {
        printf("Percentage must be between 0 and 100.\n");
        return;
    }

    struct student *new_node = malloc(sizeof(struct student));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->rollno = rollno;
    strcpy(new_node->name, name);
    new_node->percentage = percentage;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct student *temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    printf("Student record added successfully.\n");
}
