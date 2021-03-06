"""
Generates the LEX directives for the DECAF tokens
place the raw token definition from the page in tokens.txt
remove all the comments in parentheses
execute this python program in the folder.
"""

f = open("./tokens.txt", "r")

for line in f:
        token_sym = ' '.join(line.split()).split(" ")
        token = token_sym[0]
        sym = token_sym[1]
        spaces = " " * (20 - len(sym)+2)
        print('\"%s\"%s{return(%s);}' % (sym, spaces, token))