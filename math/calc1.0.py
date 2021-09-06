import math


while True:
    num1 = float(input("Введите первое число: "))
    num2 = float(input("Введите второе число: "))
    user_input = str(input("Введите действие: "))

    if user_input == "Help":
        print(" \"*-Умножение\" \n \" /- Деление \" \n \" - Вычитание \" \n \" + - Сложение\" \n \"Пиф - Теорема Пифагора\" \n \" cos - Теорема косинусов\" \n \"//-Целочисленое деление\" \n \"%- Деление по модулю\" ")

    elif user_input == "*":
        result = str(num1 * num2)
        print(result)

    elif user_input == "+":
        result = str(num1 + num2)
        print(result)
        continue

    elif user_input == "-":
        result = str(num1 - num2)
        print(result)
        continue

    elif user_input == "/":
        result = str(num1 / num2)
        print(result)
        continue

    elif user_input == "Пиф":
        result = str(math.sqrt(num1**2 + num2**2))
        print(result)
        continue

    elif user_input == "cos":
        angel= float(input("Введите угол: "))
        result = str(math.sqrt(num1**2 + num2**2 -2*num1*num2*math.cos(math.radians(angel))))
        print(result)
        continue

    elif user_input == "//":
        result = str(num1 // num2)
        print(result)
        continue

    elif user_input == "%":
        result = str(num1 % num2)
        print(result)
        continue

    elif user_input == "ringle":
        result = str(num1* 3.14**2 )
        print(result)
        continue

    elif user_input == "Stop": break

    else:
        print("Неизвестное действие")
        continue
