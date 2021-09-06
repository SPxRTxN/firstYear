from vk_api import VkApi
from vk_api.longpoll import VkLongPoll, VkEventType
import vk_api
from datetime import datetime
import time
time.time()
import random
random.random ()
# import get_pictures


login, password = "log", "pass"
vk_session: VkApi = vk_api.VkApi(login, password)
vk_session.auth()

session_api = vk_session.get_api()
longpoll = VkLongPoll(vk_session)

while True:
    for event in longpoll.listen():
        if event.type ==VkEventType.MESSAGE_NEW:
            print("Пришло в:" + str(datetime.strftime(datetime.now(), "%H:%M:%S")))
            print("Сообщение:" + str(event.text))
            print(event.user_id)
            response = event.text.lower()
            if event.from_user and not (event.from_me):
                if response == "люблю":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'и я тебя', 'random_id':0})
                elif response == "привет":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'Привет)', 'random_id':0})
                elif response == "ты чего?":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'Ничего', 'random_id':0})
                elif response == "говорить или нет":
                    vk_session.method('messages.send', {'user_id': event.user_id, 'message': 'Говори', 'random_id': 0})
                elif response == "как дела?":
                    vk_session.method('messages.send', {'user_id': event.user_id, 'message': 'Отлично)', 'random_id': 0})
                elif response == "что делаешь?":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'особо ничего', 'random_id':0})
                elif response == "тут справедливо":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'Естественно', 'random_id':0})
                # elif response == "котики":
                #     attachment = get_pictures.get(vk_session, -130670107, session_api)
                #     vk_session.method('messages.send',
                #                       {'user_id': event.user_id, 'message': 'Держи котиков!', 'random_id': 0,
                #                        "attachment": attachment})
            if event.from_me:
                if response == "она сказала":
                    vk_session.method('messages.send', {'user_id': event.user_id, 'message': 'Заебись', 'random_id': 0})
                elif response == "пахомова":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'В рот она ебись', 'random_id':0})
