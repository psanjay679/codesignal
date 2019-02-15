import string
operators = ['+', '-', '*', '/', '^']
operands = string.ascii_lowercase

def convert_to_rev_polish(expr):
    chars, ops = list(), list()
    expr = expr[::-1]
    _c = ''
    for c in expr:
        if c in operands:
            chars.append(c)
        elif c in operators:
            ops.append(c)
        elif c == '(':
            c1 = chars.pop()
            c2 = chars.pop()
            op = ops.pop()
            _c = c1 + c2 + op
            chars.append(_c)

    return _c

def main():

    for _ in range(int(raw_input())):
        expr = raw_input().strip()
        print convert_to_rev_polish(expr)

if __name__ == '__main__':
    main()