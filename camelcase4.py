import fileinput
import re

for line in fileinput.input():
    _op, _type, _string = line.rstrip().split(';')

    if _op == 'S':

        if _type == 'M':
            words = _string[:-2]
            s = re.sub(r"(\w)([A-Z])", r"\1 \2", words)
            print(s.lower())

        elif _type == 'C':
            s = re.sub(r"(\w)([A-Z])", r"\1 \2", _string)
            print(s.lower())

            
        elif _type == 'V':
            s = re.sub(r"(\w)([A-Z])", r"\1 \2", _string)
            print(s.lower())



    elif _op == 'C':
        words = _string.title()

        if _type == 'M':
            words = re.sub(' ', '', words)

            print(words[0].lower() + words[1:] + "()")

        elif _type == 'C':
            words = re.sub(' ', '', words)

            print(words)
            
            
        elif _type == 'V':
            words = re.sub(' ', '', words)

            print(words[0].lower() + words[1:])