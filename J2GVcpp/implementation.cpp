#include "jni_Framework.h"
#include "j2gvc.h"
#include <iostream>

void JNICALL Java_jni_Framework_renderGraph
(JNIEnv * env, jclass thisObject, jstring jDotCmds, jstring jEngine, jstring jFormat, jstring jFileName) {

	const char* strA = env->GetStringUTFChars(jDotCmds, nullptr);
	const char* strB = env->GetStringUTFChars(jEngine, nullptr);
	const char* strC = env->GetStringUTFChars(jFormat, nullptr);
	const char* strD = env->GetStringUTFChars(jFileName, nullptr);

	if (strA == nullptr || strB == nullptr || strC == nullptr || strD == nullptr) {
		std::cerr << "Error to get a string" << std::endl;
		return;
	}

	renderGraph(strA, strB, strC, strD);

	env->ReleaseStringUTFChars(jDotCmds, strA);
	env->ReleaseStringUTFChars(jEngine, strB);
	env->ReleaseStringUTFChars(jFormat, strC);
	env->ReleaseStringUTFChars(jFileName, strD);

}