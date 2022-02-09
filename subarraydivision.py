#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'birthday' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY s
#  2. INTEGER d
#  3. INTEGER m
#

def birthday(s, d, m):
    sub_arrays = 0

    for i in range(len(s)):
        sum_total = 0
        jmp = False

        for j in range(m):
            if i+j >= len(s):
                jmp = True
                break
            sum_total += s[i+j]
            print(s[i+j])

        print("break break break")
        if sum_total == d and not jmp:
            sub_arrays += 1

    return sub_arrays



    # Write your code here

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    first_multiple_input = input().rstrip().split()

    d = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    result = birthday(s, d, m)
    print(result)
    # fptr.write(str(result) + '\n')

    # fptr.close()
