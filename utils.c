//utils.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
int validate_password(const char *password)
{
    int has_upper=0,has_lower=0,has_digit=0,has_special=0;
    if(strlen(password)<8)
    {
        return 0;
    }
    for (int i=0;password[i]; i++)
    {
        if(isupper(password[i]))
        {
            has_upper++;
        }
        else if(islower(password[i]))
        {
            has_lower++;
        }
        else if(isdigit(password[i]))
        {
            has_digit++;
        }
        else if(strchr("!@#$%^&*()",password[i]))
        {
            has_special++;
        }
    }
    return has_upper && has_lower && has_digit && has_special;
}
int is_username_unique(const char *username)
{
    FILE *fp=fopen("user_logins.txt","r");
    if (!fp)
  {
        return 1;
    }
    user u;
    while (fscanf(fp,"%s %s",u.username,u.password)==2)
    {
        if (strcmp(u.username,username)==0)
        {
            printf("Username already exists...");
            fclose(fp);
            return 0;
        }   
    }
    fclose(fp);
    return 1;  
}