#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stud.h"

void delete_record(struct student **head)
{
    int rollno;
    struct student *temp = *head;
    struct student *prev = NULL;

    if (*head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    if (!read_int("Enter roll number to delete: ", &rollno))
    {
        printf("Invalid roll number.\n");
        return;
    }

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
    struct student *temp = *head;

    while (temp != NULL)
    {
        struct student *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    printf("All student records deleted successfully.\n");
}
