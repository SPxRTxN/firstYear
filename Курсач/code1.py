import os
import sys
import time
import multiprocessing
import hashlib
import binascii
import itertools

MATRIX_SIZE = [3,3]
MAX_LEN = MATRIX_SIZE[0]*MATRIX_SIZE[1]
MIN_POSITIONS_NUMBER = 3
FOUND = multiprocessing.Event()

def lookup(param):
    global FOUND
    lenhash = param[0]
    target = param[1]
    positions = param[2]

    if FOUND.is_set() is True:
        return None

    # все возможные перестановки
    perms = itertools.permutations(positions, lenhash)
    # для каждой перестановки
    for item in perms:
        #создание строкового шаблона
        if FOUND.is_set() is True:
            return None
        pattern = ''.join(str(v) for v in item)
        # перевод строки в 16-ричную систему (строка '123' переводится в '\x01\x02\x03')
        key = binascii.unhexlify(''.join('%02x' % (ord(c) - ord('0')) for c in pattern))
        # вычисление хэша для ключа
        sha1 = hashlib.sha1(key).hexdigest()
        # шаблон найден
        if sha1 == target:
            FOUND.set()
            return pattern
    # шаблон не найден
    return None

def show_pattern(pattern):
    """
    Графическое представление в видде матрицы
    """

    gesture = [None, None, None, None, None, None, None, None, None]

    cont = 1
    for i in pattern:
        gesture[int(i)] = cont
        cont += 1

    print ("[+] Gesture:\n")
    for i in range(0, 3):
        val = [None, None, None]
        for j in range(0, 3):
            val[j] = " " if gesture[i * 3 + j] is None else str(gesture[i * 3 + j])

        print ('  -----  -----  -----')
        print ('  | %s |  | %s |  | %s |  ' % (val[0], val[1], val[2]))
        print ('  -----  -----  -----')

def crack(target_hash):
    ncores = multiprocessing.cpu_count() #получение данных о количестве процессов 
    pool = multiprocessing.Pool(ncores) #управление пулом задач от количества процессов
    #генерируем идентификаторы позиций матрицы
    positions = [i for i in range(MAX_LEN)]
    
    # устанавливаем длинну для каждого процесса
    generate_worker_params = lambda x: [x, target_hash, positions]
    params = [generate_worker_params(i) for i in range(MIN_POSITIONS_NUMBER, MAX_LEN + 1)]
    
    result = pool.map(lookup,params)#применяем функцию lookup для всех параметров
    pool.close()
    pool.join()
    
    ret = None
    for r in result:
        if r is not None:
            ret = r
            break
    return ret

def main():
    # проверка входных параметров
    if len(sys.argv) != 2:
        print ('[+] Usage: %s /gesture.key\n' % sys.argv[0])
        sys.exit(0)
    
    # проверка файла gesture.key 
    if not os.path.isfile(sys.argv[1]):
        print ("[e] Cannot access to %s file\n" % sys.argv[1])
        sys.exit(-1)
        
    # считываем SHA1 в файл
    f = open(sys.argv[1], 'rb')
    gest = f.read(hashlib.sha1().digest_size).encode('hex')
    f.close()

    # проверка длинны хэша
    if len(gest) / 2 != hashlib.sha1().digest_size:
        print ("[e] Invalid gesture file?\n")
        sys.exit(-2)

    # вывод времени для подбора пароля
    t0 = time.time()
    pattern = crack(gest)
    t1 = time.time()

    if pattern is None:
        print ("[:(] The pattern was not found...")
        rcode = -1
    else:
        print ("[:D] The pattern has been FOUND!!! => %s\n" % pattern)
        show_pattern(pattern)
        print ("")
        print ("It took: %.4f seconds" % (t1-t0))
        rcode = 0

    sys.exit(rcode)

if __name__ == "__main__":
    main()