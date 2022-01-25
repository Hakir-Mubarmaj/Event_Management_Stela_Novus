#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void design();
struct login;
int login();
void newID();
void forgot();
void event();
struct event;
int info();
int billing();
void ClearScreen();
double payment;

void design()
{
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~STELA NOVUS EVENT PLANERS~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\t\t\t~~~~~~~~~~~~~~All Right Reserved By Tanvir, Tethi & Ani~~~~~~~~~~~~\n");
    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main()
{
    design();
    int choice;
    printf("\n\t\t\t\t\t\tWarm Welcome !!!!!\n\n\t\t\tHow Can We Help You???\n\t\t\tMake Your Choice.........\n");
    printf("\t\t\t1. Create New Customer ID.\n\t\t\t2. Login To Existing ID.\n\t\t\tYour Choice :");
    scanf("%d",&choice);
    if(choice==1)
    {
        ClearScreen();
        newID();
    }
    else if(choice==2)
    {
        ClearScreen();
        login();
    }
    return 0;
}

struct login
{
    char fullname[100];
    char mobile[20];
    char username[20];
    char password[20];
};

int login()
{
    int cHoice;
    design();
    char username[20], password[20];
    FILE *log;
    log=fopen("login.txt","r");
    struct login l;
    printf("\n\t\t\tEnter Username      :");
    scanf("%s",&username);
    printf("\t\t\tEnter Password      :");
    scanf("%s",&password);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0&&strcmp(password,l.password)==0)
        {
            int cois;
            printf("\n");
            printf("\t\t\tLogin Succesful!!!!!!\n\t\t\t1. Previous Order\n\t\t\t2. New Event\n\t\t\tYour Choice  :");
            scanf("%d",&cois);
            if(cois==1)
            {
                printf("\n");
                printf("\t\t\tStrike Any Key for Next Page... ");
                getch();
                ClearScreen();
                info();
            }
            else if(cois==2)
            {
                printf("\n");
                printf("\t\t\tStrike Any Key for Next Page... ");
                getch();
                ClearScreen();
                event();
            }
        }
        else
        {
            printf("\n");
            printf("\t\t\tYou Are Not Register Yet Or Your Information is wrong !!!!!!!!!!!\n");
            printf("\n\t\t\tYour Further Option\n\t\t\t1.Login\n\t\t\t2.Forget Password\n\t\t\t3.Registration.\n\t\t\tYour Choice   :");
            scanf("%d",&cHoice);
            if(cHoice==1)
            {
                printf("\n");
                printf("\t\t\tStrike Any Key for Next Page... ");
                getch();
                ClearScreen();
                login();
            }
            else if(cHoice==2)
            {
                printf("\n");
                printf("\t\t\tStrike Any Key for Next Page... ");
                getch();
                ClearScreen();
                forgot();
            }
            else if(cHoice==3)
            {
                printf("\n\t\t\tStike Any Key For Next Page... ");
                getch();
                ClearScreen();
                newID();
            }
        }
    }
    fclose(log);

}

void newID()
{
    design();
    FILE *log;
    log=fopen("login.txt","w");
    struct login l;
    fflush(stdin);
    printf("\n\n\t\t\tEnter Full Name     :");
    scanf("%[^\n]",l.fullname);
    printf("\t\t\tEnter Mobile Number :");
    scanf("%s",l.mobile);
    printf("\t\t\tEnter Username      :");
    scanf("%s",l.username);
    printf("\t\t\tEnter New Password  :");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    printf("\n");
    printf("\t\t\tNOW you can login by using username and password!!!!!!\n\t\t\tStrike Any Key for Next Page...");
    getch();
    ClearScreen();
    login();
}

