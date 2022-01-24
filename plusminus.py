#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    total_lentgh = len(arr)
    positive = 0
    negative = 0
    zero = 0
    for item in arr:
        if item == 0:
            zero += 1
        elif item > 0:
            positive += 1
        else:
            negative += 1
    print(positive/total_lentgh)
    print(negative/total_lentgh)
    print(zero/total_lentgh)

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
