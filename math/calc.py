import math

#Пользователь вводит сначала действие калькулятора
print("Введите действие калькулятора \n Если нужна помощь напишите Help")
user_input = input(": ")


#Функция выполняющая действия при вводе
while True:
    print("Введите действие калькулятора \n Если нужна помощь напишите Help")
    user_input = input(": ")
    if user_input == "*":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 * num2)
        print(result)
        continue

    elif user_input == "+":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 + num2)
        print(result)
        continue

    elif user_input == "-":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 - num2)
        print(result)
        continue

    elif user_input == "/":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 / num2)
        print(result)
        continue

    elif user_input == "Пиф":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(math.sqrt(num1**2 + num2**2))
        print(result)
        continue

    elif user_input == "cos":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        angel= float(input("Введите угол: "))
        result = str(math.sqrt(num1**2 + num2**2 -2*num1*num2*math.cos(math.radians(angel))))
        print(result)
        continue

    elif user_input == "//":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 // num2)
        print(result)
        continue
    elif user_input == "%":
        print("Неизвестное действие")
