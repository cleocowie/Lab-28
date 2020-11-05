/** lab28.h
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Programming Assessment 3 Practice
* Documentation: DOC STATEMENT
* ===========================================================  */

#ifndef MYEXE_LAB28_H
#define MYEXE_LAB28_H

typedef struct  {
     char firstName[30];
     char lastName[30];
     char birthMonth[15];
     int  birthDate;
} EmployeeBD;

 

int numVowels(char vowels[]);
char *sortString(char array[]);
int readFile(char filename[],EmployeeBD*Employee, int count);
int IDEmpBDMonth(EmployeeBD*Employee, int count,int month);
EmployeeBD readEmployeeArchive(int index);

#endif //MYEXE_LAB28_H
