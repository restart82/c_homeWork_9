#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// В файле .txt строка из маленьких и больших английских букв, знаков
// препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
// все пробелы. Результат записать в файл .txt.

#define STRING_BUFER        1000
const char *inputFileName = "in.txt";
const char *outputFileName = "out.txt";

int readFile(char str[])
{
    FILE *file;
    char c;
    int i = 0;

    if ((file = fopen(inputFileName, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    while ((c = fgetc(file)) != EOF)
    {
        str[i++] = c;
    }
    str[i] = '\0';
    fclose(file);
    return 0;
}

void writeFile(char str[])
{
    FILE *file = fopen(outputFileName, "w");
    fprintf(file, "%s", str);
    fclose(file);
}

void deleteRepeats(char str[])
{
    int size = strlen(str);
    int k = 0;
    bool flag;

    for (int i = 0; i < size; i++)
    {
        flag = false;
        for (int j = i + 1; j < size; j++)
        {
            if (str[i] == str[j])
            {
                flag = true;
                break;
            }
        }
        if (str[i] == ' ')
        {
            flag = true;
        }
        if (!flag)
        {
            str[k++] = str[i];
        }
    }
    str[k] = '\0';
}

int main(int argc, char const *argv[])
{
    char string[STRING_BUFER];
    if (readFile(string))
    {
        return 1;
    }
    printf("%s\n", string);
    deleteRepeats(string);
    printf("%s\n", string);
    writeFile(string);
    return 0;
}
