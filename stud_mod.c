#include <stdio.h>
#include <string.h>
#include "stud.h"

void modify_record(struct student *head)
{
    int rollno;
    int choice;
    float percentage;
    char name[NAME_SIZE];
    struct student *temp;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    if (!read_int("Enter roll number to modify: ", &rollno))
        return;

    temp = find_by_roll(head, rollno);

    if (temp == NULL)
    {
        printf("Student record not found.\n");
        return;
    }

    printf("\nCurrent student details:\n");
    printf("Roll Number: %d\n", temp->rollno);
    printf("Name: %s\n", temp->name);
    printf("Percentage: %.2f\n", temp->percentage);

    printf("\n1. Modify name\n");
    printf("2. Modify percentage\n");
    printf("3. Modify both\n");

    if (!read_int("Enter your choice: ", &choice))
        return;

    if (choice == 1 || choice == 3)
    {
        if (!read_nonempty_name("Enter new name: ",
                                name, NAME_SIZE))
            return;

        strcpy(temp->name, name);
    }

    if (choice == 2 || choice == 3)
    {
        if (!read_float("Enter new percentage: ", &percentage))
            return;

        if (percentage < 0 || percentage > 100)
        {
            printf("Percentage must be between 0 and 100.\n");
            return;
        }

        temp->percentage = percentage;
    }

    if (choice < 1 || choice > 3)
    {
        printf("Invalid choice.\n");
        return;
    }

    printf("Student record modified successfully.\n");
}
