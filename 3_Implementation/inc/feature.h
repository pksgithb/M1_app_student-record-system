/**
 * @file feature.h
 * @author Pavan Kalyan Reddy
 * @brief 
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief declared function for starting application
 * 
 */


struct student{
    char ID[15];
    char name[20];
    char add[20];
    char parname[20];
    int Class;
    long unsigned int phone_no;
};

struct student stu;


void SetColor();
void ClearConsoleToColors();
void main_window();
void delete_student();
void mod_student();
void search_student();
void add_student();
void print_heading();
  
  
  
 #endif
  
  
 
  /**
 * @brief declared function for ending application
 * 
 */
