def gcd(a, b):
    while(a%b!=0):
        a, b = b, a%b
    return b

T = int(input())

for test_case in range(1, T+1):
    N, L = map(int, input().split())
    code = list(map(int, input().split()))
    msg  = []
    pset = set()
    idx = 0
    while(code[idx]==code[idx+1]):
        idx += 1

    p = code[idx] // gcd(code[idx], code[idx+1])
    for i in range(idx)[::-1]:
        p = code[i]//p
        pset.add(p)
        msg.append(p)
    msg.reverse()
    
    p = code[idx] // gcd(code[idx], code[idx+1])
    pset.add(p)
    msg.append(p)
    for i in range(idx, L):
        p = code[i]//p
        pset.add(p)
        msg.append(p)

    plist = sorted(list(pset))
    pdict = {plist[i] : chr(ord('A')+i) for i in range(26)}

    ans = ''.join([pdict[ch] for ch in msg])

    print("Case #{0}: {1}".format(test_case, ans))
