//train.c
#include<stdio.h>
#include"header.h"
void list_trains()
{
    FILE *fp=fopen("trains_info.txt","r");
    if(fp==NULL)
    {
        printf("no trains available\n");
        return;
    }
    train t;
    printf("Available trains: \n");
    printf("%-10s %-20s %-15s %-15s %-10s\n","TrainNo","TrainName","Source","Destination","Seats");
    while(fscanf(fp,"%d %s %s %s %d",&t.train_number,t.train_name,t.source,t.destination,&t.total_seats)==5)
    {
        printf("%-10d %-20s %-15s %-15s %-10d\n",t.train_number,t.train_name,t.source,t.destination,t.total_seats);
    }
    fclose(fp);
}