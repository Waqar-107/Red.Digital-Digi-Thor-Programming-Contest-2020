# from dust i have come, dust i will be

t = int(input())

case = 1
while t:
    t -= 1

    n = int(input())
    x = n // 5

    summation = (n * (n + 1)) // 2
    summation2 = (x * (x + 1)) // 2

    ans = "Case " + str(case) + ": " + str(summation - 5 * summation2)
    print(ans)
    case += 1
