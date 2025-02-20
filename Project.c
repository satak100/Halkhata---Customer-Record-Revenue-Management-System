#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
void new_record(void);
void menu(void);
void edit(void);
void erase(void);
void helping_hand(void);
void revenue(void);
void discount(void);
void yearwise_revenue(void);
struct date
{
    int month,day,year;
};
struct {
    char name[100];
    int acc_no;
    int phone;
    struct date buy;
    }add,check,rem,upd;
struct
{
    float buy;
    float paid;
    float remaining;
}cost;

struct
{   char district[20];
    char thana[20];
    char house_no[20];
}address,update;

struct revenue
{
    int month;
    float total_sell;
};

int main_exit;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
//code for quote(used time random function to generate quote)
void quote(void)
{
    srand(time(NULL));
    int x=rand()%10;
    switch(x)
    {
    case 0: printf("Success is not final, failure is not fatal, it is the courage to continue that counts. \n-Winston Churchill");
        break;
    case 1: printf("Play by the rules, but be ferocious.\n-Phil Knight");
        break;
    case 2: printf("Business opportunities are like buses, there's always another one coming.\n-Richard Branson");
        break;
    case 3: printf("Every problem is a gift—without problems we would not grow.\n-Anthony Robbins");
        break;
    case 4: printf("You only have to do a few things right in your life so long as you don't do too many things wrong.\n-Warren Buffett");
        break;
    case 5: printf("Success usually comes to those who are too busy to be looking for it.\n-Henry David Thoreau");
        break;
    case 6: printf("And the day came when the risk to remain tight in a bud was more painful than the risk it took to blossom.\n-Anaïs Nin");
        break;
    case 7: printf("There's no shortage of remarkable ideas, what's missing is the will to execute them.\n-Seth Godin");
        break;
    case 8: printf("I owe my success to having listened respectfully to the very best advice, and then going away and doing the exact opposite.\n-G.K.Chesterton");
        break;
    case 9: printf("I don't know the word 'quit'. Either I never did, or I have abolished it.\n-Susan Butcher");
        break;

    }
}
//main function consists of passcode & first page interface
int main()
{
    char pass[10],password[10]="satak";
    int i=0;

    for(i=0;i<120;i++)
        printf("*");
    printf("\n   \t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO PROJECT HALKHATA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    for(i=0;i<120;i++)
        printf("*");
    system("color E4");
    printf("\n");
     quote();
     printf("\n\n\n");

    for(int i=0;i<60;i++)
        printf("<>");

    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN PAGE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n\t\t\t\t\t   PASSCODE: ");
    i=0;
    int c;
    while(i<10)
	{
	    pass[i]=getch();
	    c=pass[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pass[i]='\0';
    if (strcmp(pass,password)==0)
        {printf("\n\nWELCOME!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".....");
        }
            system("cls");
           menu();
        }
    else
        {   printf("\n\nWRONG!!!!\a\a\a");
            login_try:
            printf("\n\nPress 1 to try again and 0 to exit:\n");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();
                    }
            else
                    {
                    printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;
                    }

        }
        return 0;
}
//main menu design. used switch to call function using number
void menu(void)
{   int choice;
    system("cls");
    system("color B1");

    printf("\n\n\n  \t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t  1. New Record");
    printf("\n\n\t\t\t  2. View All customer's list");
    printf("\n\n\t\t\t  3. Edit Customer data & for Clearing Dues");
    printf("\n\n\t\t\t  4. Delete Customer data");
    printf("\n\n\t\t\t  5. Check Remaining Dues of customer (by range)");
    printf("\n\n\t\t\t  6. REVENUE");
    printf("\n\n\t\t\t  7. Give Discount(%%)");
    printf("\n\n\t\t\t  8. Exit");
    printf("\n\n\n\t\t\t  Enter your choice according to number: ");
    scanf("%d",&choice);

    system("cls");
    int x;
    switch(choice)
    {
        case 1:new_record();
        break;
        case 2:view_list();
        break;
        case 3:edit();
        break;
        case 4:erase();
        break;
        case 5:check_range();
        break;
        case 6:revenue();
        break;
        case 7:discount();
        break;
        case 8:exit(-1);
        break;

    }
}
//function for adding new record
//1. Account number generated randomly but not repeating, 2. Date manual, 3. Name address
//4. phone, 5. Due Remaining , total buy

void new_record()
{
    int choice;
    FILE *ptr;
    ptr=fopen("record.txt","a+");
    system("cls");
    system("color DF");
    srand(time(NULL));
    account_no:
    check.acc_no=rand()%100000+100000;

    while(fscanf(ptr,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
                goto account_no;
            }

    }

    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.buy.month,&add.buy.day,&add.buy.year);
    getchar();
    add.acc_no=check.acc_no;
    printf("\nName:");
    fgets(add.name,100,stdin);
    printf("\nAddress Section:\n");
    printf("District: ");
    fgets(address.district,100,stdin);
    printf("Thana: ");
    fgets(address.thana,100,stdin);
    printf("House Number: ");
    fgets(address.house_no,100,stdin);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\nEnter the amount the customer bought:TK. ");
    scanf("%f",&cost.buy);
    printf("\nEnter the amount the customer paid:TK. ");
    scanf("%f",&cost.paid);
    cost.remaining=cost.buy-cost.paid;

    fprintf(ptr,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,address.district,address.thana,address.house_no,add.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);
    fclose(ptr);

    printf("\nData Added successfully.");

    add_invalid:
    printf("\n\n\n\t\tENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!Try again with proper keyword.\a");
            goto add_invalid;
        }
}

