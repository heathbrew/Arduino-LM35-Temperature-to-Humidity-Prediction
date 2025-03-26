#pragma once

/**
 * Compute dot product
 */
float dot(float *x, float coef) {
    float dot = 0.0;
    dot += x[0] * coef;
    return dot;
}

/**
 * Predict class for features vector
 */
float predict(float *x) {
    return dot(x, -20.175906760464) + 1031.3153005609454;
}
