#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.9/LAB_12.9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Arrange
			BinaryTree bst;

			// Вставка елементів у бінарне дерево пошуку з визначенням порядку обходу
			bst.insert(50, 'A');
			bst.insert(30, 'B');
			bst.insert(20, 'C');
			bst.insert(40, 'D');
			bst.insert(70, 'E');
			bst.insert(60, 'F');
			bst.insert(80, 'G');

			// Видалення елемента зі значенням 30
			bst.deleteNode(30);

			// Act
			int lastMinValue = bst.findMinValuePostfix();

			// Assert
			Assert::AreEqual(40, lastMinValue); // Перевірка, чи знайдено останній елемент бінарного дерева з мінімальним значенням
		}
	};
}
