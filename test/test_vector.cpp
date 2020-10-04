#include <gtest.h>
#include "Vector.h"

TEST(Vector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, can_compare_vectors)
{
	Vector<int> v1(5);
	Vector<int> v2(5);
	v1.push_back(1);
	EXPECT_FALSE(v1 == v2);
}

TEST(Vector, can_create_vector_with_zero_size)
{
	ASSERT_NO_THROW(Vector<int> v(0));
}

TEST(Vector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, can_create_copied_vector)
{
	Vector<int> v1(10);

	ASSERT_NO_THROW(Vector<int> v2(v1));
}

TEST(Vector, copied_vector_is_equal_to_source_one)
{
	Vector <int> v1(10);
	Vector <int> v2(v1);

	EXPECT_EQ(v1, v2);
}

TEST(Vector, copied_vector_has_its_own_memory)
{
	Vector <int> v1(10);
	v1[0] = 10;
	Vector <int> v2(v1);
	v2[0] = 20;

	EXPECT_NE(v1, v2);
}

TEST(Vector, can_set_and_get_element)
{
	Vector<int> v(10);
	v[0] = 10;

	EXPECT_EQ(10, v[0]);
}

TEST(Vector, throws_when_set_element_with_negative_index)
{
	Vector <int> v(10);

	ASSERT_ANY_THROW(v[-1]);
}

TEST(Vector, throws_when_set_element_with_too_large_index)
{
	Vector <int> v(10);

	ASSERT_ANY_THROW(v[10]);
}

TEST(Vector, can_assign_vector_to_itself)
{
	Vector <int> v1(10), v2(v1);
	v1 = v1;

	EXPECT_EQ(v1, v2);
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
	Vector <int> v1(10), v2(10);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(Vector, can_assign_vectors_of_different_size)
{
	Vector <int> v1(10), v2(20);
	v1 = v2;

	EXPECT_EQ(v1, v2);
}

TEST(Vector, compare_equal_vectors_return_true)
{
	Vector <int> v1(10), v2(10);
	v1[0] = 10;
	v2 = v1;

	EXPECT_TRUE(v1 == v2);
}

TEST(Vector, compare_vector_with_itself_return_true)
{
	Vector <int> v(10);
	v[0] = 10;

	EXPECT_TRUE(v == v);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
	Vector <int> v1(10), v2(20);

	EXPECT_FALSE(v1 == v2);
}

TEST(Vector, can_check_if_vector_is_empty)
{
	Vector<int> v;

	EXPECT_TRUE(v.empty());
}

TEST(Vector, can_push_back)
{
	Vector<int> v;

	ASSERT_NO_THROW(v.push_back(1));
}

TEST(Vector, can_pop_back)
{
	Vector<int> v;
	v.push_back(1);

	ASSERT_NO_THROW(v.pop_back());
}

TEST(Vector, throws_when_pop_back_from_empty_vector)
{
	Vector<int> v;
	ASSERT_ANY_THROW(v.pop_back());
}

TEST(Vector, can_push_front)
{
	Vector<int> v;

	ASSERT_NO_THROW(v.push_front(1));
}

TEST(Vector, can_pop_front)
{
	Vector<int> v;
	v.push_back(1);

	ASSERT_NO_THROW(v.pop_front());
}

TEST(Vector, throws_when_pop_front_from_empty_vector)
{
	Vector<int> v;

	ASSERT_ANY_THROW(v.pop_front());
}

TEST(Vector, can_get_size)
{
	Vector<int> v(5);

	EXPECT_EQ(5, v.size());
}

TEST(Vector, assign_operator_changes_vector_size)
{
	Vector <int> v1(10), v2(20);
	v1 = v2;

	EXPECT_EQ(v1.size(), v2.size());
}

TEST(Vector, can_resize_vector)
{
	Vector<int> v(5);
	v.resize();

	EXPECT_EQ(10, v.size());
}

TEST(Vector, can_resize_vector_with_argument)
{
	Vector<int> v(5);
	v.resize(11);

	EXPECT_EQ(11, v.size());
}