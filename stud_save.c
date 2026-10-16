#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stud.h"

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int read_int(const char *prompt, int *value)
{
    char line[100];
    char extra;

    printf("%s", prompt);

    if (fgets(line, sizeof(line), stdin) == NULL)
        return 0;

    if (sscanf(line, " %d %c", value, &extra) != 1)
        return 0;

    return 1;
}

int read_float(const char *prompt, float *value)
{
    char line[100];
    char extra;

    printf("%s", prompt);

    if (fgets(line, sizeof(line), stdin) == NULL)
        return 0;

    if (sscanf(line, " %f %c", value, &extra) != 1)
        return 0;

    return 1;
}

int read_nonempty_name(const char *prompt, char *name, int size)
{
    size_t len;

    printf("%s", prompt);

    if (fgets(name, size, stdin) == NULL)
        return 0;

    len = strlen(name);

    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';
    else
        clear_input_buffer();

    len = strlen(name);

    if (len == 0)
        return 0;

    for (size_t i = 0; i < len; i++)
    {
        if (name[i] == '|')
            return 0;
    }

    return 1;
}

struct student *find_by_roll(struct student *head, int rollno)
{
    while (head != NULL)
    {
        if (head->rollno == rollno)
            return head;

        head = head->next;
    }

    return NULL;
}

void free_list(struct student **head)
{
    struct student *temp = *head;

    while (temp != NULL)
    {
        struct student *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
}

int save_records(const struct student *head)
{
    FILE *fp = fopen(DATA_FILE, "w");

    if (fp == NULL)
    {
        printf("Unable to open file for saving.\n");
        return 0;
    }

    while (head != NULL)
    {
        fprintf(fp, "%d|%s|%.2f\n",
                head->rollno, head->name, head->percentage);
        head = head->next;
    }

    fclose(fp);
    return 1;
}

int load_records(struct student **head)
{
    FILE *fp = fopen(DATA_FILE, "r");
    int rollno;
    float percentage;
    char name[NAME_SIZE];
    char line[200];

    if (fp == NULL)
        return 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (sscanf(line, "%d|%49[^|]|%f",
                   &rollno, name, &percentage) != 3)
            continue;

        if (find_by_roll(*head, rollno) != NULL)
            continue;

        struct student *new_node = malloc(sizeof(struct student));

        if (new_node == NULL)
        {
            fclose(fp);
            return 0;
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
                temp = temp->next;

            temp->next = new_node;
        }
    }

    fclose(fp);
    return 1;
}

void sort_records(struct student **head)
{
    struct student *i;
    struct student *j;
    int rollno;
    float percentage;
    char name[NAME_SIZE];

    if (*head == NULL || (*head)->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }

    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->rollno > j->rollno)
            {
                rollno = i->rollno;
                i->rollno = j->rollno;
                j->rollno = rollno;

                percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = percentage;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);
            }
        }
    }

    printf("Records sorted by roll number.\n");
}

void reverse_list(struct student **head)
{
    struct student *prev = NULL;
    struct student *current = *head;
    struct student *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("Student list reversed.\n");
}
