#include <bitset>
#include <iostream>
#include <ostream>
#include <vector>

class ECA {
    private:
        std::vector<bool> cells;
        int size;
        int rule;
        std::bitset<8> ruleset; 
        
    public:
        ECA(int rule, std::vector<bool> state, int size);
        void step();
        void print();
};

ECA::ECA(int rule, std::vector<bool> state, int size) {
    this->rule = rule;
    ruleset = rule;
    this->size = size;
    cells = state;
}

void ECA::step() {
    std::vector<bool> new_cells;
    for (int i = 0; i < cells.size(); i++) {
        
        int left = cells[(((i -1) % size)+size)%size];
        int right = cells[(((i +1) % size)+size)%size];
        int center = cells[i];
        
        int index = (left * 4 + center * 2 + right);
        new_cells.push_back(ruleset[index]);
    }
    cells = new_cells;
}

void ECA::print() {
    for (int i = 0; i < cells.size(); i++) {
        std::cout << cells[i];
    }
    std::cout << std::endl;
}

int main() {
    int rule, size;
    bool temp;
    std::cout << "ENTER THE RULE:\t";
    std::cin >> rule;
    std::cout <<"\nENTER THE SIZE:\t";
    std::cin >> size;
    std::cout << "\nENTER THE INITIAL STATE (Space seperated):\t";
    std::vector<bool> state(size, false);
    for(int i = 0; i < size; i++) {
        std::cin >> temp;
        state[i] = temp;
    }
    ECA eca(rule, state, size);
    std::cout << "\nSTARTING THE AUTOMATA" << std::endl;
    eca.print();
    for(int i = 0; i < 10; i++) {
        eca.step();
        eca.print();
    }
}