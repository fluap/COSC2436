#ifndef PLAIN_BOX_
#define PLAIN_BOX_

typedef double ItemType; //Type definition of double to ItemType (they mean the same thing)

class PlainBox {
    private: 
        ItemType item; //double item

    public:
        PlainBox(); //Default constructor

        PlainBox(const ItemType& theItem); //Parameterized constructor

        void setItem(const ItemType& theItem); // TheItem is passed by reference and will be const.

        ItemType getItem() const; //Const method (will not modify, must be passed const argument)
}



#endif