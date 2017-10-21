"""
Author: Ian Davidson
Assignment: Lab01 part 2
Overview: program that reads 10 integers, finds sum, average of ints, and sorts the integers into ascending order.
"""
def main():

    print("Please enter 10 integer values.")
    print("Each value should be entered on a separate line: ")

    inputList = []
    counter = 0

    while (counter != 10):

        counter += 1
        inputList.append(int(input()))

    print("The values you entered are: ")
    print(inputList)

    sum = 0
    for i in range (10):
        sum += inputList[i]


    print("The total of your values is: ", sum)

    avg = sum/10

    print("The average of your values is: ", avg)

    inputList.sort(key=int)

    print("The sorted values are: ")
    print(inputList)


main()