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
        for (size_t c = 0; c < bCols; c++) {
            // Resetting the sum for every [i][j].
            jdouble tmpSum = 0.0;
            for (size_t k = 0; k < aCols; k++) {
                // tmpSum += *(pa + r * aCols + k) * *(pb + k * bCols + c);  // Works for RefTests
                tmpSum += *(pb + r * aCols + k) * *(pa + k * bCols + c); // Works for M93
            }
            *(pr + r * bCols + c) = tmpSum;
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

    env->SetDoubleArrayRegion(result, 0, sizeResult, pr);

    if (isCopyA == JNI_TRUE)      { env->ReleaseDoubleArrayElements(aValues, pa, 0); }
    if (isCopyB == JNI_TRUE)      { env->ReleaseDoubleArrayElements(bValues, pb, 0); }
    if (isCopyResult == JNI_TRUE) { env->ReleaseDoubleArrayElements(result, pr, 0);  }
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

    // Intermediate result accumulation array on heap
    jdouble* internal = new jdouble[result_length];
    for (int i = 0; i < result_length; i++) { internal[i] = pa[i]; }

    for (int k=0; k < i; k++) {
        multiply(pa, internal, pr, aRows, aRows, aRows);
        std::swap(internal, pr);
    }

    env->SetDoubleArrayRegion(resultMatrix, 0, result_length, pr);

    // If isCopyInp == JNI_TRUE -> then a copy is made.
    if (isCopyInp    == JNI_TRUE) { env->ReleaseDoubleArrayElements(inp, pa, 0);          }
    if (isCopyResult == JNI_TRUE) { env->ReleaseDoubleArrayElements(resultMatrix, pr, 0); }

    delete[] internal;
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
