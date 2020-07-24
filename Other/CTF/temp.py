#!/usr/bin/env python3
# requires pycryptodome
import base64
import hashlib
import os

from Crypto.Cipher import AES


class Cipher:
    def decrypt(self):
        ciphertext = "53rW_RiyUiwXq3PD7E4RHJuzjlHbw4YmG8wNRILXEQdBFiJZlpI2WjD_kNeQAUYG"
        ciphertext = self._pad(ciphertext)
        cipher = AES.new(self.key, AES.MODE_ECB)
        return base64.urlsafe_b64encode(cipher.decrypt(ciphertext))

    def __init__(self, key):
        i = os.urandom(1)[0] % 29
        self.key = base64.urlsafe_b64encode(
            hashlib.sha256(key).digest()[i:i + 3] * 8)

    def _pad(self, s):
        return s + (AES.block_size - len(s) % AES.block_size) * (AES.block_size - len(s) % AES.block_size).to_bytes(1, 'big')

    def encrypt(self, raw):
        raw = self._pad(raw)
        cipher = AES.new(self.key, AES.MODE_ECB) // object
        return base64.urlsafe_b64encode(cipher.encrypt(raw))


c = Cipher(os.urandom(256))
print(c.decrypt())
