/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, toggleOnce)
{
    TicTacToeBoard b;
    Piece turn = b.toggleTurn();
	ASSERT_EQ(turn, O);
}

TEST(TicTacToeBoardTest, toggleTwice)
{
    TicTacToeBoard b;
    Piece turn = b.toggleTurn();
	ASSERT_EQ(turn, O);
    turn = b.toggleTurn();
	ASSERT_EQ(turn, X);

}

TEST(TicTacToeBoardTest, getBlankPiece)
{
    TicTacToeBoard b;
    Piece p = b.getPiece(0, 0);
    ASSERT_EQ(p, Blank);
}

TEST(TicTacToeBoardTest, badSmallRow)
{
    TicTacToeBoard b;
    Piece p = b.getPiece(-1, 0);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, badSmallCol)
{
    TicTacToeBoard b;
    Piece p = b.getPiece(0, -1);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, badBigRow)
{
    TicTacToeBoard b;
    Piece p = b.getPiece(3, 0);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, badBigCol)
{
    TicTacToeBoard b;
    Piece p = b.getPiece(0, 3);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, placePiece)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(0, 0);
    ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, placeTwoSame)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(0, 0);
    p = b.placePiece(0, 0);
    ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, placeTwo)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(0, 0);
    p = b.placePiece(0, 1);
    ASSERT_EQ(p, O);
}

TEST(TicTacToeBoardTest, placeThree)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(0, 0);
    p = b.placePiece(0, 1);
    p = b.placePiece(0, 2);
    ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, placeBadSmallRow)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(-1, 0);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, placeBadBigRow)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(3, 0);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, placeBadSmallCol)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(0, -1);
    ASSERT_EQ(p, Invalid);
}


TEST(TicTacToeBoardTest, placeBadBigCol)
{
    TicTacToeBoard b;
    Piece p = b.placePiece(0, 3);
    ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, gameNotFinished)
{
  TicTacToeBoard b;
  Piece p = b.getWinner();
  ASSERT_EQ(p, Invalid);
}

TEST(TicTacToeBoardTest, horizontalWinner)
{
  TicTacToeBoard b;
  b.placePiece(0, 0);
  b.placePiece(1, 1);
  b.placePiece(0, 1);
  b.placePiece(2, 2);
  b.placePiece(0, 2);
  Piece p = b.getWinner();
  ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, verticalWinner)
{
  TicTacToeBoard b;
  b.placePiece(0, 0);
  b.placePiece(1, 1);
  b.placePiece(1, 0);
  b.placePiece(2, 2);
  b.placePiece(2, 0);
  Piece p = b.getWinner();
  ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, diagonalOneWinner)
{
  TicTacToeBoard b;
  b.placePiece(0, 0);
  b.placePiece(1, 0);
  b.placePiece(1, 1);
  b.placePiece(2, 0);
  b.placePiece(2, 2);
  Piece p = b.getWinner();
  ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, diagonalTwoWinner)
{
  TicTacToeBoard b;
  b.placePiece(2, 0);
  b.placePiece(0, 0);
  b.placePiece(1, 1);
  b.placePiece(2, 2);
  b.placePiece(0, 2);
  Piece p = b.getWinner();
  ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, oIsWinner)
{
  TicTacToeBoard b;
  b.placePiece(1,0);
  b.placePiece(0, 0);
  b.placePiece(1,1);
  b.placePiece(0, 1);
  b.placePiece(2,1);
  b.placePiece(0, 2);
  Piece p = b.getWinner();
  ASSERT_EQ(p, O);
}

TEST(TicTacToeBoardTest, getWinnerNoWinner)
{
  TicTacToeBoard b;
  b.placePiece(0, 0);
  b.placePiece(0, 1);
  b.placePiece(0, 2);
  b.placePiece(1, 1);
  b.placePiece(1, 0);
  b.placePiece(1, 2);
  b.placePiece(2, 1);
  b.placePiece(2, 0);
  b.placePiece(2, 2);
  Piece p = b.getWinner();
  ASSERT_EQ(p, Blank);
}
