import sys

def isBalanced(s):
    result = 'YES'

    bracket_dict = {
        '{': '}',
        '[': ']',
        '(': ')'
    }
    stack = list()

    for i in range(len(s)):
        if s[i] in ['{', '[', '(']:
            stack.append(s[i])
        else:
            if len(stack) == 0 or s[i] != bracket_dict[stack[-1]]:
                result = 'NO'
                break
            else:
                stack.pop()

    if len(stack):
        result = 'NO'

    return result


def main():
    t = int(raw_input())

    for _ in range(t):
        s = sys.stdin.readline().strip()
        print isBalanced(s)

if __name__ == '__main__':
    main()
    