//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct State;
struct Word;
void calcProbability(struct Word *word, struct State *state);

int main(){
	ifstream file;
	file.open(


	return 0;

}


struct State{
	char *prevWord;
	char *currWord;
	char *nextWord;
};

struct Word{
	int totalWords;
	int thisWord;
	int probability;
	//struct State *wordState;
	char *theCurrentWord;
};

void calcProbability(struct Word *word, struct State *wordState){
	word->probability = word->thisWord/word->totalWords;
}
