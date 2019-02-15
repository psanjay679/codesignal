def find_longest_valid_expr(expr):
    max_valid_expr = 0
    l_c, g_c = 0, 0

    for c in expr:
        if c == '<':
            l_c += 1
        else:
            if l_c > 0:
                l_c -= 1
                max_valid_expr += 2


    return max_valid_expr

def main():

    t = int(raw_input())

    for _ in range(t):
        expr = raw_input()
        print find_longest_valid_expr(expr)

if __name__ == '__main__':
    main()