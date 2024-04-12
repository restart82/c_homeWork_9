#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
// числа и иные символы. Требуется все числа, которые встречаются в строке,
// поместить в отдельный целочисленный массив. Например, если дана строка
// "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
// массив по возрастанию в файл .txt.

#define STRING_BUFER        1000
#define MAX_WORD_NUMBER     20
#define MAX_WORD_LENGTH     20
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

void getNumberArray(int wdrNumber, char *wrd, int *size, int nmb[])
{
    int counter = 0, number, order;
    char c;
    bool flag;

    for (int i = 0; i < wdrNumber; i++)
    {
        order = 1;
        number = 0;
        flag = false;
        for (int j = 0; j < strlen(wrd + i * MAX_WORD_LENGTH); j++)
        {
            c = *(wrd + i * MAX_WORD_LENGTH + j);
            if (c >= '0' && c <= '9')
            {
                number *= order;
                order *= 10;
                number += (c - '0');
                flag = true;
            }
        }
        if (flag)
        {
            nmb[counter] = number;
            counter++;
        }
    }
    *size = counter;
}

void sortArray(int size, int a[])
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 2; j >= i; j--)
        {
            if (a[j] > a[j + 1])
            {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }  
    }
}

void writeFile(int size, int arr[])
{
    FILE *file = fopen(outputFileName, "w");

    fprintf(file, "%d", arr[0]);
    for (int i = 1; i < size; i++)
    {
        fprintf(file, " %d", arr[i]);
    }

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

void printArray(int size, int arr[])
{
    printf("\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    int numbers[MAX_WORD_NUMBER];
    int size;
    getNumberArray(wordsNumber, words, &size, numbers);
    // printArray(size, numbers);
    sortArray(size, numbers);
    // printArray(size, numbers);
    writeFile(size, numbers);

    return 0;
}
