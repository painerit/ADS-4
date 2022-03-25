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
    if (value/2 < i)
      break;
    for (int j = (len - 1); j > i; j--) {
      if (value/2 > j)
        continue;
      else if (arr[i] + arr[j] == value)
        sum++;
    }
  }
  return sum;
}
int nums(int *arr, int len, int mid, int sum) {
  sum++;
  int mid2 = mid;
  while ((arr[mid2] == arr[mid2 + 1]) && (arr[mid2 + 1] < len)) {
    sum++;
    mid2++;
  }
  while ((arr[mid] == arr[mid - 1]) && (arr[mid-1] >= 0)) {
    sum++;
    mid--;
  }
  return sum;
}
int BinSearch(int *arr, int len, int value, int left, int sum) {
  int right = len - 1, num = left;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (num + arr[mid] == value)
      return nums(arr, len, mid, sum);
    else if (num + arr[mid] > value)
      right = mid;
    else
      left = mid + 1;
  }
  return sum;
}
int countPairs3(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (value/2 <= arr[i])
      break;
  sum = BinSearch(arr, len, value, i + 1, sum);
  }
  return sum;
}
