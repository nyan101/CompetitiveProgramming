T = int(input())

for test_case in range(1, T+1):
    num = input()
    num1 = ''
    num2 = ''
    
    for d in num:
        if d == '4' or d == '5':
            num1 += chr(ord(d) - 2)
            num2 += '2'
        else:
            num1 += d
            num2 += '0'
    
    num1 = int(num1)
    num2 = int(num2)
    num1 -= 1
    num2 += 1
    print("Case #{0}: {1} {2}".format(test_case, num1, num2))