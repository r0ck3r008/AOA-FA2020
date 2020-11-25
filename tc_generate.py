from random import randint
from sys import argv

rows = randint(1, int(argv[1]))  # mval
cols = randint(1, int(argv[1]))  # nval

uint16_max = 2**15
hval = randint(1, uint16_max)  # height

gridville = [[randint(1, uint16_max) for i in range(cols)] for i in range(rows)]

with open(argv[2], 'w') as f:
    f.write('{} {} {}\n'.format(rows, cols, hval))
    for i in range(rows):
        for j in range(cols):
            f.write('{}'.format(gridville[i][j]))
            if j<cols-1:
                f.write(' ')
        f.write('\n')
