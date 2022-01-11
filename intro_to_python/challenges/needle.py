# needle.py

# Hint: Use dummy_index to track iterations of the loop

def find_needle(haystack):
    '''This function iterates through a list
    to find the "needle" string. The function
    then returns the index (position) in the
    list where it found "needle".'''

    dummy_index = 0
    for entry in haystack:
        #TO-DO

    return #TO-DO

# Create a couple "haystack" lists to be searched through and tested
hay_list_1 = ['283497238987234', 'a dog', 'a cat',     \
                 'some random junk', 'a piece of hay', \
                 'needle', 'something somebody lost a while ago']

hay_list_2 = ['Python is cooler than C++', 'needle',    \
              'Fortran is also cool', 'blah', 'summit', \
              'rhea', 'andes', 'titan']

# Call the find_needle function, set result to a variable
needle_pos_1 = find_needle(hay_list_1)
needle_pos_2 = find_needle(hay_list_2)

# Check to see if you are correct
print('Found the needle in the 1st haystack at position', needle_pos_1)
print('Found the needle in the 2nd haystack at position', needle_pos_2)

if (needle_pos_1 == 5) and (needle_pos_2 == 1):
    print('Success!')
else:
    print('Try again!')
    print('You should find them at position 5 and position 1')
