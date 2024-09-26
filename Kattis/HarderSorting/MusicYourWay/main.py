attributes = input().split()
songs = []
for i in range(int(input())):
    songs.append(input().split())

num_sorts = int(input())
order = []
for i in range(num_sorts):
    order.append(attributes.index(input()))



for sort in order:
    print(*attributes)
    songs.sort(key=lambda x: x[sort])
    for song in songs:
        print(*song)
    
    print()





