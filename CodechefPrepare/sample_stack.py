import random

x = [random.randint(1, 100) for _ in range(10)]
y = list()

while len(x):
    y.append(x.pop())

print y
print x