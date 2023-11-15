# TODO
from cs50 import get_string

while True:
    text = get_string("type tour text : ")
    if text != '':
        break
leters = 0
words=0
sentence = 0
for char in text:
    if char.isalpha():
        leters = leters +1

for char in text:
    if char == " ":
        words = words +1
words = words +1
for char in text:
    if (char == '.' or char == '!' or char == '?'):
        sentence = sentence +1


print(leters)
print(words)
print(sentence)

l = leters / words * 100
s = sentence / words * 100
index = (0.0588 * l) - (0.296 * s) - 15.8
if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+");
else:
    print(f"Grade ", round(index))