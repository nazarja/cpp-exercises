#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename KeyType, typename ValueType> 
class Mapping
{
    public:
        KeyType key;
        ValueType value;
        
        Mapping(KeyType key, ValueType value) : key(key), value(value)
        {};
        
        string Print() const
        {
            ostringstream stream;
            stream << this->key << " : " << this->value;
            return stream.str();
        };
};

int main() 
{
    Mapping<string, int> mapping("age", 20);
    cout << mapping.Print() << endl;
}