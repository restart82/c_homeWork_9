#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// В файле .txt даны два слова не более 100 символов каждое, разделенные
// одним пробелом. Найдите только те символы слов, которые встречаются в
// обоих словах только один раз. Напечатайте их через пробел в файл .txt в
// лексикографическом порядке.

#define MAX_WORD_NUMBER     5
#define MAX_WORD_LENGTH     100
const char *fileName = "in.txt";

int readFile(int *number, char *wrd)
{
    FILE *file;
    char c;
    int i = 0, wordCounter = 0;

    if ((file = fopen(fileName, "r")) == NULL)
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
        else if (c >= 'a' && c <= 'z')
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

void task(int wordNum, char *wrd, char arr[])
{
    bool flag;
    int counter = 0;
    int secondLevelCounter = 0;
    int charNumber = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        flag = true;
        for (int i = 0; i < wordNum; i++)
        {
            if (!flag)
            {
                break;
            }
            for (int j = 0; j < strlen(wrd + i * MAX_WORD_LENGTH); j++)
            {
                if (c == *(wrd + i * MAX_WORD_LENGTH + j))
                {
                    counter++;
                }
            }
            if (counter != 1)
            {
                flag = false;
            }
            else
            {
                // printf("word %d char '%c' : %d time\n", i, c, counter);
                secondLevelCounter++;
            }
            counter = 0;
        }
        if (secondLevelCounter == wordNum)
        {
            arr[charNumber++] = c;
        }
        secondLevelCounter = 0;
    }
}

void printWords(int quantity, char *wrd)
{
    for (size_t i = 0; i < quantity; i++)
    {
        printf("wrd[%d]: '%s'\n", i, wrd + i * MAX_WORD_LENGTH);
    }
}

void printChar(char arr[])
{
    printf("%c", arr[0]);
    for (int i = 1; i < strlen(arr); i++)
    {
        printf(" %c", arr[i]);
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
    // printWords(MAX_WORD_NUMBER, words);
    char result[15];
    task(wordsNumber, words, result);
    printChar(result);

    return 0;
}
