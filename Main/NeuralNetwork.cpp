#include "NeuralNetwork.h"

// Level implementation
Level::Level(int inputCount, int outputCount) {
    this->inputCount = inputCount;
    this->outputCount = outputCount;
    inputs = new int[inputCount];
    outputs = new int[outputCount];
    biases = new int[outputCount];
    weights = new int*[inputCount];
    for (int i = 0; i < inputCount; i++) {
        weights[i] = new int[outputCount];
    }
    randomize();
}

void Level::randomize() {
    // Implement randomization logic
}

void Level::feedForward(int* givenInputs) {
    // Implement feedforward logic
}

void Level::backpropagate(int* expectedOutputs, float learningRate) {
    // Implement backpropagation
}

int* Level::getOutputs() {
    return outputs;
}

void Level::updateWeights(int layerIndex, int neuronIndex, int weightIndex, int delta) {
    // Implement weight update logic
}

// NeuralNetwork implementation
NeuralNetwork::NeuralNetwork(int* neuronCounts, int numLevels) {
    this->numLevels = numLevels;
    levels = new Level*[numLevels];
    for (int i = 0; i < numLevels - 1; i++) {
        levels[i] = new Level(neuronCounts[i], neuronCounts[i + 1]);
    }
}

void NeuralNetwork::feedForward(int* givenInputs) {
    // Implement feedforward logic
}

void NeuralNetwork::backpropagate(int* expectedOutputs, float learningRate) {
    // Implement backpropagation
}

int* NeuralNetwork::getOutputs() {
    // Implement logic to get outputs from the last level
    return levels[numLevels - 1]->getOutputs();
}
