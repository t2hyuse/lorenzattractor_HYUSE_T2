/**
 * @file lorenzattractor.hxx
 * @brief Main header for lorenzattractor
 * @author Hyuse & T2
 */

#pragma once
#include <iostream>
#include <vector>


/**
 * @brief The evolution functions for our dynamic
 * 
 * @return * void 
 */

void updateposition();
void updatevelocity();
void step();

/**
 * @brief Example class for lorenzattractor
 * @details the position and the velocity in a class, std::vector<double> as data structure
 */

class LorenzAttractor {
public:
    double x, y, z;      
    double sigma, beta, rho, dt;

    LorenzAttractor(double x0, double y0, double z0,
                    double sigma, double beta, double rho, double dt)
        : x(x0), y(y0), z(z0),
          sigma(sigma), beta(beta), rho(rho), dt(dt) {}

    void step() {
        double dx = sigma * (y - x);
        double dy = x * (rho - z) - y;
        double dz = x * y - beta * z;

        x += dx * dt;
        y += dy * dt;
        z += dz * dt;
    }
};

