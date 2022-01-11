# for_loop_range.py


# iterate from 0 through 10 (exclude 10) in steps of 1
print( 'Example 6.1: range(0,10,1)' )

for i in range(0,10,1):
    print(i)


# iterate from 0 through 10 (exclude 10) in steps of 2
print(' ')
print( 'Example 6.2: range(0,10,2)' )

for i in range(0,10,2):
    print(i)


# if only supplying one number, it will iterate up to that number
print(' ')
print( 'Example 6.3: range(4)' )

for i in range(4):
    print(i)
    

# iterate over a list using its length and indexing
print(' ')
print( 'Example 6.4: range(length_x)' )

x = ['O','L','C','F']
length_x = len(x)
for i in range(length_x):
    print(x[i])
