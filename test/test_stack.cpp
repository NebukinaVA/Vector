#include <gtest.h>
#include "Stack.h"


TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-5));
}

TEST(Stack, can_check_if_stack_is_empty)
{
	Stack<int> s;

	EXPECT_TRUE(s.empty());
}

TEST(Stack, can_push)
{
	Stack<int> s;

	ASSERT_NO_THROW(s.push(1));
}
TEST(Stack, can_pop)
{
	Stack<int> s;

	s.push(1);
	
	ASSERT_NO_THROW(s.pop());
}

TEST(Stack, throws_when_pop_from_empty_stack)
{
	Stack<int> s;

	ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_check_if_stack_is_full)
{
	Stack<int> s(3);

	s.push(1);
	s.push(2);
	s.push(3);

	EXPECT_TRUE(s.full());
}

TEST(Stack, copied_stack_is_equal_to_source_one)
{
	Stack<int> s1;
	Stack<int> s2(s1);

	EXPECT_EQ(s1, s2);
}

TEST(Stack, copied_stack_has_its_own_memory)
{
	Stack<int> s1;
	Stack<int> s2(s1);

	s2.push(1);

	EXPECT_NE(s1, s2);
}

TEST(Stack, can_repack_stack)
{
	Stack<int> s(3);

	s.push(1);
	s.push(2);
	s.push(3);

	ASSERT_NO_THROW(s.push(4));
}

TEST(Stack, compare_equal_stacks_return_true)
{
	Stack <int> s1(10), s2(10);

	s2 = s1;

	EXPECT_TRUE(s1 == s2);
}

TEST(Stack, compare_stack_with_itself_return_true)
{
	Vector <int> s(10);

	EXPECT_TRUE(s == s);
}

TEST(Stack, stacks_with_different_size_are_not_equal)
{
	Vector <int> s1(10), s2(20);

	EXPECT_TRUE(s1 != s2);
}