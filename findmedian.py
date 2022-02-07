#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'findMedian' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def findMedian(arr):
    arr.sort()
    leng_arr = len(arr)
    
    return arr[int(leng_arr/2)] if leng_arr%2 == 1 else arr[int(leng_arr/2)] + arr[int(leng_arr/2) - 1]

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = findMedian(arr)

    print(result)

    # fptr.write(str(result) + '\n')

    # fptr.close()
