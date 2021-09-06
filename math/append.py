x = []
n = 0 
while n <10:
    y = int(input("y: "))
    x.append(y)
    n+=1
    print(x, len(x))
x.sort()
print(x)