/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student& pData, ListElem* const pNext, ListElem* const pPrev):
    data(pData), next(pNext), prev(pPrev)
{
}

void ListElem::setData(const Student& pData)
{
    data = pData;
}


void ListElem::setNext(ListElem* const pNext)
{
    next = pNext;
}

//added function for prev-Pointer
void ListElem::setPrev(ListElem* const pPrev)
{
	prev = pPrev;
}


Student ListElem::getData() const
{
    return data;
}


ListElem* ListElem::getNext() const
{
    return next;
}

ListElem* ListElem::getPrev() const
{
    return prev;
}
