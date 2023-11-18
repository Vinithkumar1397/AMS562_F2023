#include "Matrix.hpp"
#include "Vector.hpp"
#include "PageRank.hpp"
#include <iostream>
#include <cassert>

// Test function for matrix normalization
void testMatrixNormalization() {
    Matrix<double> matrix = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    // Normalize columns
    matrix.normalizeColumns();

    // Add assertions to check normalization
    // For example, you can check if the sum of each column is 1
    for (std::size_t col = 0; col < matrix.getCols(); ++col) {
        double sum = 0.0;
        for (std::size_t row = 0; row < matrix.getRows(); ++row) {
            sum += matrix(row, col);
        }
        assert(std::abs(sum - 1.0) < 1e-6);
    }

    std::cout << "Matrix normalization test passed!" << std::endl;
}

// Test function for PageRank convergence
void testPageRankConvergence() {
    Matrix<double> linkMatrix = {
        {0, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    linkMatrix.normalizeColumns();

    // Compute PageRank with a low threshold for fast convergence
    Vector<double> ranks = pageRank(linkMatrix, 0.85, 1000, 1e-1);

    // Add assertions to check PageRank convergence
    // For example, you can check if the difference between consecutive ranks is below the threshold
    for (std::size_t iter = 1; iter < ranks.size(); ++iter) {
        assert(std::abs(ranks[iter] - ranks[iter - 1]) <= 1e-1);
    }

    std::cout << "PageRank convergence test passed!" << std::endl;
}

// Test function for initializing rank vector
void testRankVectorInitialization() {
    Matrix<double> linkMatrix = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    linkMatrix.normalizeColumns();

    // Initialize ranks with all entries equal to 1/numNodes
    Vector<double> ranks(linkMatrix.getRows(), 1.0 / linkMatrix.getRows());

    // Compute PageRank
    Vector<double> computedRanks = pageRank(linkMatrix);

    // Add assertions to check if the initialized rank vector matches the computed ranks
    for (std::size_t i = 0; i < ranks.size(); ++i) {
        assert(std::abs(ranks[i] - computedRanks[i]) < 1e-1);
    }

    std::cout << "Rank vector initialization test passed!" << std::endl;
}

// Test function for vector operations (dot product, vector addition, scalar multiplication)
void testVectorOperations() {
    Vector<double> vectorA = {1.0, 2.0, 3.0};
    Vector<double> vectorB = {4.0, 5.0, 6.0};

    // Test dot product
    double dotProductResult = vectorA.dotProduct(vectorB);
    assert(dotProductResult == 1.0 * 4.0 + 2.0 * 5.0 + 3.0 * 6.0);

    // Test vector addition
    Vector<double> additionResult = vectorA + vectorB;
    assert(additionResult[0] == 1.0 + 4.0);
    assert(additionResult[1] == 2.0 + 5.0);
    assert(additionResult[2] == 3.0 + 6.0);

    // Test scalar multiplication
    double scalar = 2.0;
    Vector<double> scalarMultiplicationResult = vectorA * scalar;
    assert(scalarMultiplicationResult[0] == 2.0 * 1.0);
    assert(scalarMultiplicationResult[1] == 2.0 * 2.0);
    assert(scalarMultiplicationResult[2] == 2.0 * 3.0);

    std::cout << "Vector operations test passed!" << std::endl;
}

// Test function for PageRank algorithm
void testPageRankscores() {
    Matrix<double> linkMatrix = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    linkMatrix.normalizeColumns();

    // Compute PageRank
    Vector<double> ranks = pageRank(linkMatrix);

    // Add assertions to check PageRank results
    // For example, you can check if the sum of PageRank scores is approximately 1
    assert(std::abs(ranks.sum() - 1.0) < 1e-6);

    std::cout << "PageRank test passed!" << std::endl;
}

int main() {
    // Define the small web structure as a link matrix
    Matrix<double> linkMatrix = {
        {0, 1, 1, 0, 0, 0}, // Page A
        {0, 0, 1, 1, 1, 0}, // Page B
        {1, 0, 0, 0, 0, 0}, // Page C
        {0, 1, 0, 0, 1, 0}, // Page D
        {0, 1, 0, 1, 0, 1}, // Page E
        {0, 0, 0, 0, 1, 0}  // Page F
    };

    // Normalize columns to make the link matrix stochastic
    linkMatrix.normalizeColumns();

    // Compute the PageRank
    Vector<double> ranks = pageRank(linkMatrix);

    // Output the PageRank scores
    for (std::size_t i = 0; i < ranks.size(); ++i) {
        std::cout << "PageRank of page " << static_cast<char>('A' + i) << " = " << ranks[i] << std::endl;
    }

    // Run your test functions
    testMatrixNormalization();
    testPageRankscores();
    testRankVectorInitialization();
    testPageRankConvergence();
    testVectorOperations();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
