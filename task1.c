#include <stdio.h>

// В файле .txt даны два слова не более 100 символов каждое, разделенные
// одним пробелом. Найдите только те символы слов, которые встречаются в
// обоих словах только один раз. Напечатайте их через пробел в файл .txt в
// лексикографическом порядке.

#define MAX_WORD_NUMBER     10
#define MAX_WORD_LENGTH     100

void readFile(char *wrd[])
{
    FILE *file;
    char *fileName = "in.txt";
    char *word;
    int i = 0;
    file = fopen(fileName, "r");
    while (fscanf(file, "%s", word))
    {
        wrd[i++] = word;
    }
    fclose(file);

}

void printWords(char *wrd[])
{
    int i = 0;
    while (wrd[i])
    {
        printf("%s\n", wrd[i++]);
    }
}


int main(int argc, char const *argv[])
{
    char *words[MAX_WORD_NUMBER];
    readFile(words);
    printWords(words);

    return 0;
}