void view_list(void)
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    system("color F4");

    while(fscanf(view,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
       {

           printf("***Record No:         %d\n",add.acc_no);
           printf("Name of the Customer: %s\n",add.name);
           printf("*Remaining Money:     %g \n",cost.remaining);
           printf("Address:  District: %s, Thana: %s, H/N: %s\n",address.district,address.thana,address.house_no);
           printf("Purchase Amount:      %g\n",cost.buy);
           printf("Paid Amount:          %g\n",cost.paid);
           for(int i=0;i<60;i++)
            printf("<>");
            printf("\n\n");

           test++;
       }
    fclose(view);

    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
//this function helps to edit phone, address & due amount clearance
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    helping_hand();
    printf("\n\n");

    printf("\nEnter the record no. of the buyer whose info you want to change:");
    scanf("%d",&upd.acc_no);

    while(fscanf(old,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n3.Due Money\n\nEnter your choice(1 for address and 2 for phone and 3 for due money):");
            scanf("%d",&choice);
            getchar();
            system("cls");
            if(choice==1)
            {
            printf("Enter the new address:");
            printf("District: ");
            gets(update.district);
            printf("Thana: ");
            gets(update.thana);
            printf("House Number: ");
            gets(update.house_no);
            fprintf(newrec,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,update.district,update.thana,update.house_no,add.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);
                system("cls");
                printf("Successfully changed!!");
            }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%d",&upd.phone);
    fprintf(newrec,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,address.district,address.thana,address.house_no,upd.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);
                system("cls");
                printf("Successfully changed!!");
                }
            else if(choice==3)
            {
                float paying_money;
                printf("Customer cleared the amount: ");
                scanf("%f",&paying_money);
                cost.remaining=cost.remaining-paying_money;
    fprintf(newrec,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,address.district,address.thana,address.house_no,add.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);
                system("cls");
                printf("Successfully changed!!");
            }
        }
    else
    fprintf(newrec,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,address.district,address.thana,address.house_no,add.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);
    }

    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");

    if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}
