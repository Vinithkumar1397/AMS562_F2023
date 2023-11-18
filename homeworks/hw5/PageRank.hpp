#ifndef PAGERANK_HPP
#define PAGERANK_HPP

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cmath>
#include <vector>

template <typename T>
Vector<T> pageRank(const Matrix<T>& linkMatrix, T dampingFactor = 0.85, std::size_t maxIterations = 100, T tol = 1e-6) {
    // Get the number of nodes in the link matrix
    std::size_t numNodes = linkMatrix.getRows();

    // Initialize the rank vector with equal values
    Vector<T> ranks(numNodes, 1.0 / numNodes);

    // Perform PageRank iteration
    for (std::size_t iter = 0; iter < maxIterations; ++iter) {
        // Create a new vector to store updated ranks
        Vector<T> newRanks(numNodes, (1.0 - dampingFactor) / numNodes);

        // Distribute rank from outgoing links
        for (std::size_t i = 0; i < numNodes; ++i) {
            for (std::size_t j = 0; j < numNodes; ++j) {
                if (linkMatrix(i, j) > 0) {
                    // Calculate the out-degree of the current node
                    std::size_t outDegree = 0;
                    for (std::size_t k = 0; k < numNodes; ++k) {
                        if (linkMatrix(i, k) > 0) outDegree++;
                    }

                    // Update ranks based on the PageRank algorithm formula
                    if (outDegree > 0) {
                        newRanks[j] += dampingFactor * (ranks[i] / outDegree);
                    }
                }
            }
        }

        // Check for convergence
        T diff = 0.0;
        for (std::size_t i = 0; i < numNodes; ++i) {
            diff += std::abs(newRanks[i] - ranks[i]);
        }

        // If the difference is below the tolerance, break the loop
        if (diff < tol) {
            break;
        }

        // Update the ranks with the new values
        ranks = newRanks;

        // Print intermediate ranks for debugging or monitoring
        std::cout << "Iteration " << iter << ": ";
        for (std::size_t i = 0; i < ranks.size(); ++i) {
            std::cout << ranks[i] << " ";
        }
        std::cout << std::endl;
    }

    // Return the final PageRank vector
    return ranks;
}

#endif // PAGERANK_HPP
