# TODO
from cs50 import get_int
def getinput ():
    while True :
        h = get_int("height :")
        if h>0 and h<9:
            return h


def main():
    h = (getinput())
    t = 1
    for i in range(h):
        print(" "*(h-1) ,end='')
        h = h-1
        print("#"*t)
        t = t+1
main()