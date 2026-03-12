#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
};

void addstudent();
void studentrecord();
void searchstudent();
void deletestudent();

int main(){

    int choice = 0;

    while(choice!=5){

        printf("\n====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student Records\n");
        printf("2. Student Records\n");
        printf("3. Search Records\n");
        printf("4. Delete Records\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
                case 1:
                    addstudent();
                    break;
                case 2:
                    studentrecord();
                    break;
                case 3:
                    searchstudent();
                    break;
                case 4:
                    deletestudent();
                    break;
                case 5:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Enter a valid choice\n");
                }
    }
}

void addstudent(){

    FILE *fp;
    struct student info;
    char another;

    fp = fopen("student_info.dat","ab");

    do{

        printf("\nEnter First Name: ");
        scanf("%s",info.first_name);
        printf("Enter Last Name: ");
        scanf("%s",info.last_name);
        printf("Enter Roll Number: ");
        scanf("%d",&info.roll_no);
        printf("Enter Class: ");
        scanf("%s",info.Class);
        printf("Enter Address: ");
        scanf("%s",info.vill);
        printf("Enter Percentage: ");
        scanf("%f",&info.per);

        fwrite(&info,sizeof(struct student),1,fp);

        printf("Add another record (y/n): ");
        scanf(" %c",&another);

    }while(another=='y'||another=='Y');

    fclose(fp);
}

void studentrecord(){

    FILE *fp;
    struct student info;

    fp = fopen("student_info.dat","rb");

    if(fp==NULL){
        printf("File not found\n");
        return;
    }

    printf("\n==== STUDENT RECORDS ====\n");

    while(fread(&info,sizeof(struct student),1,fp)){

        printf("\nName : %s %s",info.first_name,info.last_name);
        printf("\nRoll : %d",info.roll_no);
        printf("\nClass : %s",info.Class);
        printf("\nAddress : %s",info.vill);
        printf("\nPercentage : %.2f\n",info.per);
        printf("------------------------\n");
    }
    fclose(fp);
}

void searchstudent(){

    FILE *fp;
    struct student info;
    int roll_no, found=0;

    fp = fopen("student_info.dat","rb");

    printf("Enter roll number to search: ");
    scanf("%d",&roll_no);

    while(fread(&info,sizeof(struct student),1,fp)){

        if(info.roll_no==roll_no){
            printf("\nStudent Found\n");
            printf("Name : %s %s\n",info.first_name,info.last_name);
            printf("Class : %s\n",info.Class);
            printf("Address : %s\n",info.vill);
            printf("Percentage : %.2f\n",info.per);

            found=1;
        }
    }

    if(!found){
        printf("Record not found\n");
    }

    fclose(fp);
}

void deletestudent(){

    FILE *fp,*fp1;
    struct student info;
    int roll_no,found=0;

    fp=fopen("student_info.dat","rb");
    fp1=fopen("temp.dat","wb");

    printf("Enter roll number to delete: ");
    scanf("%d",&roll_no);

    while(fread(&info,sizeof(struct student),1,fp)){
        if(info.roll_no==roll_no){
            found=1;
        }
        else{
            fwrite(&info,sizeof(struct student),1,fp1);
        }
    }

    fclose(fp);
    fclose(fp1);
  
    remove("student_info.dat");
    rename("temp.dat","student_info.dat");

    if(found)
        printf("Record deleted successfully\n");
    else
        printf("Record not found\n");

}
