#ifndef STUD_H
#define STUD_H
#define NAME_SIZE 50
#define DATA_FILE "student.dat"
struct student
{
int rollno;
char name[NAME_SIZE];
float percentage;
struct student*next;
};
void add_record(struct student**head);
void delete_record(struct student**head);
void delete_all(struct student**head);
void show_records(const struct student*head);
void modify_record(struct student*head);
int save_records(const struct student*head);
int load_records(struct student **head);
void sort_records(struct student**head);
void reverse_list(struct student**head);
void free_list(struct student**head);
void clear_input_buffer(void);
int read_int(const char *prompt,int*value);
int read_float(const char*prompt,float*value);
int read_nonempty_name(const char*prompt,char*name,int size);
struct student*find_by_roll(struct student*head,int rollno);
#endif
