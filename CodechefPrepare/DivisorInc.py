from __future__ import print_function
while True:
    N = int(raw_input())
    M = int(raw_input())

    count = 0
    while N < M:
        divisor = 2
        for i in range(2, N/2 + 1):
            if N % i == 0 and N + (N / i) <= M:
                divisor = N / i
                break

        print ("%d->" % N, end="")
        N += divisor
        count += 1

    print(N)

    if N == M:
        print (count)
    else:
        print (-1)