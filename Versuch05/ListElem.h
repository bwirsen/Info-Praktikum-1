/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

class ListElem
{
private:
	Student data;
    ListElem* next;
    ListElem* prev; //prev-Pointer

public:
    ListElem(const Student& pData, ListElem* const pNext, ListElem* const pPrev);

    void setData(const Student& pData);
    void setNext(ListElem* const pNext);
    void setPrev(ListElem* const pPrev); //Added member declaration for prev-Pointer

    Student getData() const;
    ListElem* getNext() const;
    ListElem* getPrev() const; //Added member declaration for prev-uses
};

#endif
