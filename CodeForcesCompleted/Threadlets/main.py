
for asdf in range(int(input())):
    things = list(map(int, input().split()))


    for i in range(3):
        if len(set(things)) == 1:
            print("YES")
            break

        largest = max(things)
        things.remove(largest)
        things.append(min(things))
        things.append(largest - min(things))
    else:

        if len(set(things)) != 1:
            print("NO")
        else:
            print("YES")





