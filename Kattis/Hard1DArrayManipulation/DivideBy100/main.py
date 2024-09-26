inp1 = input()
inp2 = input()

# get the amount of decimal places that should be shifted based on input 2

decimal_places = len(inp2) - 1
# print format with inp1 with a dot where the decimal_places says it should be

end_string = list(inp1)

if len(end_string) < decimal_places:
    end_string = ["0" * (decimal_places - len(end_string)) + "".join(end_string)]

end_string.insert(len(end_string) - decimal_places, ".")

while end_string[-1] == "0" or end_string[-1] == ".":
    if (end_string[-1] == "."):
        end_string.pop()
        break
    end_string.pop()

if (end_string[0] == "."):
    end_string.insert(0, "0")


print("".join(end_string))

