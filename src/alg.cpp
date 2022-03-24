// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    for (int j = (i + 1); j < len; j++) {
      if (arr[i] + arr[j] == value)
        sum++;
    }
  }
  return sum;
}
int countPairs2(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    for (int j = (len - 1); j > i; j--) {
      if ((j >= value) || (j < (value/2)))
        continue;
      else if (arr[i] + arr[j] == value)
        sum++;
    }
  }
  return sum;
}
int countPairs3(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
  }
}
