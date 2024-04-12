#include <stdio.h>
#include <string.h>

// В файле .txt дана символьная строка не более 1000 символов. Необходимо
// заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// строчные. Результат записать в .txt

#define STRING_BUFER    1000
const char *inputFileName = "in.txt";
const char *outputFileName = "out.txt";

int swipAB()
{
    FILE *file;
    char string[STRING_BUFER];
    char c;
    int i = 0;

    if ((file = fopen(inputFileName, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    while ((c = fgetc(file)) != EOF)
    {
        string[i++] = c;
    }
    string[i] = '\0';
    fclose(file);
    printf("%s\n", string);

    file = fopen(outputFileName, "w");

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == 'a')
        {
            string[i] = 'b';
        }
        else if (string[i] == 'b')
        {
            string[i] = 'a';
        }
        else if (string[i] == 'A')
        {
            string[i] = 'B';
        }
        else if (string[i] == 'B')
        {
            string[i] = 'A';
        }
    }

    fprintf(file, "%s", string);
    printf("%s\n", string);
    fclose(file);

    return 0;
}

int main(int argc, char const *argv[])
{
    if (swipAB())
    {
        return 1;
    }
    return 0;
}
