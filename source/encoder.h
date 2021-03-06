/*
 * Developer : Rui Oliveira (rui96pedro@hotmail.com)
 * Date : 05/01/2014
 * You can use this for your own purpose
 */


#ifndef ENCODER_H
#define ENCODER_H
#include <fstream>
#include <string>
#include "struct/shan_table.class.h"

class Encoder
{
	private:
		ShanTable mShan;
		void writeOnBuffer(unsigned int a,char *outBuffer,int* blockIndex,int* bitSize);
		void writeTable();
	public:
		Encoder();
		void fileName(std::string fileName,std::string output);
		void startSample();
		void startSampleRLE();
		void startWriting();
		void startWritingRLE();
		void close();
		void printTable();
		
};


#endif
