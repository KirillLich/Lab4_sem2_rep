#ifndef TEST_H
#define TEST_H

#include "tree/tree.h"
#include <assert.h>

int test_func_mult_2(int a)
{
	return a * 2;
}

class tree_tester
{
	int number_of_passed_tests = 0;
	const int number_of_tests = 4;

	void insert_and_search_test(bool assert_free)
	{
		tree<int> t(10);
		t.insert(2);
		t.insert(3);
		t.insert(11);

		if (!assert_free)
		{
			assert(t.search(10));
			assert(t.search(2));
			assert(t.search(3));
			assert(t.search(11));
		}
		else
		{
			if (!(
				t.search(10) &&
				t.search(2) &&
				t.search(3) &&
				t.search(11)
				))
			{
				std::cerr << "insert test failed\n";
				return;
			}
		}
		number_of_passed_tests++;
	}

	void delete_test(bool assert_free)
	{
		tree<int> t(10);
		t.insert(2);
		t.insert(3);
		t.insert(11);
		tree<int>* t2;
		t.delete_item(2, &t2);

		if (!assert_free)
		{
			assert(t2->search(10));
			assert(!t2->search(2));
			assert(t2->search(3));
			assert(t2->search(11));
		}
		else
		{
			if (!(
				t2->search(10) &&
				!t2->search(2) &&
				t2->search(3) &&
				t2->search(11)
				))
			{
				std::cerr << "delete test failed\n";
				return;
			}
		}
		delete t2;

		number_of_passed_tests++;
	}

	void map_test(bool assert_free)
	{
		tree<int> t(10);
		t.insert(2);
		t.insert(3);
		t.insert(11);

		tree<int>* t2 = t.map(test_func_mult_2);

		if (!assert_free)
		{
			assert(t2->search(20));
			assert(t2->search(4));
			assert(t2->search(6));
			assert(t2->search(22));
		}
		else
		{
			if (!(
				t2->search(20) &&
				t2->search(4) &&
				t2->search(6) &&
				t2->search(22)
				))
			{
				std::cerr << "map test failed\n";
				return;
			}
		}
		delete t2;

		number_of_passed_tests++;
	}

	void merge_test(bool assert_free)
	{
		tree<int> t(10);
		t.insert(2);
		t.insert(3);
		t.insert(11);

		tree<int> t2(8);
		t2.insert(25);
		t2.insert(18);
		t2.insert(-5);
		t2.insert(1);

		tree<int>* t_res = t.merge(&t2);

		if (!assert_free)
		{
			assert(t_res->search(10));
			assert(t_res->search(2));
			assert(t_res->search(-5));
			assert(t_res->search(1));
		}
		else
		{
			if (!(
				t_res->search(10) &&
				t_res->search(2) &&
				t_res->search(-5) &&
				t_res->search(1)
				))
			{
				std::cerr << "merge test failed\n";
				return;
			}
		}

		delete t_res;
		number_of_passed_tests++;
	}

	void start_tests(bool assert_free)
	{
		insert_and_search_test(assert_free);
		delete_test(assert_free);
		map_test(assert_free);
		merge_test(assert_free);
	}
public:
	void test_with_assert()
	{
		start_tests(false);
	}
	
	bool test_without_assert()
	{
		start_tests(true);
		return number_of_passed_tests == number_of_tests;

		std::cout << "Number of passed tests:" << number_of_passed_tests << std::endl;
	}
};

#endif