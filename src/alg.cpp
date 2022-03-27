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
  return 0;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, dop = 0;
  for (int i = 0; i < len; i++) {
    int left = 1 + i, right = len - 1;
    while (left < right) {
      dop = (left + right) / 2;
      if (arr[dop] + arr[left] < value) {
        left = dop + 1;
      } else { right = dop; }
    }
    while (arr[i] + arr[left] == value) {
      count++;
      left++;
    }
  }
  return count;
  return 0;
}
