#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// В файле .txt дано предложение. Необходимо определить, сколько слов
// заканчиваются на букву 'а'. Ответ записать в файл .txt.

#define STRING_BUFER        1000
#define MAX_WORD_NUMBER     20
#define MAX_WORD_LENGTH     50
const char *inputFileName = "in.txt";
const char *outputFileName = "out.txt";

int readFile(int *number, char *wrd)
{
    FILE *file;
    char c;
    int i = 0, wordCounter = 0;

    if ((file = fopen(inputFileName, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }

    while ((c = fgetc(file)) != EOF)
    {
        if (c == ' ')
        {
            *(wrd + wordCounter * MAX_WORD_LENGTH + i) = '\0';
            wordCounter++;
            i = 0;
        }
        else
        {
            *(wrd + wordCounter * MAX_WORD_LENGTH + i) = c;
            i++;
        }
    }
    *(wrd + wordCounter * MAX_WORD_LENGTH + i) = '\0';
    fclose(file);
    *number = wordCounter + 1;
    return 0;
}

int getWordNumber(int num, char *wrd)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        if (*(wrd + i * MAX_WORD_LENGTH + strlen(wrd + i * MAX_WORD_LENGTH) - 1) == 'a')
        {
            count++;
        }
    }
    return count;
}

void writeFile(int number)
{
    FILE *file = fopen(outputFileName, "w");
    fprintf(file, "%d", number);
    fclose(file);
}

void printWords(int quantity, char *wrd)
{
    printf("\n");
    for (size_t i = 0; i < quantity; i++)
    {
        printf("wrd[%d]: '%s'\n", i, wrd + i * MAX_WORD_LENGTH);
    }
}

int main(int argc, char const *argv[])
{
    char *words = (char*) malloc(MAX_WORD_LENGTH * MAX_WORD_NUMBER * sizeof(char));
    int wordsNumber;
    if (readFile(&wordsNumber, words))
    {
        return 1;
    }
    // printWords(wordsNumber, words);

    int number = getWordNumber(wordsNumber, words);
    // printf("%d", number);
    writeFile(number);

    return 0;
}