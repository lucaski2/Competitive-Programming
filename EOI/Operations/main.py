for _ in range(int(input())):
  a, b = map(int, input().split())

  num1 = a * b
  num2 = a + b
  num3 = a - b
  if num1 >= num2 and num1 >= num3:
    print("*")
  elif num2 >= num1 and num2 >= num3:
    print("+")
  else:
    print("-")
