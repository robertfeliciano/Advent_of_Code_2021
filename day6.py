'''
Slow way.
def simulate(ants, days):
    for day in range(0, days):
        for i in range(0, len(ants)):
            if ants[i] == 0:
                ants[i] = 6
                ants.append(8)
            else:
                ants[i]-=1
    return len(ants)
'''
from collections import Counter
from random import randint

def simulate(ants, days):
    today = dict(Counter(ants))
    for i in range(0, 9):
        if today.get(i) is None:
            today[i] = 0
    nextday = {}
    for _ in range(0,days):
        for i in range(0, 9):
            nextday[i] = today[i+1] if i!=8 else today[0]
        if today[0] > 0:
            nextday[6] += today[0]
        today = nextday
        nextday = {}
    sum = 0
    for mapping in today:
        sum+=today[mapping]
    return sum




if __name__ == "__main__":
    inpt = input("Initial list of Fin-ants: ")
    lst = inpt.split(",")
    for i in range(0, len(lst)):
        lst[i] = int(lst[i])

    lst2 = lst.copy()
    ants = simulate(lst, 80)
    print("After 80 days, there are %d ants." %(ants))
    
    ants = simulate(lst2, 256)
    print("After 256 days, there are %d ants." %(ants))

    
    '''VERY BIG TEST. '''
    '''biglst = []
    for i in range(0, 300):
        biglst.append(randint(1,6))
    ants = simulate(biglst, 10000)
    print("After 10000 days, there are %d ants. That's a lot of ants." %(ants))'''
    