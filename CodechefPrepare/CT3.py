

def max_count(ar, count):
    # print ar
    # print count
    if len(ar) == 0: return 0;
    elif len(ar) == 1: return ar[0]

    # print "left: {} right: {} ar[left:right]: {}".format(left, right, ar[left:right])
    max_index = ar.index(max(ar))
    # print ar[left:right]
    # print "max_value: {}".format(ar[max_index])
    # print "ar: {}".format(ar[left:right])
    # print "next_left_arr: {}".format(ar[:max_index - 1])
    # print "next_right_arr: {}".format(ar[max_index + 2:])
    print "ar[max_index]: {}".format(ar[max_index])
    # count += ar[max_index]
    count += max_count(ar[:max_index - 1], count)
    count += max_count(ar[max_index + 1:], count)

    return count


def main():
    ar = [6, 7, 1, 3, 8, 2, 4]
    # ar = [5, 3, 4, 11, 2]
    print max_count(ar, 0)


if __name__ == '__main__':
    main()