//function to erase data
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    helping_hand();
    printf("\n\n");
    printf("Enter the record no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while(fscanf(old,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
    {
        if(add.acc_no!=rem.acc_no)
    fprintf(newrec,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,address.district,address.thana,address.house_no,add.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {
        printf("\nENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}
// search within remaining dues upto lower & upper limit
void check_range(void)
{
    FILE*check=fopen("record.txt","r");
    float range1,range2;
    printf("Enter the lower limit of range: ");
    scanf("%f",&range1);
    printf("Enter the upper limit of range: ");
    scanf("%f",&range2);
    printf("\n\n");
    int test=0;
    while(fscanf(check,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
    {
        test++;
        if (cost.remaining>=range1 && cost.remaining<=range2)
        {
            printf("PAYMENT DUE: %g\n",cost.remaining);
            printf("Record No: %d\n",add.acc_no);
            printf("Name of the customer: %s\n",add.name);
            printf("Date: %d/%d/%d\n\n\n",add.buy.month,add.buy.day,add.buy.year);
        }
    }

    fclose(check);
    if(test==0)
        {
            printf("\nRECORD NOT FOUND!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {
            printf("Discounted succesfully!!! \n\n");
        printf("\nENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}
//this function shows us a short view of customer list
void helping_hand(void)
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    system("color 2");

    while(fscanf(view,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
       {
           printf("Record No: %d\n",add.acc_no);
           printf("Name of the Customer: %s\n",add.name);
           printf("Remaining Money: %g \n",cost.remaining);
           for(int i=0;i<60;i++)
        printf("* ");

           test++;
       }
    fclose(view);
}
void revenue(void)
{
    FILE*fp=fopen("record.txt","r");
    int test=0;
    system("cls");
    system("color 2");
    float total_sell=0;
    float total_due=0;
    while(fscanf(fp,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
       {

           total_sell+=cost.buy;
           total_due+=cost.remaining;

           test++;
       }
       printf("***TOTAL REVENUE:\n");
    printf("Your total sell: TK.%g\n",total_sell);
    printf("Your total due: TK.%g\n",total_due);
    printf("\n");
    yearwise_revenue();
    fclose(fp);
    view_list_invalid:
     printf("\n\nENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
//this functions ocassionally discounts customer remaining due
void discount(void)
{
    float x,y;
    printf("Enter the discount percentage you want to give: ");
    scanf("%f",&x);
    FILE*fp=fopen("record.txt","r");
    FILE*fp1=fopen("new.txt","w");
    int test=0;

    while(fscanf(fp,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
    {
        y=(x/100)*cost.remaining;
        cost.remaining=cost.remaining-y;
    fprintf(fp1,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",add.acc_no,add.name,address.district,address.thana,address.house_no,add.phone,cost.buy,cost.paid,cost.remaining,add.buy.month,add.buy.day,add.buy.year);

    }
   fclose(fp);
   fclose(fp1);
   remove("record.txt");
   rename("new.txt","record.txt");
    fclose(fp);
    view_list_invalid:
     printf("\n\nENTER 1 FOR MAIN MENU & 0 TO EXIT\n");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
//this function shows reveneu monthly & in total
char name_of_months[12][15]={"January","February","March","April","May","June","July","August","September","October","November","December"};
void yearwise_revenue(void)
{
    FILE*fp=fopen("record.txt","r");
    struct revenue r[12];
    printf("***MONTHWISE REVENUE: \n");
    for(int i=0;i<12;i++)
    {
        r[i].month=i+1;
        r[i].total_sell=0;
    }
    while(fscanf(fp,"%d %s %s %s %s %d %f %f %f %d/%d/%d\n",&add.acc_no,add.name,address.district,address.thana,address.house_no,&add.phone,&cost.buy,&cost.paid,&cost.remaining,&add.buy.month,&add.buy.day,&add.buy.year)!=EOF)
    {
        r[add.buy.month-1].total_sell+=cost.buy;

    }
    for(int i=0;i<12;i++)
    {
        printf("%s ->",name_of_months[i]);
        printf("Tk.%g",r[i].total_sell);
        printf("\n");
    }
    printf("\n\nGRAPH OF STAR\n");
    float graph_array[12];
    for(int i=0;i<12;i++)
        graph_array[i]=r[i].total_sell;

    float max=graph_array[0];
    for(int i=0;i<12;i++)
    {
        if(max<graph_array[i])
            max=graph_array[i];
    }
    for(int i=0;i<12;i++)
    {
        graph_array[i]=(graph_array[i]/max)*10;
    }
    for(int i=0;i<12;i++)
    {
        printf("%s ->     ",name_of_months[i]);
        for(int j=0;j<graph_array[i];j++)
            printf("*");
        printf("\n");
    }


}


