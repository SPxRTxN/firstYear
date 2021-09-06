import vk_api
import requests
import json
import time
import python3_anticaptcha
import random
import threading
from python3_anticaptcha import ImageToTextTask, errors
import pytz
from datetime import datetime

def captcha_handler(captcha):
	key = ImageToTextTask.ImageToTextTask(anticaptcha_key="key", save_format='const').captcha_handler(captcha_link=captcha.get_url())
	return captcha.try_again(key['solution']['text'])

vk = vk_api.VkApi(token = "token", captcha_handler=captcha_handler)
vk._auth_token()
api = vk.get_api()

id = "-182725650" #не трогать
buy = 0 #не трогать
n = 0
sila = int(2499999) #укажите максимальную силу пропуска

#########НЕ ТРОГАТЬ########
nov = 3765000000
buv = 376500000
opt = 37650000
vet = 3765000
ybi = 376500
chi = 37650
#########НЕ ТРОГАТЬ########

times = 1

while True:
	hod = 0
	while hod == 0:
		text = api.messages.getHistory(count = 1, peer_id = id)['items'][0]['text']
		moch = int(text.split('🔱 Сила бойцов: ')[-1].split('ед.')[0])
		a = sila-moch
		print('я в цикле разведки')
		if int(moch) <= 1000000: #меньше
			api.messages.send(peer_id=id, message=f'💀 Покинуть лабораторию', random_id=0, payload = json.dumps({"button":"2"}))
			n += 1
			print(f" #{n} | Текущая сила: {moch} | Надо пополнить: {a} ")
			hod = 1
			time.sleep(5)
		else: #больше
			for i in range(5):
				print(f" #{n} | Иду в разведку | ")
				api.messages.send(peer_id=id, message=f'🔥 Отправить бойцов на разведку', random_id=0, payload = json.dumps({"button":"3"}))
				n += 1
				time.sleep(3)
			api.messages.send(peer_id=id, message=f'🏃‍♂ Продолжить путь', random_id=0, payload = json.dumps({"button":"1"}))
			print(f" #{n} | Текущая сила: {moch} | Надо пополнить: {a} ")
			n += 1
			continue
	while hod == 1:
		print('я в цикле покупки')
		text = api.messages.getHistory(count = 1, peer_id = id)['items'][0]['text']
		if "👣 Вы отозвали бойцов из Лаборатории." in text:
			api.messages.send(peer_id=id, message=f'👥 Отправить бойцов ко входу в лаборатор…', random_id=0, payload = json.dumps({"button":"1"}))
			print(f" #{n} |  Иду в попополнение ")
			n += 1
		if "Отправить ко входу новичков ⏩ 🔱 1 ед." in text:
			api.messages.send(peer_id=id, message=f'👼 Отправить ко входу новичков ⏩ 🔱 1 ед.', random_id=0, payload = json.dumps({"button":"1"}))
			print(f" #{n} |  Выбрал для пополнения новичков ")
			n += 1
			buy = 1
		if "Отправь количество новичков, которое желаешь отправить в лабораторию" in text:
			api.messages.send(peer_id=id, message=f'{a}', random_id=0)#, payload = json.dumps({"button":"1"}))
			nov -= a
			print(f" #{n} |  Купил {a} новичков, осталось {nov} ")
			n += 1
		if "Отправить ко входу новичков ⏩ 🔱 1 ед." in text and buy == 1:
			api.messages.send(peer_id=id, message=f'⏪ Назад', random_id=0, payload = json.dumps({"button":"*"}))
			print(f" #{n} |  Возвращаюсь назад ")
			time.sleep(5)
			api.messages.send(peer_id=id, message=f'🌟 Открыть вход в лабораторию', random_id=0, payload = json.dumps({"button":"2"}))
			print(f" #{n} |  Продолжаю ")
			n += 1
			buy = 0
			hod = 0