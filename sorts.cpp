#include "sorts.h"

void swap(int& a, int& b) {
    a += b;
    b = a - b;
    a = a - b;
}
int poisk_min(int* ar, int len, int n) {
    int min = n;
    for (int i = n; i < len; i++)
        if (ar[i] < ar[min])
            min = i;
    return min;
}
int poisk_max(int* ar, int len) {
    int max = 0;
    for (int i = 0; i < len; i++)
        if (ar[i] > ar[max])
            max = i;
    return max;
}
void fill_array(int* ar, int len) {
    for (int i = 0; i < len; i++) {
        ar[i] = 0 + rand() % 10000;
    }
}
int partition(int* ar, int first, int last) {
    int pivot = ar[(last + first) / 2];
    int i = first;
    int j = last;
    while(1){
        while (ar[i] < pivot) {
            i++;
        }
        while (ar[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(ar[i], ar[j]);
        i++;
        j--;
    }

    return j;
}

void sort_choice(int* ar, int len) {
    for (int i = 0; i < len; i++) {
        int minindex = poisk_min(&ar[0], len, i);
        if (ar[i] != ar[minindex])
            swap(ar[i], ar[minindex]);
    }
}
void quick_sort(int* ar, int last, int first) {
    if (first < last) {
        int p = partition(ar, first, last);

        quick_sort(ar, p, first);
        quick_sort(ar, last, p + 1);
    }
}
void quick_demo(int* ar, int len){
    quick_sort(ar, len - 1, 0);
}
void select_sort(int* ar, int len) {
    for (; len > 0; len--) {
        int maxindex = poisk_max(&ar[0], len);
        if (ar[len - 1] != ar[maxindex]) {
            swap(ar[len - 1], ar[maxindex]);
        }
    }
}
void bubble_sort(int* ar, int len) {
    bool kk = false;
    for (int k = len - 1; len > 0 && !kk; k--) {
        for (int i = 0; i < k; i++) {
            kk = true;//предпологаем, что все стоит правильно
            if (ar[i] > ar[i + 1]) {
                kk = false;
                swap(ar[i], ar[i + 1]);
            }
        }
    }
}
void shell_sort(int* ar, int len) {
    int d = len / 2, i = 0, j = 0;
    while(d >= 1) {
        i = 0;
        j = d;
        while (j < len) {
            if (ar[i] > ar[j])
                swap(ar[i], ar[j]);
            i++;
            j++;
        }
        if (d < 3) {
            d--;
            continue;
        }
        d /= 2;
    }
}
void count_sort(int* ar, int len) {
    int k = ar[poisk_max(ar, len)];
    int* C = new int[k + 1];
    for (int i = 0; i < k + 1; i++)
        C[i] = 0;
    for (int i = 0; i < len; i++) {
        C[ar[i]]++;
    }
    int i = 0;
    int g = 0;
    while (C[k]) {
        if (C[i]) {
            ar[g++] = i;
            C[i]--;
            continue;
        }
        i++;
    }
    delete[] C;
}

float test_sort(void (*testSort)(int*, int), int len, int &flag) {
    int* ar = new int[len];
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    fill_array(ar, len);
    start = std::chrono::steady_clock::now();

    testSort(ar, len);

    end = std::chrono::steady_clock::now();
    if (std::chrono::duration<float>(end - start).count()  > 20) {
        flag = 1;
    }
    delete[] ar;
    return std::chrono::duration<float>(end - start).count();
}
void false_or_true(void (*testSort)(int*, int), int len, int* ar) {
    testSort(ar, len);
}
void test_sort(){
    void(*sort[])(int*, int) = {quick_demo,count_sort, bubble_sort,
                                select_sort, sort_choice,shell_sort};
    int len = 100;
    bool kk = false;//запомнит, верно ли стоят элементы в массиве
    int* ar = new int[len];
    for(int i = 0; i < N; i++){
        fill_array(ar, len);
        false_or_true( sort[i], len, ar);
        kk = true;
        for(int g = 0; g < len; g++){
            if(ar[g] > ar[g+1])
                kk = false;
        }

        if(kk){
            std::cout << "bad sort\n";
            continue;

        }
        std::cout << "good sort\n";

    }
}