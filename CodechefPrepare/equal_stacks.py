import sys

n1, n2, n3 = map(int, raw_input().strip().split())

s1 = list(map(int, sys.stdin.readline().strip().split()))[::-1]
s2 = list(map(int, sys.stdin.readline().strip().split()))[::-1]
s3 = list(map(int, sys.stdin.readline().strip().split()))[::-1]

l1, l2, l3 = len(s1), len(s2), len(s3)


print s1
print s2
print s3

while len(s1) > min(l1, l2, l3):
    s1.pop()

while len(s2) > min(l1, l2, l3):
    s2.pop()

while len(s3) > min(l1, l2, l3):
    s3.pop()


print s1
print s2
print s3

print max(sum(s1), sum(s2), sum(s3))