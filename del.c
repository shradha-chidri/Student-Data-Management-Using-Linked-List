#include <stdio.h>
#include <stdlib.h>
#include "stud.h"

void delete_record(struct student **head)
{
    struct student *temp;
    struct student *prev = NULL;
    int rollno;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (!read_int("Enter roll number to delete: ", &rollno))
        return;

    temp = *head;

    while (temp != NULL && temp->rollno != rollno)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student record not found.\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student record deleted successfully.\n");
}

void delete_all(struct student **head)
{
    struct student *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    printf("All student records deleted.\n");
}
