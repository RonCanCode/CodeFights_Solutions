// Ratiorg got statues of different sizes as a present from CodeMaster 
// for his birthday, each statue having an non-negative integer size. 
// Since he likes to make things perfect, he wants to arrange them from 
// smallest to largest so that each statue will be bigger than the previous 
// one exactly by 1. He may need some additional statues to be able to 
// accomplish that. Help him figure out the minimum number of additional 
// statues needed.
//
//Example
//
//For statues = [6, 2, 3, 8], the output should be
//makeArrayConsecutive2(statues) = 3.
//
//Ratiorg needs statues of sizes 4, 5 and 7.
//
// C++ Solution:

int makeArrayConsecutive2(std::vector<int> statues) {
    
    int largestNumber = -999;
    int smallestNumber = 999;
    
    for (int i = 0; i < statues.size(); i++) {
        if (statues[i] > largestNumber) {
            largestNumber = statues[i];
        }
        if (statues[i] < smallestNumber) {
            smallestNumber = statues[i];
        }
    }
    
    int numberNeeded = largestNumber - smallestNumber - statues.size() + 1;
    return numberNeeded;
    
}

