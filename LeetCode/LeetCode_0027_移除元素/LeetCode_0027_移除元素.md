# LeetCode 27：移除元素

- 平台：LeetCode
- 难度：简单
- 题目链接：https://leetcode.cn/problems/remove-element/
- 完成日期：2026-09-10

## 一、题目理解

给定一个整数数组 nums 和一个整数 val，需要在原数组中移除所有等于 val 的元素，并返回最终保留下来的元素数量 k。

题目只要求保证 nums 的前 k 个位置保存不等于 val 的元素，后面的元素内容不重要。

例如：

~~~text
输入：nums = [3, 2, 2, 3], val = 3
输出：k = 2
结果：nums 的前两个元素为 [2, 2]
~~~

这道题的关键要求是：

- 原地修改数组；
- 不需要额外创建新的数组；
- 返回保留下来的元素数量；
- 数组后面超出前 k 个位置的内容不需要处理。

## 二、解题思路

本题使用双指针法：

- fast 指针负责从左到右遍历整个数组；
- slow 指针负责记录下一个应该写入的位置；
- 当 nums[fast] 不等于 val 时，把 nums[fast] 放到 nums[slow]；
- 写入完成后 slow 加 1；
- 每次循环结束后 fast 加 1；
- 遍历结束时，slow 就是不等于 val 的元素数量。

以 nums = [3, 2, 2, 3]，val = 3 为例：

| fast | 当前元素 | 是否保留 | slow 操作 |
| ---: | ---: | --- | --- |
| 0 | 3 | 不保留 | slow 不变 |
| 1 | 2 | 保留 | nums[0] = 2，slow 加 1 |
| 2 | 2 | 保留 | nums[1] = 2，slow 加 1 |
| 3 | 3 | 不保留 | slow 不变 |

最终 slow 等于 2，数组前两个元素为 [2, 2]。

这种方法还会保持剩余元素的相对顺序，虽然题目并不强制要求保持顺序。

## 三、代码

当前代码使用的是 C 语言双指针实现：

~~~c
// 双指针解法

int removeElement(int *nums, int numsSize, int val)
{
    int fast = 0;
    int slow = 0;

    while (fast < numsSize)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }

        fast++;
    }

    return slow;
}
~~~

完整代码保存在同目录下的：

[LeetCode_0027_移除元素.c](./LeetCode_0027_移除元素.c)

## 四、复杂度分析

- 时间复杂度：O(n)
- 空间复杂度：O(1)

其中 n 是数组 nums 的元素个数。fast 指针只遍历数组一次，slow 指针只负责写入，因此整体是线性时间复杂度，并且没有使用额外数组。

## 五、易错点

1. 循环条件应为 fast < numsSize，不能写成 fast <= numsSize，否则会访问 nums[numsSize]，造成数组越界。
2. slow 只在当前元素不等于 val 时增加。
3. 函数返回值应该是 slow，而不是 numsSize。
4. 只需要保证数组前 slow 个元素正确，后面的元素不需要清理。
5. 这是原地修改，不能直接创建一个新的数组来保存结果。
6. 当前函数没有输入输出操作，因此不需要 stdio.h；本地测试时可以另外编写带 main 函数的测试文件。

## 六、复盘：
