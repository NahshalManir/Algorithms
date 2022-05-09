#include<stdio.h>
int main()
{
    FILE *fp;
    char str[50];

    fp = fopen("Sample.txt", "w");    //open for writing

    // fputs takes two parameters(char *str, FILE *stream)
    scanf("%[^\n]",str);
    fputs(str,fp);
    fclose(fp);     // Close file after operations are done

    return 0;
}


#include <stdio.h>
int main()
{
   FILE *fp;
   char str[50];
   fp = fopen("Sample.txt", "w");  //open for writing

   scanf("%[^\n]",str); // Input data to be written

   //fprintf takes parameters(FILE *pointer, char *str)
   fprintf(fp,str);     //writing data into file
   fclose(fp);          //closing file
}

#include<stdio.h>
int main()
{
    FILE *fp;
    fp=fopen("Sample.txt","w");   // Opening file

    char str[50];
    scanf("%[^\n]",str);

    // fputc takes parameters (int char, FILE *pointer)
    for (int i = 0; str[i]!='\0'; i++)
        // Input string into the file single character at a time
        fputc(str[i], fp);

    fclose(fp);  // Closing file
    return 0;
}

#include <stdio.h>
#include <string.h>
 int main()
 {
     FILE *fp;
     fp = fopen("Sample.txt", "w");

     char str[50];
     scanf("%[^\n]",str);

     /* fwrite takes parameters(char *str,size in bytes
        of each item, no. of items, *FILE pointer)*/

     fwrite(str, 1, strlen(str), fp);
     fclose(fp);

     return 0;
 }












