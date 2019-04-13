T, N, M = map(int, input().split())

MOD = 8*9*5*7*11*13*17
mod = [8, 9, 5, 7, 11, 13, 17]
phi = [4, 6, 4, 6, 10, 12, 16]
rem = [0, 0, 0, 0,  0,  0,  0]
pinv = [pow(MOD//mod[i], phi[i], MOD) for i in range(7)]

for test_case in range(1, T+1):
    for i in range(7):
        ss_in = (str(mod[i])+' ') * 18
        print(ss_in)

        ss_out = map(int, input().split())
        rem[i] = sum(ss_out) % mod[i]

    ans = sum([pinv[i]*rem[i] for i in range(7)]) % MOD

    print(ans)
    res = input()
