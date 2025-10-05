//main.c
#include<stdio.h>
#include"header.h"
extern int signup();
extern int signin();
extern void list_trains();
extern void reserve_ticket();
extern void cancel_ticket();
extern void display_booking();
void menu2()
{
    char opt;
    do
    {
        printf("\n---------MENU-2--------\n");
        printf("R/r: Reserve Ticket\n");
        printf("C/c: Cancel Ticket\n");
        printf("B/b: Booking Details\n");
        printf("Q/q: Quit\n");
        printf("Enter option: ");
        scanf(" %c",&opt);
        switch(opt)
        {
            case'R':case'r':reserve_ticket();
                            break;
            case'C':case'c':cancel_ticket();
                            break;
            case'B':case'b':display_booking();
                            break;
            case'Q':case'q':printf("exiting app\n");
                            break;
            default:printf("invalid option.\n");
        }
    } while (opt!='Q'&&opt!='q');     
}
void menu1()
{
    int choice;
    int success=0;
    do{
    printf("\n---------MENU-1----------\n");
    printf("1: sign-up\n");
    printf("2: sign-in\n");
    printf("choose option: \n");
    scanf("%d",&choice);
    if(choice==1)
    {
        success=signup();
        break;
    }
    else if (choice==2)
    {
        success=signin();
        break;
    }
    else
    {
        printf("invlid option\n");
        break;
    }
}while(!success);
list_trains();
menu2();
}
int main()
{
    menu1();
    return 0;
}