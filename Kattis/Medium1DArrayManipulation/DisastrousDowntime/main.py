from math import ceil, floor
from queue import Queue
num_requests, server_space = list(map(int, input().split(' ')))
requests = [int(input()) for _ in range(num_requests)]

start = min(requests)
end = max(requests)
currently_running = 0
currently_running_requests_keys = Queue()
currently_running_requests_values = Queue()
highest = 0

requests_dict = {}
current_ind = 0


#go through all of the requests and make them into a dictionary
for request in requests:
    if request not in requests_dict:
        requests_dict[request] = 1
    else:
        requests_dict[request] += 1



request_dict_values = list(requests_dict.values())
request_dict_keys = list(requests_dict.keys())


for i in range(start, end + 1):


    if currently_running_requests_keys.qsize():

        if i == currently_running_requests_keys.queue[0]:
            currently_running_requests_keys.get()
            currently_running -= currently_running_requests_values.get()

    if i == request_dict_keys[current_ind]:
        currently_running += request_dict_values[current_ind]
        currently_running_requests_keys.put(i + 1000)
        currently_running_requests_values.put(request_dict_values[current_ind])
        current_ind += 1
        if currently_running > highest:
            highest = currently_running



    
    if current_ind >= num_requests:
        break
    

print(ceil(highest / server_space))