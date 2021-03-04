#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs != nullptr && rhs != nullptr) {
        int a = *lhs;
        *lhs = *rhs;
        *rhs = a;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows < 1 | num_cols < 1) {
        return nullptr;
    }
    int **array = new int* [num_rows];
    for (int i = 0; i < num_rows; i++) {
        array[i] = new int [num_cols];
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            array[i][j] = init_value;
        }
    }
    return array;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if ((arr_2d_source == nullptr || arr_2d_target == nullptr) && (num_cols < 1 || num_rows < 1))
        return false;
    else {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                arr_2d_target[i][j] = arr_2d_source[i][j];
            }
        }
        return true;
    }
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size()/2; i++) {
        int a = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = a;
    }
}


// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (!arr_begin || !arr_end) {
        return;
    }
    int temp;
    while (arr_begin < arr_end) {
        temp = *arr_end;
        *arr_end = *arr_begin;
        *arr_begin = temp;
        arr_begin++;
        arr_end--;
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    int max = 0;
    int *pointer_max = &max;
    if (arr == nullptr) return nullptr;;
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if (arr[i] > *pointer_max) {
                *pointer_max = arr[i];
            }
        }
    } else return nullptr;
    return pointer_max;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    if (arr.empty()) return {};
    vector<int> result {};
    for (int element : arr) {
        if (element % 2 != 0) {
            result.push_back(element);
        }
    }
    return result;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> common_elements {};
    for(int & i : arr_a){
        for (int j : arr_b){
            if(i == j){
                common_elements.push_back(i);
            }
        }
    }
    return common_elements;
}
