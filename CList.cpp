//Written by Steve Nwachukwu and Nick Larkin
#include "CList.hpp"

CList::~CList()  {
    currentCell = head;
    Cell* temp = currentCell -> next;
    for (int i = 0; i < cellCount; i++) {
        delete currentCell;
        currentCell = temp;
        temp = temp -> next;
    }
};

bool CList::empty() {
    if (cellCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

ostream& CList::print(ostream& CListOutput) {
    Cell* temp;
    for (int i = 0; i < cellCount; i++) {
        currentCell = temp;
        temp = temp -> next;
        CListOutput << currentCell->upp;
    }
}
