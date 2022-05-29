

def lucasNumber(number):
    sequence_of_numbers = []
    luc1, luc2 = 2, 1
    while (luc1 < number-1):
        sequence_of_numbers.append(luc1)
        luc1, luc2 = luc2, luc1 + luc2
    print(sequence_of_numbers)


lucasNumber(18)
