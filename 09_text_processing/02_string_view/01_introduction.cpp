/*
 * A string view is a non-owning reference to a string. It represents a view of a sequence of characters.
 * This sequence of characters can be a C++ string or a C-string. A string view needs the header
 * <string_view>
 * From a bird-eye perspective the purpose of std::string_view is to avoid copying data that is slready 
 * owned by someone else and to allow immutable access to a std::string like object. The string view is a 
 * kind of a restricted string that supports only immutable operations. Additionally, a string view sv has
 * two additional mutating operations: sv.remove_prefix and sv.remove_suffix.
 *
 * Create and initialize
 * We can create an empty string view. We can also create a string view from an existing string, an existing
 * character-array, or an existing string view.
 *
 * Non-modifying operations
 *  Element access: operator[], at, front, back, data.
 *  Capacity: size, length, max_size, empty.
 *  Find: find, rfind, find_first_of, find_last_of, find_first_not_of, find_last_not_of.
 *  Copy: copy.
 *
 * Modifyng operations
 * The call stringView.swap(stringView2) swpas the content of the two string views. The methods 
 * remove_prefix and remove_suffix are unique to a string view because a string supports neither.
 * remove_prefix shrinks its start forward; remove_suffix shrinks its end backwards.
*/
#include <iostream>
#include <string>
#include <string_view>

int main(){
    std::string str{"   A lot of space"};
    std::string_view strView{str};
    strView.remove_prefix(std::min(strView.find_first_not_of(" "), strView.size()));
    
    std::cout << "str      :  " << str << std::endl 
              << "strView  : " << strView << std::endl;
                
    std::cout << std::endl;
    
    char arr[] = {'A', ' ', 'l', 'o', 't', ' ', 'o', 'f', ' ', 's', 'p', 'a', 'c', 'e', '\0',  '\0',  '\0'};
    std::string_view strView2(arr, sizeof(arr));
    auto trimPos = strView2.find('\0');
    
    if(trimPos != strView2.npos)
        strView2.remove_suffix(strView2.size() - trimPos);
    
    std::cout << "arr     : " << arr << ", size=" << sizeof arr << std::endl
              << "strView2: " << strView2 << ", size=" << strView2.size() << std::endl;



    return 0;
}
