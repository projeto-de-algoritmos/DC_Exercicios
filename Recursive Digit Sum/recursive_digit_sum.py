# https://www.hackerrank.com/challenges/recursive-digit-sum/problem
#!/bin/python3
import os

def dcSum(arr):
    arrLen = len(arr)
    if arrLen == 0:
        return 0
    elif arrLen == 1:
        return arr[0]
    mid = arrLen // 2
    left = dcSum(arr[0:mid])
    right = dcSum(arr[mid:arrLen + 1])
    return left + right


def superDigit(n, k):
    if int(n) < 10:
        return int(n)

    # K now takes on 1
    return superDigit(dcSum([int(i) for i in str(n)]) * k, 1)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = first_multiple_input[0]

    k = int(first_multiple_input[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()
