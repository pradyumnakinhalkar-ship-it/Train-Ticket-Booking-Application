//header.h
#ifndef HEADER_H
#define HEADER_H
#define MAX_NAME_LEN 50
#define MAX_PASS_LEN 20
#define MAX_SOURCE_DEST 30
#define MAX_DATE_LEN 20
#define MAX_SEATS 100
typedef enum {MALE,FEMALE}Gender;
typedef struct  user
{
    char username[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
}user;
typedef struct train
{
    int train_number;
    char train_name[MAX_NAME_LEN];
    char source[MAX_SOURCE_DEST];
    char destination[MAX_SOURCE_DEST];
    int total_seats;
}train;
typedef struct passenger
{
    int seat_number;
    char name[MAX_NAME_LEN];
    int age;
    Gender gender;
}passenger;
typedef struct booking
{
    int train_number;
    char date[MAX_DATE_LEN];
    passenger passenger;
    struct booking *next;    
}booking;
int validate_password(const char *password);
int is_username_unique(const char *username);
void menu1();
void menu2();
int signup();
int signin();
void list_trains();
void reserve_ticket();
void cancel_ticket();
void display_booking();
#endif


