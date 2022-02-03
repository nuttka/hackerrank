#!/bin/python3

import math
import os
import random
import re
import sys
import string


#
# Complete the 'pangrams' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def pangrams(s):
    return "pangram" if set(s.lower()) >= set(string.ascii_lowercase) else "not pangram"



if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)
    print(result)
    # fptr.write(result + '\n')

    # fptr.close()
