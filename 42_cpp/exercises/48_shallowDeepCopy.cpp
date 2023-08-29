#include <iostream>

/* cpp'de oop ile uğraşırken genelde obje ve sınıfları kopyalarsın. bunun da shallow ve deep
olmak üzere iki farklı yolu, daha doğrusu seviyesi vardır */

/* A shallow copy creates a new object that is a copy of the original object,
but it does not duplicate the data itself. Instead, it copies references or pointers to the data.
This means that changes made to the data in the copied object will also affect
the original object, and vice versa. */

/* A deep copy creates a new object and duplicates both the structure
and the data of the original object. This means that the copied object
is entirely independent of the original one, and changes made to the
copied object won't affect the original object, and vice versa. */

