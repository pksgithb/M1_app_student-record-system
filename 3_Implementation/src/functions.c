/**
 * @file functions.c
 * @author Pavan Kalyan Reddy
 * @brief Functions
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//Main function

int main(){
    ClearConsoleToColors(17,15);
    SetConsoleTitle("Programming-technique.blogspot.com - Student Record System");
    window();
    //use_pass_field();
    main_window();
    return 0;
  
//Window function
  
void main_window(){
    int choice;
    SetColor(8);
    int x = 2;
    while(1){
        gotoxy(x,8);printf("1. Add Student");
        gotoxy(x,10);printf("2. Search Student");
        gotoxy(x,12);printf("3. Modify Student Record");
        gotoxy(x,14);printf("4. Generate Marksheet");
        gotoxy(x,16);printf("5. Delete Student Record");
        //gotoxy(x,18);printf("6. Change password");
        gotoxy(x,18);printf("6. Exit");
        gotoxy(x,20);printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
                break;
            case 5:
                delete_student();
                break;
            case 6:
                exit(0);
                break;
            default:
                break;
        }

    }

}
  
  
//Delete Student

void delete_student(){
    clearWindow();
    print_heading("Delete Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(37,12);printf("The record is sucessfully deleted");
    SetColor(28);
    return;
}
  
//Modify Student

void mod_student(){
    clearWindow();
    print_heading("Modify Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(stu.ID);
            gotoxy(print,13);printf("Name: ");gets(stu.name);
            gotoxy(print,14);printf("Address: ");gets(stu.add);
            gotoxy(print,15);printf("Parent's name: ");gets(stu.parname);
            gotoxy(print,16);printf("Class: ");scanf("%d",&stu.Class);
            gotoxy(print,17);printf("Phone Number: ");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);printf("No Record Found");
    }
    fclose(fp);
    SetColor(28);
    return;
}
  
//Search Student
  
void search_student(){
    clearWindow();
    print_heading("Search Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("The record is Found");
        gotoxy(37,14);printf("ID: %s",stu.ID);
        gotoxy(37,15);printf("Name: %s",stu.name);
        gotoxy(37,16);printf("Address: %s",stu.add);
        gotoxy(37,17);printf("Parent's Name: %s",stu.parname);
        gotoxy(37,18);printf("Class: %d",stu.Class);
        gotoxy(37,19);printf("Phone No: %ld",stu.phone_no);
    }else{
        gotoxy(37,12);printf("Sory, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    return;
}
  
//Add Student
  
void add_student(){
    clearWindow();
    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        gotoxy(print,10);printf("ID: ");gets(stu.ID);
        //here you can confirms the ID
        gotoxy(print,12);printf("Name: ");gets(stu.name);
        gotoxy(print,14);printf("Address: ");gets(stu.add);
        gotoxy(print,16);printf("Parent's name: ");gets(stu.parname);
        gotoxy(print,18);printf("Class: ");scanf("%d",&stu.Class);
        gotoxy(print,20);printf("Phone Number: ");scanf("%ld",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,22); printf("The record is sucessfully added");
    }
    SetColor(28);
    fclose(fp);
    return;
}

/**
 * @brief end of function declaration
 * 
 */
