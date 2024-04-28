#include<iostream>
#include<queue>

using namespace std;

// definition of a state
struct State
{
    int row;
    int col;
};
const int ROW = 4;
const int COL = 4;
// create a space
int maze[ROW][COL] =
{
    {0, 1, 1, 1},
    {0, 0, 0, 1},
    {0, 1, 0, 1},
    {1, 1, 0, 0}
};


// is state valid
bool isValid(State _state)
{
    if(_state.row >=0 && _state.row < ROW && _state.col >=0 && _state.col < COL)
        return true;
    return false;
}

bool isVisited(State _state, queue<State> _list)
{
    while(!_list.empty())
    {
        State temp;
        temp = _list.front();
        _list.pop();
        if(_state.row == temp.row && _state.col == temp.col)
        {
            return true;
        }
    }

    return false;
}

void breadthFirst(State _start, State _goal)
{
    queue<State> open;
    queue<State> closed;

    open.push(_start);

    while(!open.empty())
    {
        State X = open.front();
        open.pop();
        //check if this is the goal
        if(X.row == _goal.row && X.col == _goal.col)
        {
            cout<<"SUCCESS"<<endl;
            cout<<"GOAL IS:"<<X.row<<","<<X.col<<endl;
            break;
        }
        else
        {
            // generate children for X
            // The children are based on the rules of the game
            State MOVES[] = {{X.row, X.col -1}, {X.row,X.col + 1},{ X.row -1, X.col}, {X.row + 1, X.col}};
            queue<State> children;
            for(State possibleMove : MOVES)
            {
                if(isValid(possibleMove) && !isVisited(possibleMove, open) && !isVisited(possibleMove, closed))
                {
                    open.push(possibleMove);
                }
            }
            // put x on closed
            closed.push(X);
        }
    }
}

int main()
{

    int startRow = 0, startCol = 0;
    int goalRow = 3, goalCol = 3;

    breadthFirst({startRow, startCol}, {goalRow, goalCol});

    return 0;
}
