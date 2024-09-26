is_reversed = int(input()) % 2 != 0

pre_deletion = input()
post_deletion = input()


if is_reversed:
    #turn all 0's into 1's and vice versa
    correct_deletion = ""
    for i in range(len(pre_deletion)):
        if pre_deletion[i] == "0":
            correct_deletion += "1"
        else:
            correct_deletion += "0"
    if correct_deletion == post_deletion:
        print("Deletion succeeded")
    else:
        print("Deletion failed")

else:
    if pre_deletion == post_deletion:
        print("Deletion succeeded")
    else:
        print("Deletion failed")