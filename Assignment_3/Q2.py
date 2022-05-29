from msilib import sequence


def lucasNumberLoop(number):
    sequence_of_numbers = []
    luc1, luc2 = 2, 1
    for i in range(number):
        sequence_of_numbers.append(luc1)
        luc1, luc2 = luc2, luc1 + luc2
    print(sequence_of_numbers, "Generated with loop")


# lucasNumberLoop(8)


def lucasNumberGenerator(n):
    luc1, luc2 = 2, 1
    for i in range(n):
        yield luc1
        luc1, luc2 = luc2, luc1 + luc2


print(list(lucasNumberGenerator(8)), "Generated with the generator function")
