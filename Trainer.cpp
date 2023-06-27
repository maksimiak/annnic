#include "Trainer.h"
#include <iostream>
#include <math.h>
#include <algorithm>


float Trainer::cost(float w1, float w2, float b) const
{
    int data_size = m_data.size();
    float result = 0.0f;
    for (int i = 0; i < data_size; ++i)
    {
        float x1 = m_data[i][0];
        float x2 = m_data[i][1];

        float y = sigmoidf(x1 * w1 + x2 * w2 + b);
        float d = y - m_data[i][2];

        result += d * d;
    }
    result /= data_size;
    return result;
}

void Trainer::set_data(DATA_TYPE data)
{
    m_data = data;
}
void Trainer::debug()
{
    std::cout << "=============================" << std::endl;
    std::cout << "Data sample" << std::endl;
    for (int i = 0; i < m_data.size(); ++i)
    {
        for (int j = 0; j < m_data[i].size(); ++j)
        {
            std::cout << m_data[i][j] << " "; 
        }
        std::cout << std::endl;
    }
    std::cout << "=============================" << std::endl;
}

float Trainer::sigmoidf(float x) const
{
    return 1.f / (1.f + expf(-x));
}
float Trainer::randf() const
{
    return (float) rand() / (float) RAND_MAX;
}
float Trainer::learn(int iterations, bool trace)
{
    /* start from random location */
    float w1 = randf();
    float w2 = randf();
    float b = randf();

    float eps = 1e-2;
    float rate = 1e-1;

    float c = 0.0f; 
    
    for (int i = 0; i < iterations; ++i)
    {
        c = cost(w1, w2, b);

        if (trace)
        {
            std::cout << "w1=" << w1 << " w2=" << w2 << " b=" << b << " cost=" << c << std::endl;
        }

        /* simulate derivative */
        float dw1 = (cost(w1 + eps, w2, b) - c) / eps;
        float dw2 = (cost(w1, w2  + eps, b) - c) / eps;
        float db = (cost(w1 + eps, w2, b + eps) - c) / eps;

        w1 -= rate * dw1;
        w2 -= rate * dw2;
        b -= rate * db;
    }

    // save model for predictions
    m_saved_state.push_back(w1);
    m_saved_state.push_back(w2);
    m_saved_state.push_back(b);
    
    return c;
}
bool Trainer::prediction()
{
    float w1 = m_saved_state[0];
    float w2 = m_saved_state[1];
    float b = m_saved_state[2];

    bool res = true;
    std::vector<int> compare;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            float value = i * w1 + j * w2 + b;
            std::cout << i << " | " << j << " = " << sigmoidf(value) << std::endl;
            compare.push_back(round(sigmoidf(value)));
        }
    }

    for (int i = 0; i < m_data.size(); ++i)
    {   
        if (compare[i] != m_data[i][2])
        {
            res = false;
        }
    }
    return res;
}