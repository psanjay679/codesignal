def make_sieve():
    n = 5 * (10 ** 4)
    ar = [True] * (n + 1)
    p = 2
    sieve = list()
    while (p * p <= n):
        if ar[p] == True:
            for i in range(p * p, n + 1, p):
                ar[i] = False
        p += 1

    for i in range(2, n):
        if ar[i] is True:
            sieve.append(i)
    return sieve


def main():
    sieve = make_sieve()

    # print '*****Sieve Created*****'

    N, Q = map(int, raw_input().split())

    ar = map(int, raw_input().split())
    B = list()

    for i in range(Q):

        # print 'sieve[%d] = %d' % (i, sieve[i])
        temp_stack = list()

        while len(ar):
            if ar[-1] % sieve[i] == 0:
                B.append(ar.pop())
            else:
                temp_stack.append(ar.pop())

        while temp_stack:
            ar.append(temp_stack.pop())

        # print ar

        while B:
            print B.pop()

    while ar:
        print ar.pop()

if __name__ == '__main__':
    main()