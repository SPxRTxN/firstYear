from vk_api.longpoll import VkLongPoll, VkEventType
import vk_api
from datetime import datetime
import time
import random

login, password = "log", "pass"
vk_session = vk_api.VkApi(login, password)
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
                if response == "1":
                    vk_session.method('messages.send',{'user_id': event.user_id, 'message': 'hello', 'random_id':0})