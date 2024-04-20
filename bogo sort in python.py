import random

def is_sorted(lst):
    return all(lst[i] <= lst[i+1] for i in range(len(lst)-1))

def bogosort(lst):
    while not is_sorted(lst):
        random.shuffle(lst)
    return lst

# Input from the user
input_str = input("Enter numbers separated by spaces: ")
input_list = [int(x) for x in input_str.split()]

sorted_list = bogosort(input_list)
print("Sorted list:", sorted_list)
