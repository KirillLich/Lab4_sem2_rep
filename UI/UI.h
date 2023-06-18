#ifndef UI
#define UI
#include "../test.h"
#include "../tree/tree.h"

#include <iostream>

namespace UINamespace
{
	int double_num_int(int x)
	{
		return x * 2;
	}

	int div_2_num_int(int x)
	{
		return x / 2;
	}

	int all_negative_num_int(int x)
	{
		return (-1) * x;
	}

	float double_num_float(float x)
	{
		return x * 2.0;
	}

	float div_2_num_float(float x)
	{
		return x / 2.0;
	}

	float all_negative_num_float(float x)
	{
		return (-1.0) * x;
	}

	float sqroot_float(float x)
	{
		return sqrt(x);
	}


}

class UserInterface
{
	int action;
	int take()
	{
		char* t = new char;
		std::cin >> (*t);
		int T = 0;
		T = atoi(t);
		if (T == 0)
		{
			delete t;
			std::cout << "You need to use number from 1 to 9\n";
			T = take();
		}
		return T;
	}
	void printDialogMenu(const std::string dialogActions[], int n)
	{
		for (size_t i = 0; i < n; i++)
		{
			std::cout << dialogActions[i] << std::endl;
		}
	}
	void printArrayInt(ArraySequence<int>* arr)
	{
		for (size_t i = 0; i < arr->GetLenght(); i++)
		{
			std::cout << arr->Get(i) << " ";
		}
		std::cout << std::endl;
	}
	void printArrayFloat(ArraySequence<float>* arr)
	{
		for (size_t i = 0; i < arr->GetLenght(); i++)
		{
			std::cout << arr->Get(i) << " ";
		}
		std::cout << std::endl;
	}
	void printArrayString(ArraySequence<std::string>* arr)
	{
		for (size_t i = 0; i < arr->GetLenght(); i++)
		{
			std::cout << arr->Get(i) << " ";
		}
		std::cout << std::endl;
	}

	tree<int>* makeBaseIntTree()
	{
		tree<int>* out = new tree<int>(10);
		out->insert(5);
		out->insert(2);
		out->insert(12);
		return out;
	}
	void useIntTree()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new tree", "3. Search element", "4. Insert element", "5. Map", "6. Detour", "7. Merge"};
		tree<int>* myTree = makeBaseIntTree();
		bool exit = false;
		int item;
		tree<int>* secondTree = NULL,* mergeTree = NULL;
		ArraySequence<int>* detour = NULL;

