/* читаем из файла требуемое кол. строк ROWS или до конца файла EOF
 * (что наступит раньше), формируем строку по конечному символу '\n'
 * в файле, затем добавляем завершающий '\0' и полученную строку СИ 
 * записываем
 * в двумерный массив по 1-й строке в каждый элемент массива.
 * Затем массив выводим на консоль. Есть подсчет считанных строк.
 * См также ниже мой коммент
*/

/* file_in находится в каталоге программы и имеет вид:
I am a human 1
I am a 2 human`s 2
I am a 3 human 3
Nmjh## ___ 987 ht!
5555555555555555
66666666666666
77777777777777
8888888888888888
*/

#include <stdio.h>
#include <stdlib.h> /* prototype exit() */
#include <string.h>
#define ROWS 7
#define COLS 20
void file_open(void);
FILE * file_in;
char ch, arr_str[ROWS][COLS];
int j, i, count = 0;

int main(int agrc, char * argv[]){
  file_open();
  for(j = 0; j < ROWS; ++j){
    for(i = 0; (ch=getc(file_in)) != '\n' && (ch != EOF); ++i) {
      arr_str[j][i] = ch; // заполнение строки
    } //конец внутреннего for
    if(ch == EOF){
      puts("достигнут конец файла, выход.");
      fprintf(stdout, "count is: %i \n", count);
      break;
    } // конец if
    else{
      arr_str[j][i] = '\0'; 
      ++count;
    } // конец else
    
  } // конец внешнего for
  fclose(file_in);
/* вывод массива на консоль */
  fprintf(stdout, "Из файла считано %i строк, которые имеют вид:\n", count);
  puts(""); // пропуск строки
  for(j = 0; j < count; ++j){
    fprintf(stdout, "%s\n", arr_str[j]);
  }
  puts(""); // пропуск строки
  puts("Программа завершена.");
  exit(EXIT_SUCCESS);
}

void file_open(void){
  if( (file_in = fopen("example.txt", "r")) == NULL){
    fprintf(stdout, "%s\n", "не могу отрыть файл для чтения");
    exit(EXIT_FAILURE);
  }
}

/*
Вывод на консоль:
Из файла считано 7 строк, которые имеют вид:

I am a human 1
I am a 2 human`s 2
I am a 3 human 3
Nmjh## ___ 987 ht!
5555555555555555
66666666666666
77777777777777

Программа завершена.
*/