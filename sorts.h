#include <iostream>
#include <chrono>

const int N = 6;//количество сортировок
//вспомогательные функции
void swap(int& a, int& b);
int poisk_min(int* ar, int len, int n);
int poisk_max(int* ar, int len);
void fill_array(int* ar, int len);
int partition(int* ar, int first, int last);
//функции сортировок
void sort_choice(int* ar, int len);
void quick_sort(int* ar, int last, int first);
void quick_demo(int* ar, int len);
void select_sort(int* ar, int len);
void bubble_sort(int* ar, int len);
void shell_sort(int* ar, int len);
void count_sort(int* ar, int len);
//использование функции сортировок
float test_sort(void (*testSort)(int*, int), int len, int &flag);
//для каких-то там тестов
void false_or_true(void (*testSort)(int*, int), int len, int* ar);
void test_sort();


