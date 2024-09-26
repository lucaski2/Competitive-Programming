N, Q = list(map(int, input().split()))

closing_times = list(map(int, input().split()))
visiting_times = list(map(int, input().split()))
all_times = [(closing_times[i], visiting_times[i]) for i in range(len(closing_times))]
all_times.sort(key=lambda x: x[0])



for i in range(Q):
    wakeup_time, visits = list(map(int, input().split()))

    for i in all_times:
        if (i[0] >= i[1] + wakeup_time) and i[1] >= wakeup_time:
            visits -= 1
    
        if visits <= 0:
            print("YES")
            break
    else:
        print(visits)
        print("NO")