		while (!exit)
		{
			std::cout << "\n";
			printDialogMenu(dialogActions, 7);
			std::cout << "Started tree (KLP): ";
			detour = myTree->KLP();
			printArrayInt(detour);
			delete detour;
			detour = NULL;

			switch (take())
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete myTree;
				std::cout << "\nSet root item: ";
				std::cin >> item;
				myTree = new tree<int>(item);
				break;
			case 3:
				std::cout << "\nSet item to search: ";
				std::cin >> item;
				if (myTree->search(item))
					std::cout << "\nTree contain this item\n";
				else
					std::cout << "\nTree doesnt contain this item\n";
				break;
			case 5:
				std::cout << "\nChoose function: \n\t1. y = x*2\n\t2. y = x/2\n\t3. y = -x\n";
				switch (take())
				{
				case 1:
					secondTree = myTree->map(UINamespace::double_num_int);
					break;
				case 2:
					secondTree = myTree->map(UINamespace::div_2_num_int);
					break;
				case 3:
					secondTree = myTree->map(UINamespace::all_negative_num_int);
					break;
				default:
					break;
				}
				if (secondTree != NULL)
				{
					delete myTree;
					myTree = secondTree;
					secondTree = NULL;
				}
				break;
			case 4:
				std::cout << "\nSet item: ";
				std::cin >> item;
				myTree->insert(item);
				break;
			case 6:
				std::cout << "\nChoose detour:\n\t1.KPL\n\t2.LKP\n\t3.LPK\n\t4.PKL\n\t5.PLK\n\tDefault.KLP\n";
				switch (take())
				{
				case 1:
					detour = myTree->KPL();
					break;
				case 2:
					detour = myTree->LKP();
					break;
				case 3:
					detour = myTree->LPK();
					break;
				case 4:
					detour = myTree->PKL();
					break;
				case 5:
					detour = myTree->PLK();
					break;
				default:
					break;
				}
				if (detour != NULL)
					printArrayInt(detour);
				break;
			case 7:
				secondTree = makeBaseIntTree();
				while (!exit)
				{
					std::cout << "\n";
					printDialogMenu(dialogActions, 4);
					std::cout << "Started tree (KLP): ";
					detour = secondTree->KLP();
					printArrayInt(detour);
					delete detour;
					detour = NULL;

					switch (take())
					{
					case 1:
						exit = true;
						break;
					case 2:
						delete secondTree;
						std::cout << "\nSet root item: ";
						std::cin >> item;
						secondTree = new tree<int>(item);
						break;
					case 3:
						std::cout << "\nSet item to search: ";
						std::cin >> item;
						if (secondTree->search(item))
							std::cout << "\nTree contain this item\n";
						else
							std::cout << "\nTree doesnt contain this item\n";
						break;
					case 4:
						std::cout << "\nSet item: ";
						std::cin >> item;
						secondTree->insert(item);
						break;
					default:
						break;
					}
				}
				exit = false;
				mergeTree = myTree->merge(secondTree);
				delete myTree;
				delete secondTree;
				myTree = mergeTree;
				secondTree = NULL;
				mergeTree = NULL;
				break;
			default:
				break;
			}
		}
		delete myTree;
	}

	tree<float>* makeBaseFloatTree()
	{
		tree<float>* out = new tree<float>(1);
		out->insert(0.5);
		out->insert(0.2);
		out->insert(1.2);
		return out;
	}
	void useFloatTree()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new tree", "3. Search element", "4. Insert element", "5. Map", "6. Detour", "7. Merge" };
		tree<float>* myTree = makeBaseFloatTree();
		bool exit = false;
		int item;
		tree<float>* secondTree = NULL, * mergeTree = NULL;
		ArraySequence<float>* detour = NULL;

		while (!exit)
		{
			std::cout << "\n";
			printDialogMenu(dialogActions, 6);
			std::cout << "Started tree (KLP): ";
			detour = myTree->KLP();
			printArrayFloat(detour);
			delete detour;
			detour = NULL;

			switch (take())
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete myTree;
				std::cout << "\nSet root item: ";
				std::cin >> item;
				myTree = new tree<float>(item);
				break;
			case 3:
				std::cout << "\nSet item to search: ";
				std::cin >> item;
				if (myTree->search(item))
					std::cout << "\nTree contain this item\n";
				else
					std::cout << "\nTree doesnt contain this item\n";
				break;
			case 5:
				std::cout << "\nChoose function: \n\t1. y = x*2\n\t2. y = x/2\n\t3. y = -x\n\t4. y = sqrt(x)\n";
				switch (take())
				{
				case 1:
					secondTree = myTree->map(UINamespace::double_num_float);
					break;
				case 2:
					secondTree = myTree->map(UINamespace::div_2_num_float);
					break;
				case 3:
					secondTree = myTree->map(UINamespace::all_negative_num_float);
					break;
				case 4:
					secondTree = myTree->map(UINamespace::sqroot_float);
					break;
				default:
					break;
				}
				if (secondTree != NULL)
				{
					delete myTree;
					myTree = secondTree;
					secondTree = NULL;
				}
				break;
			case 4:
				std::cout << "\nSet item: ";
				std::cin >> item;
				myTree->insert(item);
				break;
			case 6:
				std::cout << "\nChoose detour:\n\t1.KPL\n\t2.LKP\n\t3.LPK\n\t4.PKL\n\t5.PLK\n\tDefault.KLP\n";
				switch (take())
				{
				case 1:
					detour = myTree->KPL();
					break;
				case 2:
					detour = myTree->LKP();
					break;
				case 3:
					detour = myTree->LPK();
					break;
				case 4:
					detour = myTree->PKL();
					break;
				case 5:
					detour = myTree->PLK();
					break;
				default:
					break;
				}
				if (detour != NULL)
					printArrayFloat(detour);
				break;
			case 7:
				secondTree = makeBaseFloatTree();
				while (!exit)
				{
					std::cout << "\n";
					printDialogMenu(dialogActions, 4);
					std::cout << "Started tree (KLP): ";
					detour = secondTree->KLP();
					printArrayFloat(detour);
					delete detour;
					detour = NULL;

					switch (take())
					{
					case 1:
						exit = true;
						break;
					case 2:
						delete secondTree;
						std::cout << "\nSet root item: ";
						std::cin >> item;
						secondTree = new tree<float>(item);
						break;
					case 3:
						std::cout << "\nSet item to search: ";
						std::cin >> item;
						if (secondTree->search(item))
							std::cout << "\nTree contain this item\n";
						else
							std::cout << "\nTree doesnt contain this item\n";
						break;
					case 4:
						std::cout << "\nSet item: ";
						std::cin >> item;
						secondTree->insert(item);
						break;
					default:
						break;
					}
				}
				exit = false;
				mergeTree = myTree->merge(secondTree);
				delete myTree;
				delete secondTree;
				myTree = mergeTree;
				secondTree = NULL;
				mergeTree = NULL;
				break;
			default:
				break;
			}
		}
		delete myTree;
	}

	void chooseStartAction(bool& exit)
	{
		const std::string dialogActions[] = { "1. Run tests", "2. Use int tree", "3. Use float tree", "4. Exit"};
		printDialogMenu(dialogActions, 4);
		switch (take())
		{
		case 1:
			runTests();
			break;
		case 2:
			useIntTree();
			break;
		case 3:
			useFloatTree();
			break;
		case 4:
			exit = true;
			break;
		default:
			std::cout << "Use number from 1 to 4\n";
			break;
		}
	} 

	void runTests()
	{
		tree_tester tester;
		if(tester.test_without_assert()) std::cout << "\n\tAll tests finished. No errors found.\n\n";
	}

public:
	UserInterface()
	{
		tree_tester tester;
		tester.test_with_assert();
		bool exit = false;
		while(!exit) chooseStartAction(exit);
	}
};

#endif