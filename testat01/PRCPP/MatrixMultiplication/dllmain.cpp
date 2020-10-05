// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "matrix_multiplication_Matrix.h"
#include <iostream>

// Output of .dll files: D:\00_fhnw\repo_prcpp\vs_projekte\testat01\PRCPP\x64


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}



void multiply(jdouble* pa, jdouble* pb, jdouble* pr,
    jint aRows, jint aCols, jint bCols) {
    for (size_t r = 0; r < aRows; r++) {
        int rowSkipperA = r * aCols;
        int rowSkipperB = r * bCols;
        for (size_t c = 0; c < bCols; c++) {
            // Resetting the sum for every [i][j].
            jdouble tmpSum = 0.0;
            for (size_t k = 0; k < aCols; k++) {
                tmpSum += *(pa + rowSkipperA + k) * *(pb + k * bCols + c);
            }
            *(pr + rowSkipperB + c) = tmpSum;
        }
    }
}


JNIEXPORT void JNICALL Java_matrix_1multiplication_Matrix_multiplyC(JNIEnv* env, jobject,
    jdoubleArray aValues, jdoubleArray bValues, jdoubleArray result,
    jint           aRows, jint           aCols, jint          bCols) {

    std::cout << "Entering C++ multiplication code." << std::endl;

    // https://docs.oracle.com/en/java/javase/15/docs/specs/jni/functions.html#array-operations
    jboolean isCopyA;
    jboolean isCopyB;
    jboolean isCopyResult;
    jsize sizeResult = env->GetArrayLength(result);

    // 'env' allows access to the JVM, allows to call special JNI functions.
    // 'jobject' or 'jclass' represents the caller of the native method.
    double* pa = env->GetDoubleArrayElements(aValues, &isCopyA); // Pointer to aValues[0]
    double* pb = env->GetDoubleArrayElements(bValues, &isCopyB); // Pointer to bValues[0]
    double* pr = env->GetDoubleArrayElements(result,  &isCopyResult);  // Pointer to result[0]

    multiply(pa, pb, pr, aRows, aCols, bCols);

    // if (isCopyResult == JNI_TRUE) { env->ReleaseDoubleArrayElements(result, pr, 0);  }
    env->ReleaseDoubleArrayElements(result, pr, 0);
}





JNIEXPORT void JNICALL Java_matrix_1multiplication_Matrix_powerC(JNIEnv* env, jobject o,
    jdoubleArray inp, jdoubleArray resultMatrix, jint aRows, jint i) {

    std::cout << "Entering powerC function, provided exponent i = " << i << std::endl;

    jboolean isCopyInp;     // Are not null.
    jboolean isCopyResult;

    jsize result_length = env->GetArrayLength(inp);

    // Get input array and result array to write values to.
    jdouble* pa = env->GetDoubleArrayElements(inp, &isCopyInp);
    jdouble* pr = env->GetDoubleArrayElements(resultMatrix, &isCopyResult);

    jdouble* aggregation = new jdouble[result_length];

    // Copy the arrays into native code.
    int k = 0;
    for (double* pi = pa; pi != pa + result_length; pi++) {
        aggregation[k] = *pi;
        k++;
    }

    // k starts with 1 because for POWER=2 only one multiplication is needed.
    for (int POWER = 1; POWER < i; POWER++) {
        std::cout << "POWER = " << POWER << std::endl;
        // multiply(pa, aggregation, pr, aRows, aRows, aRows);
        multiply(aggregation, pa, pr, aRows, aRows, aRows);
        std::swap(aggregation, pr);
    }

    std::swap(aggregation, pr); 

    if (i % 2 != 0) {
        std::swap(aggregation, pr);
        for (int s = 0; s < result_length; s++) {
            *(pr + s) = *(aggregation + s);
        }
    }
    
    /*
    for (int s = 0; s < result_length; s++) {
        std::cout << "  *(pr+" << s << ") = " << *(pr + s) << ", *(aggr+" << s << ") = " << *(aggregation + s) << std::endl;
    }
    */
    
    env->ReleaseDoubleArrayElements(resultMatrix, pr, 0);
    delete[] aggregation;
}








JNIEXPORT void JNICALL Java_matrix_1multiplication_Matrix_iterateArrayC
    (JNIEnv* env, jobject o, jdoubleArray inp) {

    double* pi      = env->GetDoubleArrayElements(inp, JNI_FALSE);
    int lengthInput = env->GetArrayLength(inp);
    double* end     = pi + lengthInput;

    for (double* i = pi; i != end; i++) {
        std::cout << "From C++: " << *i << std::endl;
    }

    env->ReleaseDoubleArrayElements(inp, pi, 0);
}