void forgot()
{
    design();
    int cHoice;
    char mobile[20];
    FILE *log;
    log=fopen("login.txt","r");
    struct login l;
    printf("\n\t\t\tEnter Mobile Number:");
    scanf("%s",&mobile);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(mobile,l.mobile)==0)
        {
            printf("\n");
            printf("\t\t\tLogin Succesful!!!!!!");
            printf("\n\n\t\t\tStrike any key to reset your login information........");
            getch();
            ClearScreen();
            newID();
        }
        else
        {
            printf("\t\t\tWrong Number\n\t\t\tYour Further Option\n\t\t\t1.Login\n\t\t\t2.Forget Password\n\t\t\tYour Choice   :");
            scanf("%d",&cHoice);
            if(cHoice==1)
            {
                printf("\n");
                printf("\t\t\tStrike Any Key for Next Page... ");
                getch();
                ClearScreen();
                login();
            }
            else if(cHoice==2)
            {
                printf("\n");
                printf("\t\t\tStrike Any Key for Next Page... ");
                getch();
                ClearScreen();
                forgot();
            }
        }
    }
    fclose(log);
}

struct event
{
    char Event[20];
    char decoration[20];
    char destination[20];
    char statter[20];
    char maincourse[20];
    char desert[20];
    double Bill;
};

void event()
{
    double total, bill=0;
    design();
    FILE *event;
    event=fopen("Event.txt","w");
    struct event e;
    printf("\n\t\t\tWhat type of Event You Want To Organize?\n\t\t\tBirthday!!!\n\t\t\tWedding!!!\n\t\t\tReception");
    printf("\n\t\t\tMake Your Choice                   :");
    scanf("%s",e.Event);
    printf("\n\t\t\tHow Many People You Want To Invite :");
    scanf("%lf",&total);
    printf("\n\t\t\tWhat type of Decoration??\n\t\t\tPlatinum = 50000 Tk\n\t\t\tGold = 40000 Tk\n\t\t\tSilver = 30000Tk\n\t\t\tNo\n\t\t\tYour Choice :");
    scanf("%s",e.decoration);
    if(strcmp("Platinum",e.decoration)==0)
        bill=bill+50000;
    else if(strcmp("Gold",e.decoration)==0)
        bill=bill+40000;
    else if(strcmp("Silver",e.decoration)==0)
        bill=bill+30000;
    else
        bill=bill+0;
    printf("\n\t\t\tWhat type of Destination??\n\t\t\tPlatinum = 100000 Tk\n\t\t\tGold = 75000 Tk\n\t\t\tSilver = 50000Tk\n\t\t\tYour Choice :");
    scanf("%s",e.destination);
    if(strcmp("Platinum",e.destination)==0)
        bill=bill+100000;
    else if(strcmp("Gold",e.destination)==0)
        bill=bill+75000;
    else if(strcmp("Silver",e.destination)==0)
        bill=bill+50000;
    printf("\n\t\t\tWhat type of Statter per person??\n\t\t\tPlatinum = 500 Tk\n\t\t\tGold = 300 Tk\n\t\t\tSilver = 200 Tk\n\t\t\tYour Choice :");
    scanf("%s",e.statter);
    if(strcmp("Platinum",e.statter)==0)
        bill=bill+(total*500);
    else if(strcmp("Gold",e.statter)==0)
        bill=bill+(total*300);
    else if(strcmp("Silver",e.statter)==0)
        bill=bill+(total*200);
    printf("\n\t\t\tWhat type of Main Course per person??\n\t\t\tPlatinum = 1500 Tk\n\t\t\tGold = 1000 Tk\n\t\t\tSilver = 500 Tk\n\t\t\tYour Choice :");
    scanf("%s",e.maincourse);
    if(strcmp("Platinum",e.maincourse)==0)
        bill=bill+(total*1500);
    else if(strcmp("Gold",e.maincourse)==0)
        bill=bill+(total*1000);
    else if(strcmp("Silver",e.maincourse)==0)
        bill=bill+(total*500);
     printf("\n\t\t\tWhat type of Desert per person??\n\t\t\tPlatinum = 500 Tk\n\t\t\tGold = 300 Tk\n\t\t\tSilver = 200 Tk\n\t\t\tYour Choice :");
    scanf("%s",e.desert);
    if(strcmp("Platinum",e.desert)==0)
        bill=bill+(total*500);
    else if(strcmp("Gold",e.desert)==0)
        bill=bill+(total*300);
    else if(strcmp("Silver",e.desert)==0)
        bill=bill+(total*200);
    e.Bill=bill;
    fwrite(&e,sizeof(e),1,event);
    fprintf(event,"%lf",e.Bill);
    fclose(event);
    printf("\n\t\t\tYour Total Bill : %0.2lf TAKA",bill);
    FILE *pay;
    pay=fopen("payment.txt","w");
    payment=bill;
    fprintf(pay,"%lf",payment);
    fclose(pay);
    printf("\n\t\t\tNow Press Any Key For Your Full Info And Bill");
    getch();
    ClearScreen();
    info();
}

