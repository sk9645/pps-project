#include <stdio.h>

void insert_record();
void search_record();
void update_record();


struct student
{
    int roll;
    char sec[10];
    char name[40];
    int marks;
};
struct student s;
void main()
{
     int ch;
     while(ch!=4)
     {
      printf("\t********************************************\n");
      printf("\tWELCOME TO SRM STUDENT MANAGEMENT PROGRAM\n");
      printf("\t********************************************\n\n\n");

             printf("\t\t****Available Options****\n\n\n");
             printf("\t\t1: Insert Student record\n");
             printf("\t\t2: Search Student record\n");
             printf("\t\t3: Update Student record\n");
             printf("\t\t4: Exit\n\n");
             printf("\t\tEnter Your Choice : ");
             scanf("%d",&ch);
             switch(ch)
             {
                case 1:system("cls");
                       insert_record();
                        break;
                case 2:system("cls");
                       search_record();
                       break;
                case 3:system("cls");
                       update_record();
                       break;
                case 4:exit(1);
                       break;
                default:printf("\n\t\t You Entered The Wrong Choice");
             }
             getchar();
     }
}
void insert_record()
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
        printf("\n\n\tStudent Recorded Sucessfully !!!\n");
    }
    fclose(fp);
    printf("\n\t\tRecord Updated !!!\n\n");
}
void search_record()
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
             printf("\n\n\tSearch Sucessfull And Student Records Is as follows");
             printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\n");
             printf("%d\t\t\t%s  \t\t  %s \t\t%d\n\n\n",s.roll,s.name,s.sec,s.marks);
        }
    }
        if(flag==0)
        {
            printf("\n\n\t\tNo Record Found\n\n");
        }
fclose(fp);
}
void update_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","r+");
    if(fp==NULL)
    {
        printf("\n\t\tError : File Does Not Exist");
        return;
    }
    printf("\n\n\tEnter Roll Number Of Students Whose Record You Want To Update :");
    scanf("%d",&ro);
    printf("\n\n\t\t *** Previously Stored Record Of Given Roll No. ***\n\n");
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
            flag=1;
            printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\n");
             printf("%d\t\t\t%s  \t\t %s \t\t%d\n",s.roll,s.name,s.sec,s.marks);
            printf("\n\n\n\t\t*** Now Enter The New Record Of The Student ***\n\n");
            printf("\n\t\tUpdated Student Roll No.: ");
            scanf("%d",&s.roll);
            fflush(stdin);
            printf("\n\t\tUpdated Student Name: ");
            gets(s.name);
            printf("\n\t\tUpdated Student Section: ");
            gets(s.sec);
            printf("\n\t\tUpdated Student Marks: ");
            scanf("%d",&s.marks);
            fseek(fp,-(long)sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            printf("\n\n\t\tRecord Updated\n\n\n");
        }
    }
    if(flag==0)
    {
        printf("\n\t\tError : Something Went Wrong !!!\n\n");
    }
fclose(fp);
}
