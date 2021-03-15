#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

enum class State
{
  kEmpty,
  kObstacle
};

string CellState(State cell)
{
  switch (cell)
  {
  case State::kObstacle:
    return "⛰️ ";
  default:
    return "0 ";
  }
}

vector<State> ParseLine(string line)
{
  vector<State> row;
  istringstream sLine(line);

  int n;
  char c;

  while (sLine >> n >> c)
  {
    if (n == 0)
      row.push_back(State::kEmpty);
    else
      row.push_back(State::kObstacle);
  }

  return row;
}

vector<vector<State>> ReadBoardFile(string filename)
{
  vector<vector<State>> board{};
  ifstream infile;
  infile.open(filename);

  if (infile)
  {
    string line;

    while (getline(infile, line))
    {
      board.push_back(ParseLine(line));
    }
  }

  return board;
}

void PrintBoard(const vector<vector<State>> board)
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
      cout << CellState(board[i][j]);
    cout << endl;
  }
}

int main()
{
  PrintBoard(ReadBoardFile("1.board"));
}
