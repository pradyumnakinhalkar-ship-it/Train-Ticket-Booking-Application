//booking.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
void reserve_ticket()
{
    int train_number,num_seat;
    char date[MAX_DATE_LEN];
    printf("Enter Train Number: \n");
    scanf("%d",&train_number);
    printf("Enter Date(YYYY-MM-DD): \n");
    scanf("%s",date);
    printf("Enter No. of Seats: \n");
    scanf("%d",&num_seat);
    FILE *fp=fopen("bookings_info.txt","a");
    if(!fp)
    {
        printf("Cannot open file\n");
        return;
    }
    int booked=0;
    passenger p;
    for(int i=0;i<num_seat;i++)
    {
        if(booked>=MAX_SEATS)
        {
            printf("Only %d seats are available.Reamining %d cannot be booked.\n",MAX_SEATS,num_seat-booked);
            break;
        }
        printf("passenger %d Name: ",i+1);
        scanf("%s",p.name);
        printf("Age: ");
        scanf("%d",&p.age);
        printf("Gender (0=Male, 1=Female): ");
        scanf("%d",&p.gender);
        p.seat_number=booked+1;
        fprintf(fp,"%d %s %d %s %d %d\n",train_number,date,p.seat_number,p.name,p.age,p.gender);
        printf("Seat assigned to %s: %d\n",p.name,p.seat_number);
        booked++;
    }
    fclose(fp);
    printf("%d tickets booked successfully.\n",booked);
}