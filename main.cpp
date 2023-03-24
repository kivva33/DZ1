#include "sorts.h"

int main() {
    FILE* fLog;//файл для записи времени
    float sum;//время выполнения сортировки
    int count = N;//счетчик сортировок
    fLog = fopen("sort", "w");
    void(*sort[])(int*, int) = {count_sort, quick_demo, shell_sort,
                                select_sort, sort_choice,bubble_sort};
    int c = 1000000;//приращение количества элементов сортировки
    int* flag = new int[N];//если вышли за пределы времени, меняем на 1
    for (int i = 0; i < N; i++) {
        flag[i] = 0;
    }
    fprintf(fLog, "%s\t\t%s\t%s\t%s\t%s\t%s\t%s\n", "size", "countSort", "quickSort", "shellsort",
            "selectsort", "sortchoice", "bubblesort");
    for (int size = 1000; size < 10e+7 && count; size += size / 3) {
        fprintf(fLog, "%d\t",size);
        if(size < 10e+6){
            size *= 3 / 2;
            fprintf(fLog, "\t");
        }
        for (int j = 0; j < N; j++) {
            if (!flag[j]) {
                int edit = flag[j];//флаг может измениться на выходе test_sort
                sum = test_sort(sort[j], size, flag[j]);
                if(edit != flag[j]){
                    count--;
                }
                fprintf(fLog, "%f\t", sum);
                continue;
            }
            fprintf(fLog, "\t");
        }
        fprintf(fLog,"\n");
    }
    fclose(fLog);
    return 0;
}
