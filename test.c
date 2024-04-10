#include <stdio.h>
#define SIZE 45

int main()
{
    char *text = "example.txt";
    FILE *fp = fopen(text, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", text);
        return 1;
    }

    //char word[SIZE+1];
    char *arr[26];

    int k=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s",arr[k]);
        //fgets(word, SIZE, fp);
        //arr[k]=word;
        k++;
    }
   for(int i=0; i<3; i++)
   {
       if (arr[i])
        printf("%i ->%s\n", i+1,  arr[i]);
   }
    return 0;
}