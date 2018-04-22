/**
 * @file List.cpp
 * content: linked list data structure
 */

#include "List.h"

List::List() :
		head(NULL), tail(NULL)
{
}

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student &pData)
{
	ListElem* new_element = new ListElem(pData, NULL, NULL);

	if (tail == NULL)                                       // list empty?
	{
		tail = new_element;

	}
	else
	{
		//ADDED LINE!
		head->setPrev(new_element);
		new_element->setNext(head);
	}

	head = new_element;

}
/**
 * @brief Enqueue an element at the end of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_tail(const Student &pData)
{
	ListElem* new_element = new ListElem(pData, NULL, NULL);

	if (tail == NULL)                                       // list empty?
	{
		tail = new_element;

	}
	else
	{

		tail->setNext(new_element);
		new_element->setPrev(tail);
	}

	tail = new_element;

}

/**
 * @brief Dequeue an element from the end of the list.
 *
 * This is the single linked version.
 *
 * @param pData The data will be stored here.
 * @return bool
 */
bool List::dequeue(Student& pData)
{
	ListElem* cursor = head;

	if (head == NULL)                                       // list empty?
	{
		return false;
	}
	else if (head == tail)                                  // only one element
	{
		pData = head->getData();
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		while (cursor->getNext() != tail)
		{
			cursor = cursor->getNext();
		}

		pData = tail->getData();
		tail = cursor;
		delete cursor->getNext();
		tail->setNext(NULL);
	}

	return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards() const
{
	ListElem* cursor = head;

	while (cursor != NULL)
	{
		cursor->getData().print();

		cursor = cursor->getNext();
	}
}

/**
 * @brief Print content from last to first element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_backwards() const
{
	ListElem* cursor = tail;

	while (cursor != NULL)
	{
		cursor->getData().print();

		cursor = cursor->getPrev();
	}
}
/**
 * @brief Checks if the wanted MatNr is forgiven
 *
 * @param MatNr
 * @return
 */
bool List::search_MatNr(const unsigned int MatNr) const
{
	ListElem* cursor = head;

	while (cursor != NULL)
	{
		if (MatNr == cursor->getData().getMatNr())
		{
			return true;
		}
		else
		{
			cursor = cursor->getNext();
		}

	}

	return false;
}
/**
 * @brief Function to delete any elements in the list by matnr
 * @param MatNr given "Matrikelnummer" of the searched person
 * @return true if matnr found and deleted
 */
bool List::deleteByMatNr(const unsigned int MatNr)
{
	ListElem* cursor = head;

	while (cursor != NULL)
	{
		if (MatNr == cursor->getData().getMatNr())
		{
			std::cout << "Matrikelnummer gefunden!" << std::endl;

			if (head == tail)                                // only one element
			{
				delete head;								//head, tail or cursor possible
				head = NULL;
				tail = NULL;

				return true;
			}

			else if (cursor == tail)
			{
				ListElem* cache = tail->getPrev();			//cache-pointer on element before tail
				cache->setNext(NULL);						//setting next in cache to NULL
				tail = cache;								//setting tail to the previous elemtent (cache)
				delete cursor;								//deleting the last element

				return true;

			}
			else if (cursor == head)						//analogical to cursor==tail
			{
				ListElem* cache = head->getNext();
				cache->setPrev(NULL);
				head = cache;
				delete cursor;

				return true;
			}

			else
			{
				ListElem* cache1 = cursor->getNext();		//2 new cache-pointer. 1 for next and 1 for prev
				ListElem* cache2 = cursor->getPrev();
				cache1->setPrev(cache2);					//connect both elements
				cache2->setNext(cache1);
				delete cursor;								//delete the start element

				return true;
			}
		}
		else
		{
			cursor = cursor->getNext();
		}
	}

	return false;
}
