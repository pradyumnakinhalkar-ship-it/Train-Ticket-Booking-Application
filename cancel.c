//cancel.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
void cancel_ticket()
{
    int train_number,seat_no;
    char date[MAX_DATE_LEN];
    printf("Enter train number: \n");
    scanf("%d",&train_number);
    printf("Enter Date (YYYY-MM-DD): \n");
    scanf("%s",date);
    printf("Enter Seat Number to Cancel: \n");
    scanf("%d",&seat_no);
    FILE *fp=fopen("bookings_info.txt","r");
    FILE *temp=fopen("temp.txt","w");
    if(!fp||!temp)
    {
        printf("Error opening files. \n");
        return;
    } 
    booking b;
    int found=0;
    while (fscanf(fp,"%d %s %d %s %d %d\n",&b.train_number,b.date,&b.passenger.seat_number,b.passenger.name,&b.passenger.age,(int *)&b.passenger.gender)==6)
    {
        if (b.train_number==train_number && strcmp(b.date,date)==0 && b.passenger.seat_number==seat_no)
        {
            printf("Booking for seat %d cancelled.\n",seat_no);
            found=1;
            continue;
        }
        fprintf(temp,"%d %s %d %s %d %d\n",b.train_number,b.date,b.passenger.seat_number,b.passenger.name,b.passenger.age,b.passenger.gender);
    }
    fclose(fp);
    fclose(temp);
    remove("bookings_info.txt");
    rename("temp.txt","bookings_info.txt");
    if(!found)
    {
        printf("No Booking found for the given seat.\n");
    }    
}