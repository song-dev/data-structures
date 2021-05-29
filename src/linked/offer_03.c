#include <stdio.h>

void printfArr(int *nums, int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int findRepeatNumber(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; ++i)
    {
        if (i == nums[i])
        {
            continue;
        }
        if (nums[i] == nums[nums[i]])
        {
            return nums[i];
        }
        else
        {
            int temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;

        }
        printfArr(nums, numsSize);
    }
    printf("\n");
    return -1;
}

int main()
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int result = findRepeatNumber(arr, sizeof(arr) / sizeof(int));
    printf("result: %d\n", result);
    return 0;
}