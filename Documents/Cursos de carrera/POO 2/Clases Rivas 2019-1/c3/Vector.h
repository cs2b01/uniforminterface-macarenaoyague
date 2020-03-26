//
// Created by Macarena Oyague on 2019-04-01.
//

#ifndef C3_VECTOR_H
#define C3_VECTOR_H

namespace UTEC {
    class vector{
        int* _arr;
        int _size;
    public:
        vector();
        ~vector();
        void push_back(const int &value);
        void pop_back();
        void insert(int pos, const int &value);
        int get_item(int i);
        int size();
    };
}
#endif //C3_VECTOR_H

