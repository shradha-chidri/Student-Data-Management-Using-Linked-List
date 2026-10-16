#include<stdio.h>
#include "stud.h"
void print_menu(void)
{
printf("\n******** STUDENT RECORD MENU********\n");
printf("a/A:Add new record\n");
printf("d/D:Delete a record\n");
printf("s/S:Show the list\n");
printf("m/M:Modify a record\n");
printf("v/V:Save records\n");
printf("e/E:Exit\n");
printf("t/T:Sort the list\n");
printf("l/L:Delete all the records\n");
printf("r/R:Reverse the list\n");
printf("Enter your choice:");
}
int main(void)
{
struct student*head=NULL;
char choice;
if(load_records(&head)==1)
printf("Records loaded from %s.\n",DATA_FILE);
while(1)
{
print_menu();
scanf("%c",&choice);
clear_input_buffer();
switch(choice)
{
case 'a':
case 'A':
add_record(&head);
break;
case 'd':
case 'D':
delete_record(&head);
break;
case 's':
case 'S':
show_records(head);
break;
case 'm':
case 'M':
modify_record(head);
break;
case 'v':
case 'V':
if(save_records(head))
printf("Records saved successfully.\n");
break;
case 't':
case 'T':
sort_records(&head);
break;
case 'l':
case 'L':
delete_all(&head);
break;
case 'r':
case 'R':
reverse_list(&head);
break;
case 'e':
        case 'E':
            printf("\nS/s: Save and exit\n");
            printf("E/e: Exit without saving\n");
            printf("Enter your choice: ");
            scanf(" %c", &choice);
            clear_input_buffer();

            if (choice == 's' || choice == 'S')
            {
                save_records(head);
                free_list(&head);
                return 0;
            }
            else if (choice == 'e' || choice == 'E')
            {
                free_list(&head);
                return 0;
            }
            else
            {
                printf("Invalid choice.\n");
            }
            break;

        default:
            printf("Invalid menu choice. Please try again.\n");
        }
    }

    return 0;
}





