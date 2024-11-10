# ITC = Lqwurgxfwlrq wr Frpsxwhu Vflhqfh
# FOP = Ixqgdphqwdov ri Surjudpplqj

plaintext = input("Enter plaintext: ")
plaintext_len = len(plaintext)
ciphertext = ""
key = 3

for i in range(plaintext_len):
    
    if plaintext[i].isalpha():

        char = chr(ord(plaintext[i]) + key)
        ciphertext += char

    else:
        ciphertext += plaintext[i]

print("Ciphertext:", ciphertext)
