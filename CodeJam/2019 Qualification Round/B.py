T = int(input())

for test_case in range(1, T+1):
    n = int(input())
    path1 = input()
    path2 = ''.join([chr(ord(ch)^ord('E')^ord('S')) for ch in path1])
    print("Case #{0}: {1}".format(test_case, path2))
    