#!/bin/python3

import math
import os
import random
import re
import sys
from unicodedata import numeric

#
# Complete the 'sockMerchant' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY ar
#

def sockMerchant(n, ar):
    number_of_pairs = 0
    di = dict()

    for a in ar:
        if a in di.keys():
            di[a] += 1
        else:
            di[a] = 1

    for key in di.keys():
        number_of_pairs += int(di[key]/2)

    return number_of_pairs


if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)
    print(result)
    # fptr.write(str(result) + '\n')

    # fptr.close()
