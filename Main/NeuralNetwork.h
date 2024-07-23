#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <Arduino.h>

class Level {
private:
    int inputCount;
    int outputCount;
    int* inputs;
    int* outputs;
    int* biases;
    int** weights;

    void randomize();

public:
    Level(int inputCount, int outputCount);
    void feedForward(int* givenInputs);
    void backpropagate(int* expectedOutputs, float learningRate);
    int* getOutputs();
    void updateWeights(int layerIndex, int neuronIndex, int weightIndex, int delta);
};

class NeuralNetwork {
private:
    Level** levels;
    int numLevels;

public:
    NeuralNetwork(int* neuronCounts, int numLevels);
    void feedForward(int* givenInputs);
    void backpropagate(int* expectedOutputs, float learningRate);
    int* getOutputs();
};

#endif
