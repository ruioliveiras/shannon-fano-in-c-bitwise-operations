/*
 * Developer : Rui Oliveira (rui96pedro@hotmail.com)
 * Date : 05/01/2014
 * You can use this for your own purpose
 */




#ifndef SHAN_TABLE_H
#define SHAN_TABLE_H
#define TABLE_K 1
#define TABLE_SPECIAL_CHAR 1 
#define TABLE_DATA_SIZE (1<<(8*TABLE_K))
#define TABLE_SIZE (TABLE_DATA_SIZE  + TABLE_SPECIAL_CHAR)
#define TABLE_MAX_DATA (TABLE_DATA_SIZE -1)
#define TABLE_SPECIAL_EOF (TABLE_SIZE - 1)

#define BUFFER_SIZE 4096 //Buffer Size need to be even
#include<vector>
#include"shan_row.class.h"



class Frequency
{
	public:
		unsigned long freq;
		int  index;
};

class ShanGraph
{
	public:
		int zero;
		int one;
		int value;
};


/**
	ShanRow is one binary code of the shannon Fano Table.
	This Can have variable number of binary digits
*/
class ShanTable
{
	private:
		unsigned long mTotalFreq; // Total of all entrys;
		ShanRow* mShanTable;
		ShanGraph* mShanGraph;	
		Frequency* mFreq; 
		
		void sort();
		/**
			Used at createShanTable, for recursive purposes 
			@argument int startIndex started index
			@argument int stopIndex index of next unused size, don't check this position
			@argument int freqSize total sum of all frequencies in this interval*/
		void shanTableAux(int startIndex,int stopIndex,unsigned long freqSize,int grapthWrite, int* graphFreeIndex);
		void printGraph(int index,int layer);
	public:
		ShanTable();
		Frequency getFrequency(int i);
		void setFrequency(int index,Frequency value);
		void addFrequency(int index);
		int size(); // TABLE_SIZE value
		unsigned long tFreq(); //mTotalFreq
		void createShanTable();
		ShanRow getRow(unsigned int index); // get mShanTable[mFreq[index].index]
		/** Used to decoude bits to is orignal char.
			@argument char a are bit 0 or 1
			@argument int bitIndex are the actual bit index
			@argument unsigned int *index if bool are return false - state of function;
						if return true - Char*/	
		bool getCharByBitsGraph(char a,int bitIndex,unsigned int *index);
		/**	Same as getCharByBitsGraph, but use the table instead the Grapth
			*/
		bool getCharByBitsTable(char a,int bitIndex,unsigned int *index);
		/** Just Used to Debug purposes
			*/		
		void printTable();
		
};

#endif
