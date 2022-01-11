# sheep_solution.py

# Hint: In Python, "True" equals 1 and "False" equals 0
# Hint: You will need to use indexing

def count_sheeps(sheep):
    '''This function loops over the entire sheep
    array and adds up all the values'''

    size_sheep = len(sheep)
    count = 0
    for i in range(0, size_sheep):
        count = count + sheep[i]

    return count

# Our flock of "sheep" list
flock = [True,  True,  True,  False, \
          True,  True,  True,  True , \
          True,  False, True,  False, \
          True,  False, False, True , \
          True,  True,  True,  True , \
          False, False, True,  True ]

# Call the count_sheeps function
flock_count = count_sheeps(flock)

# Check to see if you are correct
print("You counted this many sheep: ", flock_count)

if flock_count == 17:
    print("There are 17 sheep! Success!")
else:
    print("Try again!")
    print("The sheep count should be 17")
