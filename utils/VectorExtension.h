#pragma once

#include <vector>
#include <algorithm>

class VectorExtension{
public:
    template<typename T>
    inline void fast_erase_delete(std::vector<T*>& v, size_t index){
        if(!v.empty()){
            if(index <= v.size()-1){
                if(index != v.size()-1){
                    // Если это не последний элемент
                    // Меняем местами тот что нужно удалить и последний элемент
                    std::swap(v[index], v[v.size()-1]);
                    delete v[v.size()-1];
                    v.pop_back();
                }else{
                    // Индекс указывает на последний элемент - просто удалим его
                    delete v[v.size()-1];
                    v.pop_back();
                }
            }else{
                // Индекс больше чем размер вектора
                //throw std::out_of_range("index out of range");
            }
        }
    }
    
    template<typename T>
    static void fast_erase(std::vector<T>& v, size_t i){
        std::swap(v[i], v.back());
        v.pop_back(); 
    }
};