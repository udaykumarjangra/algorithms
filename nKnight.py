from datetime import datetime

class Nknight:
    #INITIALIZE ROWS, COLUMN TO FORM A CHESS BOARD
    def __init__(self, matrix_size):
        self.matrix_row = matrix_size
        self.matrix_column = matrix_size
        self.chess_board = []
        self.init_chess_board()

    def init_chess_board(self):
        for i in range(self.matrix_column):
            self.chess_board.append([0]*self.matrix_row)
    #PRINT THE CHESS BOARD (USED TO SHOW FROM WHERE THE KNIGHT HAS STARTED AND THAT HAS VISITED ALL THE POSITIONS)
    def show(self):
        print()
        print("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
        for i in self.chess_board:
            print(i)
        print("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
        print()
    #GET THE POSSIBLE VALID MOVES FOR A KNIGHT AT CURRENT POSITION
    def valid_moves(self, curr):
        possible_moves = []
        move_x_y = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]
        for move in move_x_y:
            pos_x = curr[0] + move[0]
            pos_y = curr[1] + move[1]

            if (pos_x >= self.matrix_column):
                continue
            elif (pos_x < 0):
                continue
            elif (pos_y >= self.matrix_row):
                continue
            elif (pos_y < 0):
                continue
            else:
                possible_moves.append((pos_x, pos_y))

        return possible_moves
    #TRAVERSING FROM EDGE NEIGHBOURS TO INSIDE AS LATER IT BECOMES DIFFICULT TO GO OUTSIDE
    def edge_neighbours(self, start):

        neighbour_list = self.valid_moves(start) #GET THE NEIGHBOURS/POSSIBLE MOVES WHERE IT CAN VISIT FROM THE START POINT
        unvisited_neighbours = []
        #GET THE UNVISITED NEIGHBOURS
        for neighbour in neighbour_list:
            value = self.chess_board[neighbour[0]][neighbour[1]]
            if value == 0:
                unvisited_neighbours.append(neighbour)
        #POINT LIST HOLDS THE NUMBER CORRESPONDING TO THE POSITION
        point_list = []
        for position in unvisited_neighbours:
            point = [position, 0]
            moves = self.valid_moves(position)
            for m in moves:
                if self.chess_board[m[0]][m[1]] == 0:
                    point[1] += 1
            point_list.append(point)
        #SORT THE LIST ACCORDING TO NUMBER
        sorted_visited_positions = sorted(point_list, key = lambda p: p[1])
        #GET THE VISITED PATH
        sorted_visited = [p[0] for p in sorted_visited_positions]
        return sorted_visited

    def knight(self, position_num, path, start):

        self.chess_board[start[0]][start[1]] = position_num
        # APPEND THE NEWEST VERTEX TO THE CURRENT PATH
        path.append(start)
        print("Visiting: ", start)
        # IF EVERY CELL IS FILLED
        if position_num == self.matrix_row * self.matrix_column:
            self.show()
            print(path)
            print("Every Position Visited Successfully in the path shown above!")
            exit(1)

        else:
            sorted_neighbours = self.edge_neighbours(start)
            #CHECK FOR THE UNVISITED NEIGHBOURS AND ADD TO PATH
            for neighbour in sorted_neighbours:
                self.knight(position_num+1, path, neighbour)

            #RESET,THE STARTING POINT SO THE LOOP DOES NOT GETS EXIT UNTIL ALL HAVE BEEN VISITED
            self.chess_board[start[0]][start[1]] = 0

            #BACKTRACK
            try:
                path.pop()
                print("Going back to: ", path[-1])
            except IndexError:
                exit(1)


n = int(input('Enter the size of the chess board n: '))
k = Nknight(n)
a = int(input('Enter the X coordinate of Starting Point:'))
b = int(input('Enter the Y coordinate of Starting Point:'))
start = datetime.now()
k.knight(1, [], (a,b))
k.show()
end = datetime.now()
print(f"Time Taken by program : {end - start}")
