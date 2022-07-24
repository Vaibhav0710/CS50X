from cs50 import get_int
# ensure valid input; prompt user if h is <1 or >8
while True:
    h = get_int('height: ')
    if h < 1 or h > 8:
        h = get_int('height: ')
    if h >= 1 or h <= 8:
        break
# iterate through h
for i in range(h):
    print((h - 1 - i) * " ", end="")
    print((i + 1) * "#")