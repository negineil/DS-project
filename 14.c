#include <stdio.h>

int findFloor(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int floor = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return arr[mid];
        else if (arr[mid] < target) {
            floor = arr[mid];
            left = mid + 1;
        } else
            right = mid - 1;
    }
    return floor;
}

int findCeil(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int ceil = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return arr[mid];
        else if (arr[mid] > target) {
            ceil = arr[mid];
            right = mid - 1;
        } else
            left = mid + 1;
    }
    return ceil;
}

int findPeak(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] < arr[mid + 1])
            left = mid + 1;
    }
    return arr[left];
}

int findMinimum(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[right])
            right = mid;
        else
            left = mid + 1;
    }
    return arr[left];
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    printf("Floor of %d is: %d\n", target, findFloor(arr, n, target));
    printf("Ceil of %d is: %d\n", target, findCeil(arr, n, target));
    printf("Peak element is: %d\n", findPeak(arr, n));
    printf("Minimum element is: %d\n", findMinimum(arr, n));
    return 0;
}
