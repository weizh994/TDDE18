#include "assignment2.h"
#include <cmath>
#include <iostream>
#include <vector>

chess::chess(int a, int b) : file{a}, rank{b}
{
}
bool chess::isValid(int nf, int nr) const { return (nf < 1 || nr < 1 || nf > 8 || nr > 8); }

pawn::pawn(int a, int b) : chess{a, b}, Move{true}
{
}
pawn::~pawn() { delete this; }
bool pawn::isValid(int nf, int nr) const
{
  if (nf < 1 || nr < 1 || nf > 8 || nr > 8)
  {
    return false;
  }
  else if (file != nf)
  {
    return false;
  }
  else if (abs(nr - rank) == 1)
  {
    return true;
  }
  else if (abs(nr - rank) == 2 && Move)
  {
    return true;
  }
  else
    return false;
}
void pawn::move(int nf, int nr)
{
  if (isValid(nf, nr))
  {
    if (Move)
    {
      Move = false;
    }
    file = nf;
    rank = nr;
  }
  else
  {
    std::cerr << "Movement is unvalid!\n";
  }
}

rook::rook(int a, int b) : chess{a, b} {}
rook::~rook() { delete this; }
bool rook::isValid(int nf, int nr) const
{
  if (nf < 1 || nr < 1 || nf > 8 || nr > 8)
  {
    return false;
  }
  else if (file == nf || rank == nr)
  {
    return true;
  }
  else
    return false;
}
void rook::move(int nf, int nr)
{
  if (isValid(nf, nr))
  {
    file = nf;
    rank = nr;
  }
  else
  {
    std::cerr << "Movement is unvalid!\n";
  }
}

queen::queen(int a, int b) : chess{a, b} {}
queen::~queen() { delete this; }
bool queen::isValid(int nf, int nr) const
{
  if (nf < 1 || nr < 1 || nf > 8 || nr > 8)
  {
    return false;
  }
  else if (file == nf || rank == nr)
  {
    return true;
  }
  else if ((nf - file) == (nr - rank))
  {
    return true;
  }
  else
    return false;
}
void queen::move(int nf, int nr)
{
  if (isValid(nf, nr))
  {
    file = nf;
    rank = nr;
  }
  else
  {
    std::cerr << "Movement is unvalid!\n";
  }
}
int main()
{
  std::vector<chess *> board;
  board.push_back(new queen(4, 5));
  board[0]->move(4, 6);
  delete board[0];
  return 0;
}