#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

class chess
{

protected:
  int file;
  int rank;

public:
  chess(int a = 0, int b = 0);
  virtual ~chess() = default;
  virtual bool isValid(int nf, int nr) const;
  virtual void move(int nf, int nr) = 0;
};
class pawn : public chess
{
private:
  bool Move;

public:
  pawn(int a = 0, int b = 0);
  ~pawn() override;
  bool isValid(int nf, int nr) const override;
  void move(int nf, int nr) override;
};

class rook : public chess
{
public:
  rook(int a = 0, int b = 0);
  ~rook() override;
  bool isValid(int nf, int nr) const override;
  void move(int nf, int nr) override;
};

class queen : public chess
{
public:
  queen(int a = 0, int b = 0);
  ~queen() override;
  bool isValid(int nf, int nr) const override;
  void move(int nf, int nr) override;
};

#endif