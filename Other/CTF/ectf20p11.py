#!/usr/bin/env python3
# requires pycryptodome
import base64
import hashlib
import os

from Crypto.Cipher import AES


class Cipher:
    def __init__(self, key):
        i = os.urandom(1)[0] % 29
        self.key = base64.urlsafe_b64encode(
            hashlib.sha256(key).digest()[i:i + 3] * 8)

    def encrypt(self, raw):
        raw = self._pad(raw)
        cipher = AES.new(self.key, AES.MODE_ECB)
        return base64.urlsafe_b64encode(cipher.encrypt(raw))

    def _pad(self, s):
        return s + (AES.block_size - len(s) % AES.block_size) * (AES.block_size - len(s) % AES.block_size).to_bytes(1, 'big')

    def decrypt(self, key, hash):
        cipher = AES.new(key, AES.MODE_ECB)
        return cipher.decrypt(hash)


cipher = Cipher(os.urandom(256))


# with open('flag', 'rb') as f:
#     flag = f.read()

# print(f'Flag: {c.encrypt(flag).decode()}')
hashbytes = base64.urlsafe_b64decode("53rW_RiyUiwXq3PD7E4RHJuzjlHbw4YmG8wNRILXEQdBFiJZlpI2WjD_kNeQAUYG")


for a in range (0, 256):
    for b in range (0, 256):
        for c in range (0, 256):
            keyarr = bytes([a,b,c])

            key = base64.urlsafe_b64encode(keyarr * 8)
            # print(key.decode())
            try:
                flag = cipher.decrypt(key, hashbytes).decode()
                if "ctf{" in flag:
                    print(flag)
                    input("enter")
            except UnicodeDecodeError as e:
                something = 1

    print(f"a = {a}")



# test = "ctf{testing_testing123}"
# flag = c.encrypt(test).decode()
# print(f'Flag: {"ctf{" in c.decrypt("tes", hashbytes).decode()}')
