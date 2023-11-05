#include <iostream>
#include <vector>

using namespace std;
struct Element {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int numRows;
    int numCols;
    vector<Element> elements;

public:
    SparseMatrix(int rows, int cols) {
        numRows = rows;
        numCols = cols;
    }

        void addElement(int row, int col, int value) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            cerr << "Invalid row or column index." << endl;
            return;
        }

        Element element;
        element.row = row;
        element.col = col;
        element.value = value;

        elements.push_back(element);
    }

        void printMatrix() {
        int currentElement = 0;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (currentElement < elements.size() && elements[currentElement].row == i && elements[currentElement].col == j) {
                    cout << elements[currentElement].value << " ";
                    currentElement++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
        SparseMatrix sparseMatrix(4, 5);

        sparseMatrix.addElement(0, 2, 30);
    sparseMatrix.addElement(0, 3, 4);
    sparseMatrix.addElement(1, 2, 570);
    sparseMatrix.addElement(2, 1, 26);

        sparseMatrix.printMatrix();

    return 0;
}
