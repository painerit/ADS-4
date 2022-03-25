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
    if (value/2 < arr[i])
      break;
    for (int j = (len - 1); j > i; j--) {
      if (value/2 > arr[j])
        continue;
      else if (arr[i] + arr[j] == value)
        sum++;
    }
  }
  return sum;
}
int nums(int *arr, int len, int mid, int sum, int num) {
  if (mid != num)
    sum++;
  int mid2 = mid;
  while ((arr[mid2] == arr[mid2 + 1]) && (mid2 + 1 < len)) {
    sum++;
    mid2++;
  }
  while ((arr[mid] == arr[mid-1]) && (mid - 1 > num)) {
    sum++;
    mid--;
  }
  return sum;
}
int BinSearch(int* arr, int len, int value, int left, int sum) {
  int right = len, num = left;
  while (left <= right) {
    int mid = left + (right - left) / 2;
      if (arr[num] + arr[mid] == value)
        return nums(arr, len, mid, sum, num);
      else if (arr[num] + arr[mid] > value)
        right = mid;
      else
        left = mid;
  }
  return sum;
}
int countPairs3(int *arr, int len, int value) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (value/2 <= arr[i])
      break;
  sum = BinSearch(arr, len, value, i, sum);
  }
  return sum;
}
