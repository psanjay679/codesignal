def main():
    t = int(raw_input().strip())

    operations = list()
    s = list()
    for _ in range(t):
        line = raw_input().split()
        # print line
        x = int(line[0])

        if x < 3:
            operations.append([x, None])
        if x == 1:
            y = list(line[1])
            s += y
            operations[-1][1] = list(y)
            # print 's in x==1:', s
        elif x == 2:
            y = int(line[1])
            operations[-1][1] = []
            while y > 0:
                operations[-1][1].append(s.pop())
                y -= 1
        elif x == 3:
            y = int(line[1])
            # print 's:', s
            # print 'y:', y
            print s[y-1]
        elif x == 4:
            if operations[-1][0] == 1:
                l = len(operations[-1][1])
                while l > 0:
                    s.pop()
                    l -= 1
            elif operations[-1][0] == 2:
                s += operations[-1][1][::-1]
            
            operations.pop()


def main1():
    t = int(raw_input())

    operations = list()
    s = [None] * 10**6

    index = 0
    for _ in range(t):
        line = raw_input().split()
        x = int(line[0])

        if x < 3:
            operations.append([x, None])
            if x == 1:
                string = line[1].split()
                for i in range(len(string)):
                    s[index + i] = string[i]

                index += len(string) - 1

if __name__ == '__main__':
    main()
    