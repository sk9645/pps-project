#include <stdio.h>

void insert();
void search();
void update();


struct student
{
    int roll;
    char sec[5];
    char name[20];
    int marks;
};
struct student s;
void main()
{
     int choice;
     while(choice!=4)
     {
      printf("\t\t***********************************\n");
      printf("\t\t'WELCOME TO SRM STUDENT DATABASE'\n");
      printf("\t\t***********************************\n\n\n");

             printf("\t\t****Available Options****\n\n");
             printf("\t\t1: Insert Student record\n");
             printf("\t\t2: Search Student record\n");
             printf("\t\t3: Update Student record\n");
             printf("\t\t4: Exit\n\n");
             printf("\t\tEnter Your Choice : ");
             scanf("%d",&choice);
             switch(choice)
             {
                case 1:system("cls");
                       insert();
                        break;
                case 2:system("cls");
                       search();
                       break;
                case 3:system("cls");
                       update();
                       break;
                case 4:exit(1);

                default:printf("\n\t\t!!! You Entered The Wrong Choice !!!\n\n");
             }

             getchar();
     }
}
void insert()
{
    FILE *fp;
    fp=fopen("stu.txt","a+");

    printf("\n\n\t\t^^^^ENTER NEW STUDENT DATA^^^^");
    printf("\n\n\t\tEnter Student Roll Number : ");
    scanf("%d",&s.roll);
    fflush(stdin);
    printf("\n\t\tEnter Student Name : ");
    gets(s.name);
    printf("\n\t\tEnter Student Section : ");
    gets(s.sec);
    printf("\n\t\tEnter Student Total Marks : ");
    scanf("%d",&s.marks);
    fwrite(&s,sizeof(s),1,fp);
    {
        printf("\n\n\tStudent Database Recorded Sucessfully !!!\n");
    }
    fclose(fp);
    printf("\n\t\tData Updated !!!\n\n");
}
void search()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","r");
    if(fp==NULL)
    {
        printf("\n\t\tError : File Does Not Exist !!! ");
        return;
    }
    printf("\n\n\tEnter Student Roll No. Which You Want To Search : ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0&&flag==0)
    {
        if(s.roll==ro)
        {
            flag=1;
             printf("\n\n\tSearch Sucessfull And Student Data Is as follows");
             printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\n");
             printf("%d\t\t\t%s  \t\t  %s \t\t%d\n\n\n",s.roll,s.name,s.sec,s.marks);
        }
    }
        if(flag==0)
        {
            printf("\n\n\t\t!!! No Data Found !!!\n\n");
        }
fclose(fp);
}
void update()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","r+");

    printf("\n\n\tEnter Roll Number Of Student Whose Data You Want To Update :");
    scanf("%d",&ro);
    printf("\n\n\t\t*** Previously Stored DataOf Given Roll No. ***\n");
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
            flag=1;
            printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\n");
             printf("%d\t\t\t%s  \t\t %s \t\t%d\n",s.roll,s.name,s.sec,s.marks);
            printf("\n\n\n\t\t*** Now Enter The New Data Of The Student ***\n\n");
            printf("\n\t\tUpdated Student Roll No.: ");
            scanf("%d",&s.roll);
            fflush(stdin);
            printf("\n\t\tUpdate Student Name: ");
            gets(s.name);
            printf("\n\t\tUpdate Student Section: ");
            gets(s.sec);
            printf("\n\t\tUpdate Student Marks: ");
            scanf("%d",&s.marks);
            fseek(fp,-(long)sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            printf("\n\n\t\tRecord Updated\n\n\n");
        }
    }
    if(flag==0)
    {
        printf("\n\t\tError :No Data Found !!!\n\n");
    }
fclose(fp);
}
