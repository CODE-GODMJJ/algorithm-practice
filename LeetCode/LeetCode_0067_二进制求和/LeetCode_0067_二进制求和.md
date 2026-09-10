# LeetCode 67：二进制求和

- 平台：LeetCode
- 题号：67
- 难度：简单
- 题目链接：https://leetcode.cn/problems/add-binary/
- 使用语言：C
- 完成日期：2026-09-10
- 提交结果：待你在力扣平台确认

## 一、题目理解

给定两个由字符 0 和 1 组成的二进制字符串 a 和 b，要求计算它们的二进制和，并以二进制字符串的形式返回结果。

本题不能直接把很长的二进制字符串转换成普通整数，因为字符串长度可能超过整型能够表示的范围。因此应该按照竖式加法的方式，从两个字符串的末尾开始逐位相加，并处理进位。

## 二、解题思路

本题使用从低位到高位的模拟加法：

- i 指向字符串 a 的末尾，j 指向字符串 b 的末尾；
- numA 和 numB 分别表示当前位的二进制数字；
- sum 等于当前位的两个数字加上 carry；
- sum % 2 得到当前位的结果，sum / 2 得到下一位的进位；
- 由于计算过程是从低位开始的，所以结果会先逆序保存；
- 最后使用双指针将结果字符串反转，并补上字符串结束符 '\0'。

以 a = "11"，b = "1" 为例，计算过程为：

| 当前位 | a 当前数字 | b 当前数字 | 进位 | 当前结果 |
| ---: | ---: | ---: | ---: | ---: |
| 个位 | 1 | 1 | 0 | 0，产生进位 1 |
| 十位 | 1 | 0 | 1 | 0，产生进位 1 |
| 新增最高位 | 0 | 0 | 1 | 1 |

最终结果为 "100"。

## 三、代码

下面的代码包含了 LeetCode 需要的 addBinary 函数，以及用于 VS Code 本地测试的 main 函数。提交到 OJ 时，平台通常只需要提交主要函数部分。

~~~c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * addBinary(char * a, char * b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int i = lenA - 1;
    int j = lenB - 1;
    int carry = 0;
    int idx = 0;
    int maxLen = lenA > lenB ? lenA : lenB;
    char* res = (char*)malloc(sizeof(char) * (maxLen + 2));

    while(i >= 0 || j >= 0 || carry > 0)
    {
        int numA = i >= 0 ? (a[i--] - '0') : 0;
        int numB = j >= 0 ? (b[j--] - '0') : 0;
        int sum = numA + numB + carry;
        int bit = sum % 2;
        carry = sum / 2;
        res[idx++] = bit + '0';
    }

    int left = 0;
    int right = idx - 1;
    while(left < right)
    {
        char temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left++;
        right--;
    }
    res[idx] = '\0';
    return res;
}

int main(void)
{
    char a[] = "11";
    char b[] = "1";
    char* ans = addBinary(a,b);
    printf("%s\n", ans);
    free(ans);
    return 0;
}
~~~

完整代码保存在同目录下的：

[LeetCode_0067_二进制求和.c](./LeetCode_0067_二进制求和.c)

## 四、复杂度分析

- 时间复杂度：O(n + m)
- 空间复杂度：O(n + m)

其中 n 和 m 分别是字符串 a 和 b 的长度。两个字符串各遍历一次，结果字符串需要额外保存计算结果，因此空间复杂度为 O(max(n, m))，写成 O(n + m) 也可以表示同一数量级。

## 五、易错点

1. 循环条件不能只写成 i >= 0 && j >= 0，还要处理较长字符串剩余部分以及最后的 carry。
2. 当前位结果是 sum % 2，下一位进位是 sum / 2。
3. 结果是从低位向高位生成的，最后必须反转。
4. 返回的字符串必须以 '\0' 结尾，否则不能作为 C 字符串使用。
5. 申请空间时要预留 maxLen + 2：一个位置用于可能产生的最高位，一个位置用于 '\0'。
6. addBinary 返回的是 malloc 申请的内存，本地 main 使用完成后要调用 free 释放。
7. strlen 的返回类型是 size_t；在本题长度范围内保存到 int 可以正常工作，但更严谨的写法可以使用 size_t 保存字符串长度。

## 六、复盘

- 本题对应知识点：字符串、模拟、进位、动态内存管理。
- 看到两个超长数字以字符串形式给出，并且要求求和时，可以考虑从末尾逐位模拟，而不是转换成整数。
- 本题和十进制竖式加法的过程相同，只是每一位的进制从 10 换成了 2。
- 本地运行时使用 a = "11"、b = "1"，输出应为 "100"。

## 七、提交记录

- 提交状态：待补充
- 是否一次通过：待补充
- 如果没有一次通过：记录报错信息、原因和修改方法