int info()
{
    design();
    printf("\n                                   YOUR INFORMATION");
    FILE *log;
    log=fopen("login.txt","r");
    struct login l;
    fread(&l,sizeof(l),1,log);
    printf("\n\t\t\tName             : %s",l.fullname);
    printf("\n\t\t\tMobile           : %s",l.mobile);
    fclose(log);
    FILE *event;
    event=fopen("Event.txt","r");
    struct event e;
    fread(&e,sizeof(e),1,event);
    printf("\n\t\t\tEvent Type       : %s",e.Event);
    printf("\n\t\t\tDestination Type : %s",e.destination);
    printf("\n\t\t\tDecoration Type  : %s",e.decoration);
    printf("\n\t\t\tStatter Type     : %s",e.statter);
    printf("\n\t\t\tMain Course Type : %s",e.maincourse);
    printf("\n\t\t\tDesert Type      : %s",e.desert);
    printf("\n\t\t\tTotal Bill       : %0.2lf TAKA",e.Bill);
    fclose(event);
    FILE *pay;
    pay=fopen("payment.txt","r");
    fscanf(pay,"%lf",&payment);
    if(payment==207)
    {
        printf("\n\n\t\t\tYour Bill Has Been Paid!!!!");
        printf("\n");
    }
    else
    {
        printf("\n\t\t\tStrike Any Key for Pay Bill");
        getch();
        ClearScreen();
        billing();
    }
    fclose(pay);
}

int billing()
{
    int pay, otp;
    design();
    printf("\n\t\t\tYour Pay Bill Option\n\t\t\t1. Bkash : 01317012940\n\t\t\t2. Nagad : 01317012940\n\t\t\t3. Rocket : 01317012940\n\t\t\t4. Pay Later\n\t\t\tYour Choice :");
    scanf("%d",&pay);
    if(pay==1||pay==2||pay==3)
    {
        printf("\n\t\t\tEnter OTP :");
        scanf("%d",&otp);
        if(otp==207)
        {
            FILE *pay;
            pay=fopen("payment.txt","w");
            payment=207;
            fprintf(pay,"%lf",payment);
            fclose(pay);
            printf("\t\t\tYour Bill is Paid");
            printf("\n");
        }
        else
        {
            printf("\t\t\tWrong OTP");
            printf("\n");
            getch();
            ClearScreen();
            billing();
        }
    }
    printf("\n");
    printf("\t\t\tStrike Any Key for latest info... ");
    getch();
    ClearScreen();
    info();
}

void ClearScreen()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };
  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;
  if (!FillConsoleOutputCharacter(hStdOut,(TCHAR) ' ',cellCount,homeCoords,&count))
    return;
  if (!FillConsoleOutputAttribute(hStdOut,csbi.wAttributes,cellCount,homeCoords,&count))
    return;
  SetConsoleCursorPosition( hStdOut, homeCoords );
}
