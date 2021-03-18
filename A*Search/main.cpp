#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// possible grid States
enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// Compare the F values of two nodes
bool Compare(vector<int> node_1, vector<int> node_2)
{
    return (node_1[2] + node_1[3]) > (node_2[2] + node_2[3]);
}

// check if cell is valid and empty
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
    bool x_on_grid = (x >= 0 && x < grid.size());
    bool y_on_grid = (y >= 0 && y < grid[0].size());
    bool cell_on_grid = (x_on_grid && y_on_grid);

    return (cell_on_grid && grid[x][y] == State::kEmpty);
}

// sort 2d vector in decending order
void CellSort(vector<vector<int>> *v)
{
    sort(v->begin(), v->end(), Compare);
}

// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

// add node to openlist and mark as open
void AddToOpenList(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid)
{
    vector<int> node{x, y, g, h};
    openlist.push_back(node);
    grid[x][y] = State::kClosed;
}

// expand currentnodes neighbours, add to openlist
void ExpandNeighbors(const vector<int> &current, vector<vector<int>> &openlist, vector<vector<State>> &grid, int goal[2])
{
    // TODO: Get current node's data.
    int x = current[0];
    int y = current[1];
    int g = current[2];

    // TODO: Loop through current node's potential neighbors.
    for (int i = 0; i < 4; i++)
    {
        // TODO: Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        // TODO: Increment g value, compute h value, and add neighbor to openlist.
        if (CheckValidCell(x2, y2, grid))
        {
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);
            AddToOpenList(x2, y2, g2, h2, openlist, grid);
        }
    }
}

// implement A* Search algorithim
vector<vector<State>> Search(vector<vector<State>> &grid, int init[2], int goal[2])
{
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);

    vector<vector<int>> openlist{};

    AddToOpenList(x, y, g, h, openlist, grid);

    while (openlist.size() > 0)
    {
        CellSort(&openlist);

        vector<int> current = openlist.back();
        openlist.pop_back();
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

        if (x == goal[0] && y == goal[1])
        {

            grid[init[0]][init[0]] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
            return grid;
        }

        ExpandNeighbors(current, openlist, grid, goal);
    }

    cout << "No path found!" << endl;
    return vector<vector<State>>{};
}

// create row (1d vector) from string
vector<State> ParseLine(string line)
{
    vector<State> row;
    istringstream sLine(line);

    int n;
    char c;

    while (sLine >> n >> c && c == ',')
    {
        if (n == 0)
            row.push_back(State::kEmpty);
        else
            row.push_back(State::kObstacle);
    }

    return row;
}

// takes filepath, creates 2d vector of grid
vector<vector<State>> ReadBoardFile(string filepath)
{
    ifstream infile(filepath);
    vector<vector<State>> board;

    if (infile)
    {
        string line;

        while (getline(infile, line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }

    return board;
}

string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️   ";
    case State::kPath:
        return "🚗   ";
    case State::kStart:
        return "🚦 ";
    case State::kFinish:
        return "🏁 ";
    default:
        return "0    ";
    }
}

// prints final grid solution to console
void PrintSolution(vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {

            cout << CellString(board[i][j]);
        }
        cout << endl;
    }
}

// run program
int main()
{
    auto board = ReadBoardFile("1.board");

    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto solution = Search(board, init, goal);

    PrintSolution(solution);
}
