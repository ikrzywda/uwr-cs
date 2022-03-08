void insertion_sort(int arr[], int length) {
    int j, temp;
    for (int i = 0; i < length; i++) {
        j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    insertion_sort(arr, 10);
}