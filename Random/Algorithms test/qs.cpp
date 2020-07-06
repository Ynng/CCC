#include <iostream>
using namespace std;

void swapnum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void quicksort(int array[], int l, int r)
{
    int length = r - l + 1;
    if (length <= 2)
    {
        if (array[l] > array[r])
            swapnum(&array[l], &array[r]);
        return;
    }
    int p = length / 2+l;
    int right = r, left = l;

    swapnum(&array[p], &array[r]);
    p = r;
    r--;
    while (r >= l)
    {
        if (array[l] > array[p] && array[r] < array[p])
        {
            swapnum(&array[l], &array[r]);
        }
        if (array[l] <= array[p])
        {
            l++;
        }
        if (array[r] >= array[p])
        {
            r--;
        }
    }
    swapnum(&array[l], &array[p]);
    p = l;
    quicksort(array, p + 1, right);
    quicksort(array, left, p - 1);
    return;
}

int main()
{
    // int length, input[] = {61, 1781, 24, 87654, 1345, 76951324, 547, 6354, 432, 654, 1324, 8654, 3254, 765};
    int length, input[] = {9, 1, 15, 11, 34, 14};
    length = (sizeof(input) / sizeof(*input));
    // swapnum(&input[0], &input[1]);
    quicksort(input, 0, length - 1);
    // cout << length;
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", input[i]);
    }
    return 0;
}
