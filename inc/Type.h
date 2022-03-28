#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
    private:
        int id;
        std::string Name;
        int ParentId;
        
    public:
        Type(int _id, std::string _Name, int _ParentId);
};

#endif