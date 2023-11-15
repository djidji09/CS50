# TODO
from cs50 import get_float
while True:
    money = get_float("how much do you have : ")
    if money >0:
        break
cents = money *100
quarters = cents // 25
cents = cents - (quarters * 25)
dimes = cents // 10
cents = cents - (dimes * 10)
nickels = cents // 5
cents = cents - (nickels * 5)
pennies = cents // 1
cents = cents - (pennies * 1)
coins = quarters + dimes + nickels + pennies
print(coins)