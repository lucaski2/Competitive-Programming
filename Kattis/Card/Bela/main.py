tableD = dict()
tableD['A'] = 11;
tableD['K'] = 4;
tableD['Q'] = 3;
tableD['J'] = 20;
tableD['T'] = 10;
tableD['9'] = 14;
tableD['8'] = 0;
tableD['7'] = 0;
tableND = dict()
tableND['A'] = 11;
tableND['K'] = 4;
tableND['Q'] = 3;
tableND['J'] = 2;
tableND['T'] = 10;
tableND['9'] = 0;
tableND['8'] = 0;
tableND['7'] = 0;

N, S = input().split(' ')
count = 0

for i in range(int(N) * 4):
    curr = list(input())
    if curr[1] == S:
        count += tableD[curr[0]]
    else:
        count += tableND[curr[0]]
print(count)

