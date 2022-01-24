#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'breakingRecords' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY scores as parameter.
#

def breakingRecords(scores):
    value_min = scores[0]
    value_max = scores[0]
    min_times = 0
    max_times = 0

    for score in scores:
        if score > value_max:
            value_max = score
            max_times += 1
        if score < value_min:
            value_min = score
            min_times += 1

    return [max_times, min_times]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
