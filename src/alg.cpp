// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
int countPairs1(int* arr, int len, int value);
int countPairs2(int* arr, int len, int value);
int countPairs3(int* arr, int len, int value);

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (i != j) {
        if (arr[i] + arr[j] == value) 
          count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, i = 0, j = len - 1;
  for (i; i <= len; i++) {
    for (j; j > 0; ) {
      while (i != j) {
        if ((arr[i] + arr[j] > value) || arr[j] >= value) {
          j--;
        } else if (arr[i] + arr[j] < value) {
          i++;
        } else if (arr[i] + arr[j] == value) {
          count++;
          j--;
        }
      }
      if (i == j) {
        i = len;
        j = 0;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int left = 0, right = len - 1, sum = arr[left] + arr[right], count = 0;
  while (left != right) {
    if (arr[left] + arr[right] < value) {
      left++;
    } else if (arr[left] + arr[right] > value) {
      right--;
    } else {
      count++;
      right--;
    }
  }
  return count;
}

int main() {
  int lenght = 0, mean = 0;
  std::cin >> lenght >> mean;
  int* arr = new int[lenght];
  for (int h = 0; h < lenght; h++) {
    std::cin >> arr[h];
  }
  std::sort(arr, arr + lenght);
  std::cout << countPairs1(arr, lenght, mean) << " " << countPairs2(arr, lenght, mean) << " " << countPairs3(arr, lenght, mean);
  return 0;
}
