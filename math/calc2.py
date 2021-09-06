import math

print("Введите действие калькулятора \n Если нужна помощь напишите Help")


while True:
#Пользователь вводит сначала действие калькулятора
    user_input = input( )

"""
    #if user_input == "Help":
        #print(" \"*-Умножение\" \n\" /- Деление \" \n\" - Вычитание \" \n\" + - Сложение\" \n\"Пиф - Теорема Пифагора\" \n\" cos - Теорема косинусов\" \n\"//-Целочисленое деление\" \n\"%- Деление по модулю\" ")
"""

#Функция выполняющая действия при вводе

if user_input == "Help":
    print(" \"*-Умножение\" \n \" /- Деление \" \n \" - Вычитание \" \n \" + - Сложение\" \n \"Пиф - Теорема Пифагора\" \n \" cos - Теорема косинусов\" \n \"//-Целочисленое деление\" \n \"%- Деление по модулю\" ")
elif user_input == "*":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 * num2)
        print(result)

elif user_input == "+":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 + num2)
        print(result)

elif user_input == "-":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 - num2)
        print(result)

elif user_input == "/":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 / num2)
        print(result)

elif user_input == "Пиф":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(math.sqrt(num1**2 + num2**2))
        print(result)

elif user_input == "cos":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        angel= float(input("Введите угол: "))
        result = str(math.sqrt(num1**2 + num2**2 -2*num1*num2*math.cos(math.radians(angel))))
        print(result)

elif user_input == "//":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 // num2)
        print(result)

elif user_input == "%":
        num1= float(input("Введите первое число: "))
        num2= float(input("Введите второе число: "))
        result = str(num1 % num2)
        print(result)

else:
        print("Неизвестное действие")
