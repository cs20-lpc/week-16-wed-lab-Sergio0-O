#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) : Graph(numV, 0, type) {
    // TODO

    // make the rows
    adjMatrix = new bool*[v];

    // make each row and fill with false
    for (int row = 0; row < v; row++) {
        adjMatrix[row] = new bool[v];

        for (int col = 0; col < v; col++) {
            adjMatrix[row][col] = false;
        }
    }
}

GraphMatrix::~GraphMatrix() {
    // TODO

    // delete each row first
    for (int row = 0; row < v; row++) {
        delete[] adjMatrix[row];
    }

    // delete the row pointers
    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    // TODO

    // check if vertices are valid
    if (i < 0 || i >= v || j < 0 || j >= v) {
        return false;
    }

    return adjMatrix[i][j];
}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    // TODO

    // check if vertices are valid
    if (i < 0 || i >= v || j < 0 || j >= v) {
        return;
    }

    bool addingEdge = !adjMatrix[i][j];

    adjMatrix[i][j] = addingEdge;

    // undirected graphs need both directions changed
    if (graphType == UNDIRECTED) {
        adjMatrix[j][i] = addingEdge;
    }

    if (addingEdge) {
        e++;
    }
    else {
        e--;
    }
}
