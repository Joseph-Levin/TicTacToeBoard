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
