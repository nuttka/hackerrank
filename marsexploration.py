#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'marsExploration' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def marsExploration(s):
    number_of_sos = int(len(s)/3)
    err = 0

    for i in range(number_of_sos):
        time = 3*i

        if s[time] != "S":
            err += 1
        if s[time+1] != "O":
            err += 1
        if s[time+2] != "S":
            err += 1

    return err

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = marsExploration(s)

    print(result)
    # fptr.write(str(result) + '\n')

    # fptr.close()
