# uncompyle6 version 3.7.3
# Python bytecode 3.8 (3413)
# Decompiled from: Python 3.8.2 (default, Mar 13 2020, 10:14:16) 
# [GCC 9.3.0]
# Embedded file name: main.py
# Compiled at: 2020-07-17 11:59:49
# Size of source mod 2**32: 5102 bytes
# int = int
# bytes = bytes
# len = len
# range = range
# pow = pow
# zip = zip
# chr = chr
# 0 = 0
# 1 = 1
# 16 = 16
# 'little' = 'little'
# 'big' = 'big'

# every one is unique
sub1 = b'P\x1e\x05\xa3lQ)\x16B\x84\xe2\xc5\x13\xfbH\x9d\xd43(^\xed\x83\xff\x15\xc6\xbb\x06-k4UJ\xa8t\xb7\xa6\xb570%\x03\xe72\xe0\xe8\xef\xb3M@\xdc\x1fT=h$\x93K\x0e\x86\xa9\\\xb8\xe3\x89\x8f\xf4\xa5+\xf7\xcd\x9aC8Iqf\xfdED#\x0bj\x17\xe1z|:\x80S\xfe\xa1\xd8&\xf3\xd6\xec\xb2\xd3w\x04\xee\xa2\x9f,\x85\x02m\xba\x0c\x1a{9\xdd\xcen\xf8\xb1\x92\x8a\xcb\x8c\x12c\xda\xc7oAg\xd1\xe4\rL\x99\xf1\xfa<\xb6\xca\xcc\xde\xd5 \xa0\xae\x82\xa7\xf5\x9b?\xac\xc3\xbc\xc2\xeb\xf6>\xd0!\x1cb;]\xc0\xb4\x10d\x1daxr\x87\x8e\xeae\xab\x18\xe6O\xbdu\n6\t\x88~\x96\xb0\x07\x00\xd91"\x98\xe5\x94\xfcWy\'\xe9\x19\xaf\xc8\x8d/\xbev\xd7\xcf\x95iX[\x97\x7fZ_\xdf\xc9`\xf9\xadY\xf2VF\xa4\xaa\x81\xc4\x90p\x14*s\x08\x8bN\xbf\x9e\x91}\x11G\xdb.\x9c\xc1\x0f\x01\xb9\x1b\xf0\xd25R'

# goes up to 48
sub2 = b'\x1e\x13\x04\x03\x14)\t\x17\x12\x07\x0f\x08\x1a"-\x1d\'\x06\x01\r\x16\x10\x02*(\x00!\x11 .\x1b\x05\x18$/\x0b\x19\x1f\x1c+\x0c&#,\x15%\x0e\n'

def reverse(b):
    return int.to_bytes(int.from_bytes(b, 'little'), len(b), 'big')


def sub(b):
    return bytes((sub1[char] for char in b))


def shuffle(b):
    # Does nothing
    # b = reverse(b)
    # b = reverse(b)
    return bytes((b[char] for char in sub2))


def pad(b):
    return b + bytes([16 - len(b) % 16] * (16 - len(b) % 16))


def bigchunk(working):
    working = pad(working)
    initStr = working
    test = working
    counter = 0
    while True:
        # strbuild = sub(working)
        # strbuild = b''
        # for begin in range(0, len(working), 16):
        #     chunk = working[begin:begin + 16]
        #     chunk = sub(chunk)
        #     strbuild += chunk

        # print(strbuild == sub(working)) is true!
        # print(weirdSub(strbuild) == weirdSub(sub(working))) is true!
        # print(len(sub(working)))
        counter += 1

        test = sub(test)

        # if(counter == 53):
        #     print(initStr[3])
        #     print(initStr[3] == test[3])            
            # print(initStr[3] == test[3])            
        # if(test == initStr):
        #     print(f"{counter} sub complete")


        # shuffle: 380, sub: 140612491110
        # LCM of both is 5343274662180 
        working = shuffle(sub(working))
        # print(counter)
        if working == initStr:
            break

    return counter


str3 = b'\xa0},\x0c@\x0fn5\xfd\xe4\x9a\xc5X\xb9s|\x14E\xe2Z\x92\x9a\x89>\x9e\xaa\xf1\xad\x7f2_|\x97\xaf\xd2p\x99'
str4 = b'\xbe\xf5@\xddk"\x80cTH\x87iT\x0b\xa4\x15\x8fp\x8f\x14\x9b\xd1$d\x98\xac\x92\'\x13\x80\xdf[}SH\x9f\xac'
# converttedStr = int.to_bytes(pow(bigchunk(str3), 65537, 127314748520905380391777855525586135065716774604121015664758778084648831235208544136462397), len(str4), 'big')
converttedStr = int.to_bytes(pow(1781091554060, 65537, 127314748520905380391777855525586135065716774604121015664758778084648831235208544136462397), len(str4), 'big')


print(''.join((chr(a ^ b) for a, b in zip(str4, converttedStr))))

# okay decompiling ./main.pyc
