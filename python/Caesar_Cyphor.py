def enc(key,t):
	res=""
	for i in range (len(t)):
		c=t[i]
		if c.islower():
			res+= chr((ord(c) + key-97) % 26 + 97)

		if c.isupper():
			res+= chr((ord(c) + key-65) % 26 + 65)

	return res

key=int(input("Enter key"))
t=str(input("Enter msg"))

print(enc(key,t))