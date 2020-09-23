// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "matrix_multiplication_Matrix.h"
#include <iostream>

// Output of .dll files: D:\00_fhnw\repo_prcpp\vs_projekte\testat01\PRCPP\x64

using namespace std;

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

void multiply(double* pa, double* pb, double* pr,
    jint aRows, jint aCols, jint bCols) {
    for (size_t r = 0; r < aRows; r++) {
        for (size_t c = 0; c < bCols; c++) {
            for (size_t k = 0; k < aCols; k++) {
                *(pr + r * bCols + c) += *(pa + r * aCols + k) * *(pb + k * bCols + c);
            }
        }
    }
}


JNIEXPORT void JNICALL Java_matrix_1multiplication_Matrix_multiplyC(JNIEnv* env, jobject,
    jdoubleArray aValues, jdoubleArray bValues, jdoubleArray result,
    jint           aRows, jint           aCols, jint          bCols) {

    cout << "Entering C++ multiplication code." << endl;

    // 'env' allows access to the JVM, allows to call special JNI functions.
    // 'jobject' or 'jclass' represents the caller of the native method.
    double* pa = env->GetDoubleArrayElements(aValues, JNI_FALSE); // Pointer to aValues[0]
    double* pb = env->GetDoubleArrayElements(bValues, JNI_FALSE); // Pointer to bValues[0]
    double* pr = env->GetDoubleArrayElements(result,  JNI_FALSE);  // Pointer to result[0]

    multiply(pa, pb, pr, aRows, aCols, bCols);

    env->ReleaseDoubleArrayElements(aValues, pa, 0);
    env->ReleaseDoubleArrayElements(bValues, pb, 0);
    env->ReleaseDoubleArrayElements(result, pr, 0);

    cout << "C++ segement ended." << endl;
}


JNIEXPORT void JNICALL Java_matrix_1multiplication_Matrix_powerC(JNIEnv* env, jobject o,
    jdoubleArray vals, jdoubleArray originalMatrix, jint aRows, jint aCols, jint i) {
    
    cout << "Entering powerC function" << endl;
    cout << "Provided exponent i = " << i << endl;
    
    // Get input array and result array to write values to.
    double* pa = env->GetDoubleArrayElements(vals, JNI_FALSE);
    double* po = env->GetDoubleArrayElements(originalMatrix, JNI_FALSE);

    // Keeping the result of the k-th multiplication.
    double* tmp = new double[aRows * aCols];

    for (int k = 1; k < i; k++) {
        multiply(po, pa, tmp, aRows, aCols, aCols);
        memcpy(tmp, pa, aCols * aRows);
    }


    for (int i = 0; i < aRows * aCols; i++) {
        cout << "tmp[i]: " << tmp[i] << endl;
    }

    env->ReleaseDoubleArrayElements(vals, pa, 0);
    env->ReleaseDoubleArrayElements(originalMatrix, po, 0);

    delete[] tmp;
}