//Written by Steve Nwachukwu and Nick Larkin
#include "tools.hpp"

class Cell {
private:
    int upp;
    Cell* next;
    Cell (int upp, Cell* next):upp(upp) {next = nullptr;};
    friend class CList;
    ~Cell() = default;
};
//---------------------
class CList {
private:
    int cellCount;
    Cell* head = nullptr;
    Cell* tail;
    Cell* currentCell;
public:
    CList();
    ~CList();
    int count () {return cellCount;};
    bool empty();
    ostream& print(ostream& CListOutput);
};
inline ostream& operator << (ostream&  output, CList& c) {return c.print(output);}
