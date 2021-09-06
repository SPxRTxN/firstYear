#a * x^2 + b * x + c = 0
from math import sqrt

while True:
    a = float(input("a= "))
    b = float(input("b= "))
    c = float(input("c= "))

    d =  b**2 - 4 * a * c

    if d > 0:
        x1 = (-b + sqrt(d)) / (2*a)
        x2 = (-b - sqrt(d)) / (2*a)
        print(x1, x2)
    if d == 0:
        try:
            x1 =  (-b) / (2*a)
            print(x1)
        except ZeroDivisionError:
            print("x = 0")
    if d < 0:
        print("none") 

