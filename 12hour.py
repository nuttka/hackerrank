#!/bin/python3
# .
import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    if s[8] == "P":
        if int(s[:2]) < 12:
            number = s[:2]
            number = int(number) + 12
            return str(number) + s[2:8]
        else:
            return s[:8]
    else:
        if int(s[:2]) < 12:
            return s[:8]
        else:
            number = s[:2]
            number = int(number) - 12
            return '0' + str(number) + s[2:8] if len(str(number)) == 1 else str(number) + s[2:8]
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
