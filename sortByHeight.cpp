// Some people are standing in a row in a park. There are trees between 
// them which cannot be moved. Your task is to rearrange the people by 
// their heights in a non-descending order without moving the trees.
// 
// Example
// 
// For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
// sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].
// 
// C++ Solution:

std::vector<int> sortByHeight(std::vector<int> a) {

    // Store "non-tree" numbers in a new vector
    std::vector<int> storage;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != -1) {
            storage.push_back(a[i]);
        }
    }
    
    // Sort the new vector
    sort(storage.begin(), storage.end());
    int count = 0;
    
    // Replace "non-tree" values in original vector
    for (int j = 0; j < a.size(); j++) {
        if (a[j] != -1) {
            a[j] = storage[count];
            count++;
        }
    }
    
    return a;
}

