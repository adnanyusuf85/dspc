#include <stdio.h>
#include <stdlib.h>

float* convolve(float *input, float *system, int lengthOfInput, int lengthOfSystem, int *lengthOfOutput);

void main(void){

        float input[] = {0.0,0.1,0.2,0.3};
        float system[] = {1.0, -1.0};

        int lengthOfInput = sizeof(input) / sizeof(float);

        int lengthOfSystem = sizeof(system) / sizeof(float);

        int lengthOfOutput;

        float *output = convolve(input, system, lengthOfInput, lengthOfSystem, &lengthOfOutput);

        for (int k = 0; k < lengthOfOutput; k++){
                printf("%+7.8f\n", output[k]);
        }

}


float* convolve(float *input, float *system, int lengthOfInput, int lengthOfSystem, int *lengthOfOutput){

        *lengthOfOutput = lengthOfInput + lengthOfSystem - 1;

        float *output = (float*)calloc(*lengthOfOutput, sizeof(float));

        for (int i = 0; i < *lengthOfOutput; i++)
        {
                *(output+i) = 0.0;
        }

        for(int i = 0; i < *lengthOfOutput; i++){
                for (int j = i; j < i + lengthOfSystem; j++){
                        if (i > lengthOfInput - 1){
                                break;
                        }
                        output[j] += input[i] * system[j-i];
                }
        }

        return output;
}
