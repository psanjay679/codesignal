import string

digits = string.digits
letters = string.ascii_uppercase

mass = {
    'H' : 1,
    'C' : 14,
    'O' : 16
}

def find_mmas(expr):
    expr = expr[::-1]

    c_digits = list()
    total_sum = 0

    for c in expr:
        if c in digits:
            c_digits.append(int(c))

        elif c in mass:
            '''i left here coding...'''
            pass