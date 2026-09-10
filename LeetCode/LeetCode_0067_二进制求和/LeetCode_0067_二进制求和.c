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
