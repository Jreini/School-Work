def fill_matrix(matrix,rows):
    for row in range(rows):
        matrix.append(list(input()))
def print_matrix(matrix):
    for row in matrix:
        print(''.join(row))
    print()
def find_Start(matrix,rows):
    for n in matrix:
        if n=='N':
            

def valid_move(matrix, row, col, direction):
    '''
    used for determining if the current move is valid,
    Note: checks AHEAD in direction if move is ok
          (not row col itself, but the next move)
    return True if move is valid False otherwise
    '''


def at_end(matrix, row, col):
    '''
    used for determining if Noibe is at the exit,
    return True if at the exit False otherwise
    '''


def find_exit(matrix, row, col):

def main():
    matrix=[]
    rows=input()
    while rows!=0:
        matrix=fill_matrix(matrix,rows)

    

# Do NOT edit below this line:
if __name__ == '__main__':
    main()


