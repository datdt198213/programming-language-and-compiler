#include<stdio.h>

int main( int argc, char *argv[] )  
{
	if(argc == 1) {
		printf("Loi tham so truyen vao");
	}
   else if( argc == 2)
   {
      printf("Hello: %s\n", argv[1]);
   }
   else if(argc == 3) {
   
   char target[100] = "";
   sprintf(target, "%s.txt", argv[2]);

   FILE * fp = NULL;   
   fp = fopen(target, "a");
   fprintf(fp,"%s \n" , argv[1]);
   fclose(fp);

   FILE * fp2 = NULL;
   fp2 = fopen(target, "r");
   char c;
   while ((c = fgetc(fp2)) != EOF)
   {
      printf("%c", c);
   }

   fclose(fp2);
   }
   else
   {
      printf("Truyen qua nhieu tham so\n");
   }
}