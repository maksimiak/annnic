#include "definitions.h"
#include <vector>

typedef std::vector<std::vector< float > > DATA_TYPE;

class Trainer
{
public:
    float cost(float w1, float w2, float b) const;
    void set_data(DATA_TYPE data);
    float learn(int iterations, bool trace = false);
    bool prediction();
    void debug();

private:
    float sigmoidf(float x) const;
    float randf() const;
    DATA_TYPE m_data;
    std::vector<float> m_saved_state;
};