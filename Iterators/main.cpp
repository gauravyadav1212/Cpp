#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> umap = {
        {1, "apple"},
        {2, "banana"},
        {3, "cherry"},
        {4, "date"},
        {5, "elderberry"}
    };

    cout << "Iterating through unordered_map:\n\n";

    for (auto it = umap.begin(); it != umap.end(); ++it) {
        cout << "Key: " << it->first 
             << ", Value: " << it->second << '\n';
        
        cout << "Address of iterator object itself (&it): " << &it << '\n';
        cout << "Address of element iterator points to (it): " << &(*it) << "\n\n";
    }

    return 0;
}
