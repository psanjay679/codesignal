def if_rearrangable(ar):
    ans_s = list()
    s = list()

    s.append(ar[0])

    for i in range(1, len(ar)):
        while len(s) and ar[i] > s[-1]:
            ans_s.append(s.pop())

        s.append(ar[i])

    while(len(s)):
        ans_s.append(s.pop())

    return sorted(ans_s) == ans_s


def main():
    while int(raw_input()) != 0:
        ar = map(int, raw_input().split())
        print 'yes' if if_rearrangable(ar) else 'no'

if __name__ == '__main__':
    main()