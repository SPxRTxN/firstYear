import random 

a = random.randint(0, 1000000)
print(a)

def Hello():
    x = []
    n = 0 
    while n <10:
        a = random.randint(0, 1000000)
        x.append(a)
        n+=1
    x1 = x.sort()
    print(x1)
    return x, x1
print(Hello()) 
