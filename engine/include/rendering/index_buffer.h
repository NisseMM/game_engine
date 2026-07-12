#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <initializer_list>
#include <vector>

class IndexBuffer
{
public:
    IndexBuffer();
    IndexBuffer(std::initializer_list<unsigned int> list);
    ~IndexBuffer();
    
    void bind() const;
    void upload() const;

    void upload(std::initializer_list<unsigned int> list);
    void upload(std::vector<unsigned int> const& list);

    size_t count() const; 

private:
    unsigned int buffer_object_;
    size_t count_;
};







#endif //INDEX_BUFFER_H