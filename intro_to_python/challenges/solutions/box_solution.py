# box_solution.py

# Hint: area = 2*depth*width + 2*depth*height + 2*width*height
# Hint: volume = width*height*depth

def get_size(w,h,d):
    '''This function calculates the
    surface area and volume of any
    given box of width "w", height
    "h", and depth "d".'''

    area = (2*d*w) + (2*d*h) + (2*w*h)
    vol = w*h*d

    box_list = [area,vol]

    return box_list

# Test the get_size function for a couple box sizes
box_1 = get_size(w=1, h=1, d=1)
box_2 = get_size(w=4, h=2, d=6)

# Check to see if you are correct
print('Area and volume of 1x1x1 box: ', box_1)
print('Area and volume of 4x2x6 box: ', box_2)

if (box_1 == [6,1]) and (box_2 == [88,48]):
    print('Success!')
else:
    print('Try again!')
    print('You should get [6,1] and [88,48]')
