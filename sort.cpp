#include "sort.h"
#define maxn 100
#define MAX 5
void printarr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void exch(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void interchangesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                exch(a[i], a[j]);
        }
    }
}

void bubblesort(int a[], int n)
{ // ( 5 1 4 2 8 )
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        { // minh họa vòng lặp i=0
            // ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 )
            // ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 )
            // ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 )
            // ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
            if (a[j] > a[j + 1])
                exch(a[j], a[j + 1]);
        }
    }
}
void selectionsort(int a[], int n)
{ // ( 5 1 4 2 8 )
    int min, i, j;
    for (i = 0; i < n - 1; i++)
    {                               // giới hạn của i từ 0 tới n-2
        min = i;                    // xác định min của mảng chưa sắp xếp ở đây amin =5
        for (j = i + 1; j < n; j++) // giới hạn của j từ i tới n-1
            if (a[j] < a[min])
                min = j;    // min là phần tử nhỏ nhất có trong giới hạn của j amin =1
        exch(a[min], a[i]); // đổi chỗ với min ban đầu 1 5 4 2 8
    }
}

void insertionsort(int a[], int n)
{ // ( 5 1 4 2 8 )
    int x, j;
    for (int i = 1; i < n; i++)
    {
        // i=2: 1 5 4 2 8; i=3 :1 4 5 2 8; i =4 :  1 2 4 5 8;
        x = a[i];
        j = i - 1; // (x=1; j=0) (x=4; j=1) (x=2; j=2) (x=8; j=3)
        while ((j >= 0) && (a[j] > x))
        {                    // đã thõa điều kiện khi i =3 nhưng thuật toán sẽ tiếp tục chạy
            a[j + 1] = a[j]; // 5 5 4 2 8 ; 1 5 5 2 8;khi j =2 ( 1 4 5 5 8 ; 1 4 4 5 8);
            j--;
        }
        a[j + 1] = x; // 1 5 4 2 8; 1 4 5 2 8 ; 1 2 4 5 8
        printarr(a, n);
    }
}
// nói chung là vẫn chưa hiểu cái mục đích của cái shellort này làm gì hiện tại chỉ như insertion nhưng dài hơn
void shellsort(int a[], int n)
{                             //  bản bổ sung của insertionsort khi xử lý số lớn và số nhỏ quá xa nhau(gg)
    int interval, i, j, temp; // mục tiêu là xác định khoảng (interval) để sắp xếp chúng theo insertionsort
    for (interval = n / 2; interval > 0; interval /= 2)
    {
        for (i = interval; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
            printarr(a, n);
        }
        cout << endl;
    }
}
int partition(int arr[], int low, int high) // high=8
{                                           // 4, 2, 8, 3, 1, 5, 7,11,6
    int pivot = arr[high];                  // pivot=6
    int i = (low - 1);                      // i là giá trị đánh dấu nơi xảy ra sự cố khí có số lớn hơn pivot
    for (int j = low; j <= high - 1; j++)
    {
        // nếu có số nhỏ hơn pivot
        if (arr[j] < pivot)
        {
            i++;                  // thì tăng i lên vì đúng quá trình , khi có sự cố thì i và j sẽ lệch nhau
            exch(arr[i], arr[j]); // nếu i và j bằng nhau thì bt, nhưng khi lệch nhau thì đổi chỗ số bé(j) với vt xảy ra sự cố(i)
        }
        cout << i << " " << j << " :";
        printarr(arr, 9);
    }
    cout << endl;
    exch(arr[i + 1], arr[high]); // đổi chỗ chính pivot với vt sự cố
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi ban đầu khi low high con xa thì giữ số lần so sánh thành công trên partition
        int pi = partition(arr, low, high); // pi =5
        cout << endl
             << "low=" << low << " pi = " << pi << " high=" << high << endl;
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    // tao cac mang tam
    int *L = new int[n1];
    int *R = new int[n2];
    // sao chép từ mảng a vào hai mảng phụ
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0; // bắt đầu từ phần tử đầu của hai mảng trên
    int k = l;
    // các bước cuối là so sánh và sao chép lại vào mảng chính a
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    printarr(a, 9);
    delete[] L;
    delete[] R;
}
void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        // chia doi thanh hai mang tu l->m va tu m+1->r
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        // vua cho lai vao mang a vua sap xep
        merge(a, l, m, r);
    }
    else
        return;
}
// Binary Heap là một cây nhị phân hoàn chỉnh cho nên nó thường được biểu diễn dưới dạng một mảng.
// heapsort dựa trên cấu trúc dữ liệu của Binary heap: Ý tưởng là đưa phần tử lớn nhất lên đầu mảng
// rồi vứt nó về vị trí cuối mảng
void heapify(int arr[], int N, int i)
{
    // khai báo root
    int largest = i;
    // phần tử bên trái luôn có vt= 2*i + 1
    int l = 2 * i + 1;
    // hần tử bên phải luôn có vt= 2*i + 2
    int r = 2 * i + 2;
    // kiểm tra xem có phần tử bên trái k và có lớn hơn root ko
    if (l < N && arr[l] > arr[largest])
        largest = l;
    // kiểm tra xem có phần tử bên phải k và có lớn hơn root ko
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // khi có phần tử lớn hơn root ban đầu
    if (largest != i)
    {
        exch(arr[i], arr[largest]);

        // đệ quy với i = largest
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // tạo một cấu trúc heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--)
    {

        // vì heapify sẽ sắp xếp phần tử lớn nhất ở đầu mảng
        // nên phải chuyển nó về cuối mảng
        cout << endl;
        printarr(arr, 9);
        exch(arr[0], arr[i]);
        printarr(arr, 9);
        // kiểm tra lại lần nữa với maxheap hay gọi là kiểm tra xem root có phải lớn nhất chưa
        heapify(arr, i, 0);
    }
}
void radixSort(int *a, int n)
{
    int b[n], m = a[0], exp = 1;
    // xác định số lớn nhất có mấy chữ số để thực hiện vòng lặp
    for (int i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (m / exp > 0)
    {
        int bucket[10] = {0};
        // đếm số phần tử thuộc từ 0-9 của các hàng đơn vị,chục,trăm...
        for (int i = 0; i < n; i++)
            bucket[(a[i] / exp) % 10]++;
        // xác định đúng vị trí của các số ở trên để thêm vào mảng cho đúng vị trí
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        // printarr(bucket,10);
        cout << endl;
        // sắp xếp theo từng hàng đv,chục.
        // hàng chục thì lấy mảng đã sắp xếp của hàng đv mà sx tiếp,các hàng sau tương tự

        for (int i = n - 1; i >= 0; i--)
        {
            cout << (a[i] / exp) % 10 << " ";
            b[bucket[(a[i] / exp) % 10] - 1] = a[i]; // sao chép các số có hàng đv,chục vào mảng theo đúng thứ tự từ nhỏ đến lớn
            bucket[(a[i] / exp) % 10]--;
        }
        // vd :9, 10, 8, 3, 11, 5, 1,7,6
        // sau khi thực hiện hàng đơn vị: 10 11 1 3 5 6 7 8 9
        //  sao chép lại mảng đã sắp xếp vào mảng a để tiếp tục lên hàng chục
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
        printarr(a, 9);
    }
}
// void bucketSort(float arr[], int n)
// {
//     // 1) Create n empty buckets
//     vector<float> b[n];

//     // 2) Put array elements in different buckets
//     for (int i = 0; i < n; i++) {
//         int bi = n * arr[i]; // Index in bucket
//         b[bi].push_back(arr[i]);
//     }

//     // 3) Sort individual buckets
//     for (int i = 0; i < n; i++)
//         sort(b[i].begin(), b[i].end());

//     // 4) Concatenate all buckets into arr[]
//     int index = 0;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < b[i].size(); j++)
//             arr[index++] = b[i][j];
// }

// void counting_sort(int input[], int n)
// {
//     int* output= new int [n]; // The output will have sorted input array
//     int max = input[0];
//     int min = input[0];

//     int i;
//     for (i = 1; i < n; i++)
//     {
//         if (input[i] > max)
//             max = input[i]; // Maximum value in array
//         else if (input[i] < min)
//             min = input[i]; // Minimum value in array
//     }

//     int k = max - min + 1; // Size of count array

//     int* count_array = new int[k];
//     for (i = 0; i < k; i++)
//         count_array[i] = 0;

//     for (i = 0; i < n; i++)
//         count_array[input[i] - min]++; // Store count of each individual input value

//     /* Change count_array so that count_array now contains actual
//      position of input values in output array */
//     for (i = 1; i < k; i++)
//         count_array[i] += count_array[i - 1];

//     // Populate output array using count_array and input array
//     for (i = 0; i < n; i++)
//     {
//         output[count_array[input[i] - min] - 1] = input[i];
//         count_array[input[i] - min]--;
//     }

//     for (i = 0; i < n; i++)
//         input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

// }

int main()
{
    int n;
    // cout << "Moi ban nhap so phan tu can sap xep: "; cin >> n;
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    int arr[] = {9, 10, 8, 3, 11, 5, 1, 7, 6}, a[10], b[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl;
    radixSort(arr, size);
    cout << endl;
    printarr(arr, size);
}
