#include <stdio.h>
#include "stud.h"

void show_records(const struct student *head)
{
    const struct student *temp = head;

    if (temp == NULL)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");
    printf("%-10s %-25s %-12s\n",
           "Roll No", "Name", "Percentage");
    printf("-------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-10d %-25s %.2f%%\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("=====================================\n");
}
