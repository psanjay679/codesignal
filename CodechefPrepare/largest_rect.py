def find_largest_rectangle(ar):
    max_area = 0;

    for i in range(len(ar) - 1):
        min_value = ar[i]
        for j in range(i + 1, len(ar)):
            min_value = min(min_value, ar[j])
            max_area = max(max_area, (j - i + 1) * min_value)
    
    return max_area;


def main():
    _ = int(raw_input())
    ar = map(int, raw_input().split())
    print find_largest_rectangle(ar)


if __name__ == '__main__':
    main()
    