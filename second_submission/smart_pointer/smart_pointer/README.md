# Smart and dumb pointer

Using reference counting for the smart pointer.
The smart pointer takes ownership of a pointee! No need to delete the old pointee.

Prefert usage:

    SmartPointer<ObjType> sp (new ObjType());
    
Or:

    ObjType ot = new ObjType();
    SmartPointer<ObjType> sp = ot;

The smart pointer's destructor will be called and handle the deletion process.
Make sure that the pointee himself deletes in the correct way.
(Calls all delete necessary and in the right order, in the reverse order of construction.)

## TODO

Make sure that the smart pointer only takes ownership, when used like this:

    SmartPointer<ObjType> sp (new ObjType());
    
And not like this:

    SmartPointer<ObjType> sp (pointer to already instantiated obj);

## Notes

When you apply operator-> to a type that's not a built-in pointer, the compiler does an interesting thing. After looking up and applying the user-defined operator-> to that type, it applies operator-> again to the result. The compiler keeps doing this recursively until it reaches a pointer to a built-in type, and only then proceeds with member access. It follows that a smart pointer's operator-> does not have to return a pointer. It can return an object that in turn implements operator->, without changing the use syntax.


[Source](http://www.informit.com/articles/article.aspx?p=25264&seqNum=4)