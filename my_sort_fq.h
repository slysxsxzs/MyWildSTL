#ifndef MY_SORT_H
#define MY_SORT_H

void swap(int &a, int &b) {
    int a_b = a;
    a = b;
    b = a_b;
}

//对数计算部分
int log2_int(int n) {
    if (n <= 0) 
    {return 0;}
    int res = 0;
    while (n >>= 1) 
    {res++;}
    return res;
}



//堆排部分
void heapify(int arr[], int max_num, int i)
{
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;

    if(left < max_num && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < max_num && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, max_num, largest);
    }
}
void heap_sort(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n,i);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}



//插入排序部分
void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}




//快排三数取中部分，分区部分，主部分
int median_of_three(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);

    swap(arr[mid], arr[high]);
    return arr[high];
}
int partition(int arr[], int left, int right) {
    int pivot = median_of_three(arr, left, right);
    int i = left - 1;
    for(int os = left; os < right; os++)
    {
        if(arr[os] < pivot)
        {   i++;
            swap(arr[i], arr[os]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}



void intro_sort(int arr[], int left, int right, int depth_limit) {
    // 1. 小数组优化：长度小于等于16直接使用插入排序
    if (right - left + 1 <= 16) {
        insertion_sort(arr + left, right - left + 1);
        return;
    }
    
    // 2. 递归过深：堆排序
    if (depth_limit <= 0) {
        heap_sort(arr + left, right - left + 1);
        return;
    }
    
    // 3. 正常快排分区
    int pi = partition(arr, left, right);
    intro_sort(arr, left, pi - 1, depth_limit - 1);
    intro_sort(arr, pi + 1, right, depth_limit - 1);
}

void my_sort(int arr[], int n) {
    if (n <= 1) return;
    int depth_limit = 2 * log2_int(n);
    intro_sort(arr, 0, n - 1, depth_limit);
}
#endif