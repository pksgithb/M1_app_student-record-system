#include "unity.h"
#include <student_record.h>

/* Modify these two lines according to the project */
#include <student_record.h>
#define PROJECT_NAME    "Record"

/* These two lines are need to be set according to project name */
#include "../inc/student_record.h"

#define PROJECT_NAME    "Student_Record_System"

/* Prototype / Function Declaration */
// Write all the function defined in the program.

/* Prototypes for all the test functions */
void test_add_student(void);
void test_search_student(void);
void test_modify_student(void);
void test_delete_student(void);
void test_exit(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add_student);
  RUN_TEST(test_search_student);
  RUN_TEST(test_modify_student);
  RUN_TEST(test_delete_student);
  RUN_TEST(test_exit);
  
/* Close the Unity Test Framework */
  return UNITY_END();
}
