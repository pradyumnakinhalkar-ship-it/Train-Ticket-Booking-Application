//user.c
#include<stdio.h>
#include<string.h>
#include"header.h"
extern int validate_password(const char *);
extern int is_username_unique(const char *);
int signup()
{
    user new_user;
    int tries=0;
    printf("Sign_up:\n");
    do
    {
        printf("Enter Username: ");
        scanf("%s",new_user.username);
        if (!is_username_unique(new_user.username))
        {
            printf("Username already exists! Please try another...\n");
        }
    } while (!is_username_unique(new_user.username));
    while(tries<5)
    {
        printf("Enter password: \n");
        scanf("%s",new_user.password);
        if (validate_password(new_user.password))
        {
            FILE *fp=fopen("user_logins.txt","a");
            if(!fp)
            {
                printf("Error opening file.\n");
                return 0;
            }
            fprintf(fp,"%s %s\n",new_user.username,new_user.password);
            fclose(fp);
            printf("Sign-up successful...\n");
            return 1;
        }
        else
        {
            printf("Password must be at least 8 characters, contain uppercase, lowercase, digit, special character. \n");
            tries++;
        }
    }
    printf("TIME OUT,too many tries Please sign-up again later. \n");
    return 0;
}
int signin()
{
char uname[MAX_NAME_LEN],pass[MAX_PASS_LEN];
int attempts=0;
user u;
while(attempts<3)
{
    printf("Enter username: \n");
    scanf("%s",uname);
    printf("Enter password: \n");
    scanf("%s",pass);
    FILE *fp=fopen("user_logins.txt","r");
    if(!fp)
    {
        printf("No user exist.\n");
        return 0;
    }
    int found=0;
    while (fscanf(fp,"%s %s",u.username,u.password)==2)
    {
        if(strcmp(u.username,uname)==0 && strcmp(u.password,pass)==0)
        {
            found=1;
            break;
        }
    }
    fclose(fp);
    if(found)
    {
        printf("Login successful.\n");
        return 1;
    }
    else
    {
        printf("Invalid login. Try again. \n");
        attempts++;
    }
}
printf("You have reached max attempts. Please wait 5 mins to login again.\n");
return 0;
}