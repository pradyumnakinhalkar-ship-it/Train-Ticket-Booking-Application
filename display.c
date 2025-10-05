//display.c
#include<stdio.h>
#include<string.h>
#include"header.h"
void display_booking()
{
    int train_number,seat_no;
    int file_train,file_seat,file_age,gender_num;
    char file_name[50];
    char data[MAX_DATE_LEN],file_data[MAX_DATE_LEN];
    printf("Enter train number: \n");
    scanf("%d",&train_number);
    printf("Enter date(YYYY-MM-DD): \n");
    scanf("%s",data);
    printf("Enter seat number: ");
    scanf("%d",&seat_no);
    FILE *fp=fopen("bookings_info.txt","r");
    if(!fp)
    {
        printf("No bookings found.\n");
        return;
    }
    int found=0;
    while (fscanf(fp,"%d %s %d %s %d %d",&file_train,file_data,&file_seat,file_name,&file_age,&gender_num)==6)
    {
        if(file_train==train_number && strcmp(file_data,data )==0 && file_seat==seat_no)
        {
            printf("Booking Details: \n");
            printf("Name: %s,Age: %d,Gender: %s\n",file_name,file_age,gender_num==0?"Male":"Female");
            found=1;
            break;
        }
    }
    fclose(fp);
    if(!found)
    {
        printf("Booking not found.\n");
    }
}