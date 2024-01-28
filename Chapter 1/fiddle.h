#ifndef PLAIN_BOX_
// Set the type of data stored in the box.
typedef double itemType;

class cPlainBox {
    private:
        //Data Field
        itemType item;

    public:
        //Default constructor
        cPlainBox();

        //Parameterize constructor
        cPlainBox(const itemType& theItem);

        //Method to change the value of the data field
        void setItem(const itemType& theItem);

        //Method to get the value of the data field
        itemType getItem() const; //Const is placed after. This is a promise that the function will not modify the value (const-correctiveness)
        
};
#endif // !PLAIN_BOX_