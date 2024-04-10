#include <stdio.h>
#include <stdint.h>

void openFile()
{
    FILE* f;
    f = fopen("in.txt", "w");
    fclose(f);
}

// 1. Посчиткать сумму чисел
void fileSum()
{
    FILE* f;
    int sum = 0, n;
    f = fopen("in.txt", "r");
    while (fscanf (f, "%d", &n) == 1)
        sum += n;
    fclose(f);
    printf ("%d\n", sum);
}

// 2. Посчитать количество цифр и записать его в конгец
void fileNumber()
{
    FILE* f;
    int sum = 0;
    signed char c;
    f = fopen("in.txt", "r+");
    while ( (c = fgetc(f)) != EOF )
    {
        if (c >= '0' && c <= '9')
        {
            sum += c - '0';
        }
    }
    fprintf(f, " %d", sum);
    printf("%d", sum);
    fclose(f);
}

// 3
void getFileSize()
{
    FILE* f;
    char fileName[255] = {0};
    size_t size;
    printf("Input file name: ");
    scanf("%s", fileName);
    f = fopen(fileName, "r");
    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        fclose(f);
        printf("File size of '%s' - %u bytes.\n", fileName, size);
    }
    else
    {
        printf("Can't open file '%s'", fileName);
    }
}

// 4. вывести строку в другой файл
int copyFileString()
{
    const int line_width = 256;
    char* input_fn = "in.txt";
    char* output_fn = "out.txt";
    char line[line_width];
    char c;
    FILE* fp;
    if ((fp = fopen(input_fn, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    int count = 0;
    while (((c = fgetc(fp)) != EOF) && (c != '\n'))
        line[count++] = c;
    line[count] = 0;
    fclose(fp);
    printf("%s", line);

    if ((fp = fopen(output_fn, "w")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    for (size_t i = 0; i < 3; i++)
    {
        if (i)
        {
            fprintf(fp, ", ");
        }
        fprintf(fp, "%s", line);
    }
    fprintf(fp, "\n%d", count);
    printf(" %d", count);
    
    return 0;
}


// union - типа как структура но только значения накладываются друг на друга
void union_1()
{
    union intbytes
    {
        uint32_t number;
        uint8_t butes[4];
    } d;

    d.number = 0x12345678;
    printf("Number %x\n", d.number);
    printf("in memory id %x %X %X %X", d.butes[0], d.butes[1], d.butes[2], d.butes[3]);
}

// point - распилим один байт
void point_1()
{
    struct point
    {
        uint8_t x : 5;
        uint8_t y : 3;
    };

    struct point center = {0, 5};
    center.x = 2;
    printf("x = %d, y = %d", center.x, center.y);
}

int main(int argc, char const *argv[])
{
    // openFile();
    // fileSum();
    // fileNumber();
    // getFileSize();
    // copyFileString();
    // union_1();
    point_1();




    return 0;
}
