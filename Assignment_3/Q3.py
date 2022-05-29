def setList(*numbers):
    temp = list(numbers)
    mylist = list(dict.fromkeys(temp))
    return mylist


print(setList(1, 2, 3, 3, 4, 5))
