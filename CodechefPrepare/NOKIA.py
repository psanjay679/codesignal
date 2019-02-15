def count_length(left, right, count):

    # print "left: {} right: {} count: {}".format(left, right, count)
    print "left: {} right: {}".format(left, right)

    # count += right - left
    if (right - left) < 2:
        return right - left
        # return 2

    mid = left + (right - left) / 2
    count += count_length(left, mid, count)
    count += count_length(mid, right, count)

    return count

# for _ in range(int(raw_input())):
for _ in range(1):
    # N = int(raw_input())
    N = 5
    print count_length(0, N + 1, 0)