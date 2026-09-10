// 双指针解法
// #include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int fast = 0;
    int slow = 0;
    while(fast < numsSize)
    {
        if(nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}

// int main(void)
// {
//     int nums[] = {3,2,2,3};
//     int val = 3;
//     int n = sizeof(nums)/sizeof(nums[0]);

//     int newLen = removeElement(nums, n, val);

//     printf("新数组长度：%d\n", newLen);
//     printf("保留元素：");
//     for(int i = 0; i < newLen; i++)
//     {
//         printf("%d ", nums[i]);
//     }
//     return 0;
// }
