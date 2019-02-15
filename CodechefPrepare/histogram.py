def largest_rect(ar):
    s = list()
    s.append(ar[0])
    max_area =1
    for i in range(1, len(ar[1:])):pass



def main():

    while True:
        ar = map(int, raw_input().split())
        if ar[0] == 0:
            break

        ar = ar[1:]
        print largest_rect(ar)




if __name__ == '__main__':
    main()