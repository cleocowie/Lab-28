/** lab28.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Progamming Assessment 3 Practice
* Documentation: DOC STATEMENT
* ===========================================================  */

int getNumLines(char*);

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h> 
#include "lab28.h"

int main(void)
{
    char array[100] = "The quick brown fox jumped over the lazy dog";
    int vowels = numVowels(array);
    printf("Number of vowels is %d.\n",vowels);
    char*ptr = sortString(array);
    printf("New string is: %s\n",ptr);
    int count=getNumLines("Employee_Recs.txt");

    EmployeeBD* Employee = NULL;

    Employee=malloc(count*sizeof(EmployeeBD));
    printf("Values read: %d\n", readFile("Employee_Recs.txt",Employee,count));
    int month;
    printf("Provide an integer that corresponds to a month.");
    scanf("%d",&month);
    int numOfBirths;
    numOfBirths = IDEmpBDMonth(Employee,count,month);
    printf("Number of birth is month %d is %d.\n",month,numOfBirths);

    readEmployeeArchive(3);

     

    //      f.) There is a note from the previous exec that the first two members of the 
    //      record (Brian Smith & Angie Thomas) have left the unit but the 16th & 18th entries 
    //      in the archive still remain in the unit.  In your main(), update the first (0th) and the second
    //      (1st) entries already in memory with the data in the 16 and 18th entries in the data file, use 
    //      readEmployeeArchive() to read these entries from the file.  After updating the entries call 
    //      IDEmpBDMonth(____, ___, 11) to print new November results.

    Employee[0]=readEmployeeArchive(15);
    Employee[1]=readEmployeeArchive(17);

    IDEmpBDMonth(Employee,count,11);

    system("pause");
    return 0;
}

int getNumLines(char filename[])
{
    char c;
    int count = 0;
    // Open the file
    FILE* fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);
    //printf("The file %s has %d lines\n ", filename, count);

    return count;
}


int numVowels(char vowels[]) {
    int numOfVowels = 0;
    int i;
    int lengthOfArray = strlen(vowels);

    for ( i = 0; i < lengthOfArray; i++)
    {
        switch (tolower(vowels[i]))
        {
        case 'a':
            numOfVowels++;
            break;
        case 'e':
            numOfVowels++;
            break;
        case 'i':
            numOfVowels++;
            break;
        case 'o':
            numOfVowels++;
            break;
        case 'u':
            numOfVowels++;
            break;

        default:
            break;
        }
    }
    

    return numOfVowels;

}

char *sortString(char array[]) {
        char temp;
        int i;
        int j; 
        int lengthOfArray=strlen(array);
        char *newArray;
        
        
        newArray=(char*)malloc((strlen(array))*sizeof(char));

        for ( i = 0; i < lengthOfArray; i++) {

            for( j = i+1; j<lengthOfArray; j++) {
            
                 if (tolower(array[i])>tolower(array[j])) {

                    temp = tolower(array[i]);

                    array[i]=array[j];

                    array[j]=temp;

                }

            }
        newArray = strchr(array, 97);
        
    }

    return newArray;

}


int readFile(char filename[],EmployeeBD*Employee, int count) {

   FILE*in = fopen(filename,"r");

    

   int numRead = 0;
   
   while (numRead <count ) {

      fscanf(in,"%s %s %s %d",Employee[numRead].firstName, Employee[numRead].lastName,Employee[numRead].birthMonth,&Employee[numRead].birthDate);
      numRead++;
   }



   return numRead;
}


 

    int IDEmpBDMonth(EmployeeBD*Employee, int count, int month) {
      int numRead = 0;
      char string[30];
      int numOfBirths = 0;
    
        switch (month)    {
        case 1:
            strcpy(string, "January");
            break;
        case 2:
            strcpy(string, "February");
            break;
        case 3:
            strcpy(string, "March");
            break;
        case 4:
            strcpy(string, "April");
            break;
        case 5:
            strcpy(string, "May");
            break;
        case 6:
            strcpy(string, "June");
            break;
        case 7:
            strcpy(string, "July");
            break;
        case 8:
            strcpy(string, "August");
            break;
        case 9:
            strcpy(string, "September");
            break;
        case 10:
            strcpy(string, "October");
            break;
        case 11:
            strcpy(string, "November");
            break;
        case 12:
            strcpy(string, "December");
            break;
        default:
            break;
    }

    printf("Requested Birthdays are:\n");
    printf("Lastname	Firstname	Birthday\n");
    printf("*********************************************\n");

    for(int i = 0; i < count; i++) {
        if(strcmp(string, Employee[i].birthMonth) == 0) {
            numOfBirths++;
            printf("%s %s %s %d\n", Employee[i].firstName, Employee[i].lastName, Employee[i].birthMonth, Employee[i].birthDate);
        }
    }
    return numOfBirths;

}



EmployeeBD readEmployeeArchive(int index) {
    EmployeeBD record;

    FILE*in = fopen("EmployeeBDData.archive","rb");

    fseek(in,sizeof(EmployeeBD)*index,SEEK_SET);
    fread(&record,sizeof(EmployeeBD),1, in);

    fclose(in);
    return record;
}
 




    
    