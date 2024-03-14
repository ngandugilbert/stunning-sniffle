#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct State
{
    int row;
    int col;
};

const int ROWS = 4;
const int COLS = 4;

int maze[ROWS][COLS] =
{
    {0, 1, 0, 1},
    {0, 1, 0, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 0}
};

// have a method that checks if it is a valid move
bool isValid(int _row, int _col)
{
    if (_row >= 0 && _row < ROWS && _col >= 0 && _col < COLS)
        return true;
    return false;
}

bool isValidPath(State _state)
{
    if (isValid(_state.row, _state.col) && maze[_state.row][_state.col] == 0)
    {
        return true;
    }
    return false;
}

bool hasState(State _state, stack<State> _List)
{
    while (!_List.empty())
    {
        if (_List.top().row == _state.row && _List.top().col == _state.col)
        {
            return true;
        }
        _List.pop();
    }
    return false;
}

vector<State> backtrack(int startRow, int startCol, int goalRow, int goalCol)
{
    stack<State> SL;
    stack<State> NSL;
    stack<State> DE;
    vector<State> pathTaken;
    State CS;


    State start = {startRow, startCol};
    // Initialize the lists
    SL.push(start);
    NSL.push(start);
    CS = start;

    while (!NSL.empty())
    {
        cout << "Current state: (" << CS.row << ", " << CS.col << ")" << endl;
        cout << "Stack SL: ";
        stack<State> tempSL = SL;
        while (!tempSL.empty())
        {
            State temp = tempSL.top();
            cout << "(" << temp.row << ", " << temp.col << ") ";
            tempSL.pop();
        }
        cout << endl;
        cout << "Stack NSL: ";
        stack<State> tempNSL = NSL;
        while (!tempNSL.empty())
        {
            State temp = tempNSL.top();
            cout << "(" << temp.row << ", " << temp.col << ") ";
            tempNSL.pop();
        }
        cout << endl;
        cout << "Stack DE: ";
        stack<State> tempDE = DE;
        while (!tempDE.empty())
        {
            State temp = tempDE.top();
            cout << "(" << temp.row << ", " << temp.col << ") ";
            tempDE.pop();
        }
        cout << endl;

        // check if the given state is the goal state
        if (CS.row == goalRow && CS.col == goalCol)
        {
            // this is the goal, return SL
            while (!SL.empty())
            {
                pathTaken.push_back(SL.top());
                SL.pop();
            }
            return pathTaken;
        }
        // check CS has no children
        if (!isValidPath({CS.row - 1, CS.col}) && !isValidPath({CS.row + 1, CS.col}) && !isValidPath({CS.row, CS.col - 1}) && !isValidPath({CS.row, CS.col + 1}))
        {
            cout << "This is a deadend" << endl;
            // this is a deadend
            while (!SL.empty() && SL.top().row == CS.row && SL.top().col == CS.col)
            {
                DE.push(CS);
                SL.pop();
                NSL.pop();
                if (!SL.empty())
                {
                    CS = SL.top();
                }
            }
            SL.push(CS);
        }
        else
        {
            // add children of CS
            cout << "Found some children" << endl;
            State children[] = {{CS.row - 1, CS.col}, {CS.row + 1, CS.col}, {CS.row, CS.col + 1}, {CS.row, CS.col - 1}};

            for (State child : children)
            {

                if (isValidPath(child))
                {
                    if (!hasState(child, DE) && !hasState(child, SL) && !hasState(child, NSL))
                    {
                        cout << "Adding child: (" << child.row << ", " << child.col << ")" << endl;
                        NSL.push(child);
                    }
                }
            }
            CS = NSL.top();
            SL.push(CS);
        }
    }

    return pathTaken;
}

// main function to test the algorithm
int main()
{
    int startRow = 0, startCol = 2;
    int goalRow = 3, goalCol = 3;

    vector<State> path = backtrack(startRow, startCol, goalRow, goalCol);
    if (!path.empty())
    {
        cout << "To move from (" << startRow << ", " << startCol << ") to (" << goalRow << ", " << goalCol << ")." << endl;
        cout << "Use Path: ";
        for (const State &state : path)
        {
            cout << "(" << state.row << ", " << state.col << ") ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path exists from (" << startRow << ", " << startCol << ") to (" << goalRow << ", " << goalCol << ")." << endl;
    }

    return 0;
}
